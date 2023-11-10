/*****************************************************************************
 * FILE NAME    : ApplicationLogDialogWindow.cpp
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
#include "ApplicationLogDialogWindow.h"

/*****************************************************************************!
 * Function : ApplicationLogDialogWindow
 *****************************************************************************/
ApplicationLogDialogWindow::ApplicationLogDialogWindow
(ApplicationLog* InLog) : QWidget()
{
  QPalette pal;
  log = InLog;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ApplicationLogDialogWindow
 *****************************************************************************/
ApplicationLogDialogWindow::~ApplicationLogDialogWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ApplicationLogDialogWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ApplicationLogDialogWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ApplicationLogDialogWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ApplicationLogDialogWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int                                   i;
  int                                   h;
  int                                   n;
  int                                   y;
  ApplicationLogDisplayWindowElement*   element;
  
  size = InEvent->size();
  width = size.width();

  y = 0;
  n = elements.size();
  for ( i = 0 ; i < n ; i++ ) {
    element = elements[i];
    h = element->size().height();
    element->move(0, y);
    element->resize(width, h);
    y += h;
  }
}

/*****************************************************************************!
 * Function : ResizeWindow
 *****************************************************************************/
void
ApplicationLogDialogWindow::ResizeWindow
()
{
  int                                   height;
  int                                   width;
  
  height = elements.count() * APPLICATION_LOG_DISPLAY_WINDOW_ELEMENT_HEIGHT;
  width = size().width();
  resize(width, height);
}

/*****************************************************************************!
 * Function : AddEntry
 *****************************************************************************/
void
ApplicationLogDialogWindow::AddEntry
(ApplicationLogEntry* InEntry)
{
  ApplicationLogDisplayWindowElement*   element;
  int                                   n;
  
  element = new ApplicationLogDisplayWindowElement(InEntry);
  elements << element;

  n = elements.size();
  n *= APPLICATION_LOG_DISPLAY_WINDOW_ELEMENT_HEIGHT;
  element->move(0, n);
  element->resize(size().height(), APPLICATION_LOG_DISPLAY_WINDOW_ELEMENT_HEIGHT);
  element->setParent(this);
}
