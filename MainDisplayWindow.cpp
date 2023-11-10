/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : November 01 2023
 * PROJECT      : WindowsHierarchy
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include "trace_winnet.h"
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "ApplicationConfiguration.h"
#include "sqlite3.h"

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
(QString InFilename) : QWidget()
{
  QPalette				pal;

  filename = InFilename;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 160)));
  setPalette(pal);
  setAutoFillBackground(true);

  Initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainDisplayWindow::Initialize()
{
  elements = new WindowElementList();
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  int                                   n;
  
  hierarchyWindow = NULL;
  signalSlotWindow = NULL;
  n = sqlite3_open(filename.toStdString().c_str(), &windowsdb);
  if ( n != SQLITE_OK ) {
    ApplicationConfiguration::MainApplicationLog->AddEntry(QString("Could not open %1 : %2").
                                                           arg(filename).
                                                           arg(sqlite3_errstr(n)));
  }
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  ReadWindowElements();
  hierarchyWindow = new WindowHierarchy(elements);
  hierarchyWindow->setParent(this);
  hierarchyWindow->SetElements(elements);
  signalSlotWindow = new SignalSlotWindow();  
  signalSlotWindow->setParent(this);
  signalSlotWindow->hide();
  PopulateHierarchyWindow();
}

/*****************************************************************************!
 * Function : ReadWindowElements
 *****************************************************************************/
void
MainDisplayWindow::ReadWindowElements
()
{
  QString                               selectStatement;
  int                                   n;

  TRACE_FUNCTION_START();
  selectStatement = QString("SELECT * FROM Windows;");

  n = sqlite3_exec(windowsdb,
                   selectStatement.toStdString().c_str(),
                   ReadWindowElementsCB,
                   this,
                   NULL);
  if ( n != SQLITE_OK ) {
    ApplicationConfiguration::MainApplicationLog->AddEntry(QString("sqlite3_exec() %1 : %2").
                                                           arg(selectStatement).
                                                           arg(sqlite3_errstr(n)));
  }
  TRACE_FUNCTION_END();
}

/*****************************************************************************!
 * Function : ReadWindowElementsCB
 *****************************************************************************/
int
MainDisplayWindow::ReadWindowElementsCB
(void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames)
{
  int                                   n;
  QString                               columnName;
  QString                               columnValue;
  QString                               name;
  bool                                  transient;
  int                                   classID;
  int                                   elementID;
  int                                   parentID;
  MainDisplayWindow*                    window;
  WindowElement*                        element;
  sqlite3*                              windowdb;
  WindowElementList*                    elementList;
  
  classID       = 0;
  elementID     = 0;
  parentID      = 0;
  name          = QString();
  transient     = false;
  
  window = (MainDisplayWindow*)InPointer;
  elementList = window->GetElements();
  windowdb = window->GetWindowDB();
  
  for ( n = 0 ; n < InColumnCount ; n++ ) {
    columnName  = QString(InColumnNames[n]);
    columnValue = QString(InColumnValues[n]);

    if ( columnName == "classid" ) {
      classID = columnValue.toInt();
    } else if ( columnName == "elementid" ) {
      elementID = columnValue.toInt();
    } else if ( columnName == "parentid" ) {
      parentID = columnValue.toInt();
    } else if ( columnName == "name" ) {
      name = QString(columnValue);
    } else if ( columnName == "transient" ) {
      transient = columnValue.toInt() ? true : false;
    }
  }
  element = new WindowElement(classID, elementID, parentID, name, transient);
  elementList->AddElement(element);
  ReadElementSlots(element, windowdb);
  return 0;
}

/*****************************************************************************!
 * Function : ReadElementSlots
 *****************************************************************************/
void
MainDisplayWindow::ReadElementSlots
(WindowElement* InElement, sqlite3* InWindowsDB)
{
  QString                               sqlstmt;
  int                                   n;
  
  sqlstmt = QString("Select * from Slots where classid is %1 and elementid is %2").
    arg(InElement->GetClassID()).
    arg(InElement->GetElementID());
  
  n = sqlite3_exec(InWindowsDB,
                   sqlstmt.toStdString().c_str(),
                   ReadElementSlotsCB,
                   InElement,
                   NULL);
  if ( n != SQLITE_OK ) {
    ApplicationConfiguration::MainApplicationLog->AddEntry(QString("sqlite3_exec() %1 : %2").
                                                           arg(sqlstmt).
                                                           arg(sqlite3_errstr(n)));
  }
}

/*****************************************************************************!
 * Function : ReadElementSlotsCB
 *****************************************************************************/
int
MainDisplayWindow::ReadElementSlotsCB
(void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames)
{
  int                                   n;
  QString                               columnName;
  QString                               columnValue;
  int                                   classID;
  int                                   elementID;
  int                                   slotID;
  QString                               name;
  WindowElementSlot*                    elementSlot;
  WindowElement*                        element;

  element = (WindowElement*)InPointer;
  classID = 0;
  elementID = 0;
  slotID = 0;
  name = QString();
  
  for ( n = 0 ; n < InColumnCount ; n++ ) {
    columnName  = QString(InColumnNames[n]);
    columnValue = QString(InColumnValues[n]);


    if ( columnName == "classid" ) {
      classID = columnValue.toInt();
    } else if ( columnName == "elementid" ) {
      elementID = columnValue.toInt();
    } else if ( columnName == "slotid" ) {
      slotID = columnValue.toInt();
    } else if ( columnName == "name" ) {
      name = QString(columnValue);
    }
  }
  elementSlot = new WindowElementSlot(classID, elementID, slotID, name);
  element->AddWindowSlot(elementSlot);
  return 0;
}
/*****************************************************************************!
 * Function : PopulateHierarchyWindow
 *****************************************************************************/
void
MainDisplayWindow::PopulateHierarchyWindow
()
{
  WindowElement*                        element;
  int                                   n;
  int                                   i;
  
  TRACE_FUNCTION_START();
  n = elements->GetElementCount();
  TRACE_FUNCTION_INT(n);
  for ( i = 0 ; i < n ; i++ ) {
    element = elements->GetElementByIndex(i);
    hierarchyWindow->AddWindowElement(element);
  }
  TRACE_FUNCTION_END();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
  if ( hierarchyWindow ) {
    hierarchyWindow->move(2, 2);
    hierarchyWindow->resize(width - 4, height - 4);
  }
  if ( signalSlotWindow ) {
    signalSlotWindow->move(2, 2);
    signalSlotWindow->resize(width - 4, height - 4);
  }
}

/*****************************************************************************!
 * Function : SlotSelectHierarchyWindow
 *****************************************************************************/
void
MainDisplayWindow::SlotSelectHierarchyWindow
()
{
  hierarchyWindow->show();
  signalSlotWindow->hide();
}

/*****************************************************************************!
 * Function : SlotSelectSignalSlotWindow
 *****************************************************************************/
void
MainDisplayWindow::SlotSelectSignalSlotWindow
()
{
  hierarchyWindow->hide();
  signalSlotWindow->show();  
}

/*****************************************************************************!
 * Function : GetHierarchWindow
 *****************************************************************************/
WindowHierarchy*
MainDisplayWindow::GetHierarchWindow
()
{
  return hierarchyWindow;
}

/*****************************************************************************!
 * Function : GetWindowDB
 *****************************************************************************/
sqlite3*
MainDisplayWindow::GetWindowDB
()
{
  return windowsdb;
}

/*****************************************************************************!
 * Function : GetElements
 *****************************************************************************/
WindowElementList*
MainDisplayWindow::GetElements
()
{
  return elements;
}
