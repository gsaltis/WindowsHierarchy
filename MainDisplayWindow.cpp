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
  hierarchyWindow = NULL;
  signalSlotWindow = NULL;
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
  WindowElement*                        windowElement;
  QFile                                 file(filename);
  QString                               fileContents;
  QStringList                           lines;
  int                                   i;
  int                                   n;
  QString                               line;
  
  if ( ! file.open(QIODevice::ReadOnly) ) {
    ApplicationConfiguration::StatusBar->showMessage(QString("Count not open %1").arg(filename), 10);
    return;
  }
  fileContents = QString(file.readAll());
  lines = fileContents.split("\n");

  n = lines.count();
  for ( i = 0 ; i < n ; i++ ) {
    line = lines[i].trimmed();
    if ( line.isEmpty() ) {
      continue;
    }
    windowElement = new WindowElement(line);
    hierarchyWindow->AddWindowElement(windowElement);
    ApplicationConfiguration::WindowElements << windowElement;
  }
  file.close();
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
