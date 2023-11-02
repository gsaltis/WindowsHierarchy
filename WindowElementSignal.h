/*****************************************************************************
 * FILE NAME    : WindowElementSignal.h
 * DATE         : November 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowelementsignal_h_
#define _windowelementsignal_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowElementSignalSlot.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : WindowElementSignal
 *****************************************************************************/
class WindowElementSignal : public WindowElementSignalSlot
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowElementSignal           (QString InName);

 //! Destructor
 public :
  ~WindowElementSignal          ();

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

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowelementsignal_h_*/
