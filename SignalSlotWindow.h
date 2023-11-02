/*****************************************************************************
 * FILE NAME    : SignalSlotWindow.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _signalslotwindow_h_
#define _signalslotwindow_h_

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

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SIGNAL_SLOT_WINDOW_X            200
#define SIGNAL_SLOT_WINDOW_Y            200
#define SIGNAL_SLOT_WINDOW_WIDTH        200
#define SIGNAL_SLOT_WINDOW_HEIGHT       200

/*****************************************************************************!
 * Exported Class : SignalSlotWindow
 *****************************************************************************/
class SignalSlotWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SignalSlotWindow              ();

 //! Destructor
 public :
  ~SignalSlotWindow             ();

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
  SignalSlotWindowScrollArea*   scrollWindow;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _signalslotwindow_h_*/
