/*****************************************************************************
 * FILE NAME    : ApplicationLogEntry.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _applicationlogentry_h_
#define _applicationlogentry_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : ApplicationLogEntry
 *****************************************************************************/
class ApplicationLogEntry : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ApplicationLogEntry           ();
  ApplicationLogEntry           (QString InLine, QDateTime InTime);

 //! Destructor
 public :
  ~ApplicationLogEntry          ();

 //! Public Methods
 public :
  QString                       GetLine                 (void);
  void                          SetLine                 (QString InLine);
  QDateTime                     GetTime                 (void);
  void                          SetTime                 (QDateTime InTime);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  QString                       line;
  QDateTime                     time;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _applicationlogentry_h_*/
