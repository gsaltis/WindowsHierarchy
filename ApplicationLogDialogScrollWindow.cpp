/*****************************************************************************
 * FILE NAME    : ApplicationLogDialogScrollWindow.cpp
 * DATE         : November 01 2023
 * PROJECT      : 
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
#include "ApplicationLogDialogScrollWindow.h"

/*****************************************************************************!
 * Function : ApplicationLogDialogScrollWindow
 *****************************************************************************/
ApplicationLogDialogScrollWindow::ApplicationLogDialogScrollWindow
(ApplicationLog* InLog) : QScrollArea()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  log = InLog;
  initialize();
}

/*****************************************************************************!
 * Function : ~ApplicationLogDialogScrollWindow
 *****************************************************************************/
ApplicationLogDialogScrollWindow::~ApplicationLogDialogScrollWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ApplicationLogDialogScrollWindow::initialize()
{
  setFrameShadow(QFrame::Plain);
  setFrameShape(QFrame::Box);
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ApplicationLogDialogScrollWindow::CreateSubWindows()
{
  logWindow = new ApplicationLogDialogWindow(log);
  setWidget(logWindow);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ApplicationLogDialogScrollWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ApplicationLogDialogScrollWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  logWindow->resize(width, height);
  (void)height;
  (void)width;
}

/*****************************************************************************!
 * Function : ResizeEntryWindow
 *****************************************************************************/
void
ApplicationLogDialogScrollWindow::ResizeEntryWindow
()
{
  logWindow->ResizeWindow();
}

/*****************************************************************************!
 * Function : AddEntry
 *****************************************************************************/
void
ApplicationLogDialogScrollWindow::AddEntry
(ApplicationLogEntry* InEntry)
{
  logWindow->AddEntry(InEntry);
}
