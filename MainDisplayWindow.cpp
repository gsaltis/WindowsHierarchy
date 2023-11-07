/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : November 01 2023
 * PROJECT      : WindowsHierarchy
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "ApplicationConfiguration.h"
#include "sqlite3.h"
#include "Trace.h"

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
  hierarchyWindow = new WindowHierarchy();
  hierarchyWindow->setParent(this);
  signalSlotWindow = new SignalSlotWindow();  
  signalSlotWindow->setParent(this);
  signalSlotWindow->hide();
  PopulateHierarchyWindow();
}

/*****************************************************************************!
 * Function : PopulateHierarchyWindow
 *****************************************************************************/
void
MainDisplayWindow::PopulateHierarchyWindow
()
{
  QString                               selectStatement;
  int                                   n;

  selectStatement = QString("SELECT * FROM Windows;");

  n = sqlite3_exec(windowsdb,
                   selectStatement.toStdString().c_str(),
                   PopulateHierarchyWindowCB,
                   this,
                   NULL);
  if ( n != SQLITE_OK ) {
    ApplicationConfiguration::MainApplicationLog->AddEntry(QString("sqlite3_exec() %1 : %2").
                                                           arg(selectStatement).
                                                           arg(sqlite3_errstr(n)));
  }
}

/*****************************************************************************!
 * Function : PopulateHierarchyWindowCB
 *****************************************************************************/
int
MainDisplayWindow::PopulateHierarchyWindowCB
(void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames)
{
  int                                   n;
  QString                               columnName;
  QString                               columnValue;
  QString                               name;
  QString                               className;
  int                                   level;
  bool                                  transient;
  int                                   classID;
  int                                   elementID;
  MainDisplayWindow*                    window;
  WindowHierarchy*                      hierarchyWindow;
  WindowElement*                        element;
  sqlite3*                              windowdb;
  
  className     = QString();
  classID       = 0;
  elementID     = 0;
  name          = QString();
  level         = 0;
  transient     = false;
  
  window = (MainDisplayWindow*)InPointer;
  hierarchyWindow = window->GetHierarchWindow();
  windowdb = window->GetWindowDB();
  
  for ( n = 0 ; n < InColumnCount ; n++ ) {
    columnName  = QString(InColumnNames[n]);
    columnValue = QString(InColumnValues[n]);

    if ( columnName == "classid" ) {
      classID = columnValue.toInt();
    } else if ( columnName == "elementid" ) {
      elementID = columnValue.toInt();
    } else if ( columnName == "name" ) {
      name = QString(columnValue);
    } else if ( columnName == "classname" ) {
      className = QString(columnValue);
    } else if ( columnName == "level" ) {
      level = columnValue.toInt();
    } else if ( columnName == "transient" ) {
      transient = columnValue.toInt() ? true : false;
    }
  }
  element = new WindowElement(classID, elementID, name, className, level, transient);
  ReadElementSlots(element, windowdb);
  hierarchyWindow->AddWindowElement(element);
  ApplicationConfiguration::WindowElements << element;
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
