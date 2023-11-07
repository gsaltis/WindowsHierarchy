/*****************************************************************************
 * FILE NAME    : WindowElementSlot.h
 * DATE         : November 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowelementslot_h_
#define _windowelementslot_h_

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
 * Exported Class : WindowElementSlot
 *****************************************************************************/
class WindowElementSlot : public WindowElementSignalSlot
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowElementSlot             (int InClassID, int InElementID, int InID, QString InName);

 //! Destructor
 public :
  ~WindowElementSlot            ();

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

#endif /* _windowelementslot_h_*/
