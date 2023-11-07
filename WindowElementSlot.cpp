/*****************************************************************************
 * FILE NAME    : WindowElementSlot.cpp
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
#include "WindowElementSlot.h"

/*****************************************************************************!
 * Function : WindowElementSlot
 *****************************************************************************/
WindowElementSlot::WindowElementSlot
(int InClassID, int InElementID, int InID, QString InName) :
  WindowElementSignalSlot(InClassID, InElementID, InID, InName, QColor(0, 96, 192))
{
}

/*****************************************************************************!
 * Function : ~WindowElementSlot
 *****************************************************************************/
WindowElementSlot::~WindowElementSlot
()
{
}

