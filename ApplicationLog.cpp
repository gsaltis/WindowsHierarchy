/*****************************************************************************
 * FILE NAME    : ApplicationLog.cpp
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
#include "ApplicationLog.h"

/*****************************************************************************!
 * Function : ApplicationLog
 *****************************************************************************/
ApplicationLog::ApplicationLog
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~ApplicationLog
 *****************************************************************************/
ApplicationLog::~ApplicationLog
()
{
}

/*****************************************************************************!
 * Function : AddEntry
 *****************************************************************************/
void
ApplicationLog::AddEntry
(ApplicationLogEntry* InEntry)
{
  if ( NULL == InEntry ) {
    return;
  }
  
  entries << InEntry;
}

/*****************************************************************************!
 * Function : AddEntry
 *****************************************************************************/
void
ApplicationLog::AddEntry
(QString InLine, QDateTime InTime)
{
  ApplicationLogEntry*          entry;
  
  entry = new ApplicationLogEntry(InLine, InTime);
  entries << entry;
}

/*****************************************************************************!
 * Function : AddEntry
 *****************************************************************************/
void
ApplicationLog::AddEntry
(QString InLine)
{
  ApplicationLogEntry*          entry;
  QDateTime                     time = QDateTime::currentDateTime();
  
  entry = new ApplicationLogEntry(InLine, time);
  entries << entry;
}

/*****************************************************************************!
 * Function : GetCount
 *****************************************************************************/
uint32_t
ApplicationLog::GetCount(void)
{
  return entries.size();
}

/*****************************************************************************!
 * Function : GetEntryByIndex
 *****************************************************************************/
ApplicationLogEntry*
ApplicationLog::GetEntryByIndex
(uint32_t InIndex)
{
  if ( InIndex >= entries.size() ) {
    return NULL;
  }
  return entries[InIndex];
}
