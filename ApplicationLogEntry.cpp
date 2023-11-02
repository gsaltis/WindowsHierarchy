/*****************************************************************************
 * FILE NAME    : ApplicationLogEntry.cpp
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
#include "ApplicationLogEntry.h"

/*****************************************************************************!
 * Function : ApplicationLogEntry
 *****************************************************************************/
ApplicationLogEntry::ApplicationLogEntry
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ApplicationLogEntry
 *****************************************************************************/
ApplicationLogEntry::ApplicationLogEntry
(QString InLine, QDateTime InTime) : QWidget()
{
  line = InLine;
  time = InTime;
}

/*****************************************************************************!
 * Function : ~ApplicationLogEntry
 *****************************************************************************/
ApplicationLogEntry::~ApplicationLogEntry
()
{
}

/*****************************************************************************!
 * Function : GetLine
 *****************************************************************************/
QString
ApplicationLogEntry::GetLine(void)
{
  return line;  
}

/*****************************************************************************!
 * Function : SetLine
 *****************************************************************************/
void
ApplicationLogEntry::SetLine
(QString InLine)
{
  line = InLine;  
}

/*****************************************************************************!
 * Function : GetTime
 *****************************************************************************/
QDateTime
ApplicationLogEntry::GetTime(void)
{
  return time;  
}

/*****************************************************************************!
 * Function : SetTime
 *****************************************************************************/
void
ApplicationLogEntry::SetTime
(QDateTime InTime)
{
  time = InTime;  
}
