/*****************************************************************************
 * FILE NAME    : SignalSlotContainer.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _signalslotcontainer_h_
#define _signalslotcontainer_h_

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
#define SIGNAL_SLOT_CONTAINER_X         200
#define SIGNAL_SLOT_CONTAINER_Y         200
#define SIGNAL_SLOT_CONTAINER_WIDTH     200
#define SIGNAL_SLOT_CONTAINER_HEIGHT    200

/*****************************************************************************!
 * Exported Class : SignalSlotContainer
 *****************************************************************************/
class SignalSlotContainer : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SignalSlotContainer           ();

 //! Destructor
 public :
  ~SignalSlotContainer          ();

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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _signalslotcontainer_h_*/
