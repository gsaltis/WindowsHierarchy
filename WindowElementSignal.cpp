/*****************************************************************************
 * FILE NAME    : WindowElementSignal.cpp
 * DATE         : November 02 2023
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
#include "WindowElementSignal.h"

/*****************************************************************************!
 * Function : WindowElementSignal
 *****************************************************************************/
WindowElementSignal::WindowElementSignal
(int InClassID, int InElementID, int InID, QString InName) :
  WindowElementSignalSlot(InClassID, InElementID, InID, InName, QColor(192, 0, 0))
{
}

/*****************************************************************************!
 * Function : ~WindowElementSignal
 *****************************************************************************/
WindowElementSignal::~WindowElementSignal
()
{
}

