/*****************************************************************************
 * FILE NAME    : ApplicationLogDisplayWindowElement.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _applicationlogdisplaywindowelement_h_
#define _applicationlogdisplaywindowelement_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ApplicationLogEntry.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define APPLICATION_LOG_DISPLAY_WINDOW_ELEMENT_X 0
#define APPLICATION_LOG_DISPLAY_WINDOW_ELEMENT_Y 0
#define APPLICATION_LOG_DISPLAY_WINDOW_ELEMENT_WIDTH 0
#define APPLICATION_LOG_DISPLAY_WINDOW_ELEMENT_HEIGHT 20

/*****************************************************************************!
 * Exported Class : ApplicationLogDisplayWindowElement
 *****************************************************************************/
class ApplicationLogDisplayWindowElement : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ApplicationLogDisplayWindowElement (ApplicationLogEntry* InEntry);

 //! Destructor
 public :
  ~ApplicationLogDisplayWindowElement ();

 //! Public Methods
 public :

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  QLabel*                       timeLabel;
  QLabel*                       lineLabel;
  ApplicationLogEntry*          logEntry;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _applicationlogdisplaywindowelement_h_*/
