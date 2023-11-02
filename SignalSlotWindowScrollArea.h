/*****************************************************************************
 * FILE NAME    : SignalSlotWindowScrollArea.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _signalslotwindowscrollarea_h_
#define _signalslotwindowscrollarea_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QScrollArea>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SignalSlotContainer.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SIGNAL_SLOT_WINDOW_SCROLL_AREA_X 200
#define SIGNAL_SLOT_WINDOW_SCROLL_AREA_Y 200
#define SIGNAL_SLOT_WINDOW_SCROLL_AREA_WIDTH 200
#define SIGNAL_SLOT_WINDOW_SCROLL_AREA_HEIGHT 200

/*****************************************************************************!
 * Exported Class : SignalSlotWindowScrollArea
 *****************************************************************************/
class SignalSlotWindowScrollArea : public QScrollArea
{
  Q_OBJECT;

 //! Constructors
 public :
  SignalSlotWindowScrollArea    ();

 //! Destructor
 public :
  ~SignalSlotWindowScrollArea   ();

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
  SignalSlotContainer*          signalSlotWindow;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _signalslotwindowscrollarea_h_*/
