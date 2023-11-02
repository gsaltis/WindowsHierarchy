/*****************************************************************************
 * FILE NAME    : SignalSlotContainer.cpp
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
#include "SignalSlotContainer.h"
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Function : SignalSlotContainer
 *****************************************************************************/
SignalSlotContainer::SignalSlotContainer
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SignalSlotContainer
 *****************************************************************************/
SignalSlotContainer::~SignalSlotContainer
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SignalSlotContainer::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SignalSlotContainer::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SignalSlotContainer::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SignalSlotContainer::resizeEvent
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
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
SignalSlotContainer::paintEvent
(QPaintEvent* )
{
  QSize                                 size;
  WindowElement*                        element;
  QPainter                              painter(this);
  int                                   i;
  int                                   n;
  int                                   x;
  int                                   y;
  int                                   width;
  int                                   height;
  
  n = ApplicationConfiguration::WindowElements.count();

  x = 20;
  y = 10;

  width = 0;
  height = 0;
  for (i = 0; i < n; i++) {
    element = ApplicationConfiguration::WindowElements[i];
    size = element->GetDrawSize();
    if ( size.width() > width ) {
      width = size.width();
    }
  }
  for (i = 0; i < n; i++) {
    element = ApplicationConfiguration::WindowElements[i];
    size = element->GetDrawSize();
    height = size.height();
    size = element->SlotSignalPaint(&painter, QPoint(x, y), QSize(width, height));
    if ( height > 0 ) {
      y += height + 10;
    }
  }
}
