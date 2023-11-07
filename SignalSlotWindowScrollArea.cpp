/*****************************************************************************
 * FILE NAME    : SignalSlotWindowScrollArea.cpp
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
#include "SignalSlotWindowScrollArea.h"
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Function : SignalSlotWindowScrollArea
 *****************************************************************************/
SignalSlotWindowScrollArea::SignalSlotWindowScrollArea
() : QScrollArea()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SignalSlotWindowScrollArea
 *****************************************************************************/
SignalSlotWindowScrollArea::~SignalSlotWindowScrollArea
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SignalSlotWindowScrollArea::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SignalSlotWindowScrollArea::CreateSubWindows()
{
  signalSlotWindow = new SignalSlotContainer();
  setWidget(signalSlotWindow);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SignalSlotWindowScrollArea::InitializeSubWindows()
{
  signalSlotWindow = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SignalSlotWindowScrollArea::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  signalSlotWindow->resize(size);
  (void)height;
  (void)width;
}
