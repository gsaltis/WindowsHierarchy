/*****************************************************************************
 * FILE NAME    : ApplicationLog.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _applicationlog_h_
#define _applicationlog_h_

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
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : ApplicationLog
 *****************************************************************************/
class ApplicationLog : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ApplicationLog                ();

 //! Destructor
 public :
  ~ApplicationLog               ();

 //! Public Methods
 public :
  void                          AddEntry                (ApplicationLogEntry* InEntry);
  void                          AddEntry                (QString InLine, QDateTime InTime);
  void                          AddEntry                (QString InLine);
  uint32_t                      GetCount                (void);
  ApplicationLogEntry*          GetEntryByIndex         (uint32_t InIndex);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  QList<ApplicationLogEntry*>   entries;
  
 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _applicationlog_h_*/
