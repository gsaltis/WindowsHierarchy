/*****************************************************************************
 * FILE NAME    : WindowElementList.h
 * DATE         : November 09 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowelementlist_h_
#define _windowelementlist_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : WindowElementList
 *****************************************************************************/
class WindowElementList : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowElementList             ();

 //! Destructor
 public :
  ~WindowElementList            ();

 //! Public Methods
 public :
  void                          AddElement              (WindowElement* InElement);
  WindowElement*                FindElementByID         (int InID);
  int                           GetElementDepth         (WindowElement* InElement);
  int                           GetElementCount         ();
  WindowElement*                GetElementByIndex       (int InIndex);
  
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
  QList<WindowElement*>         elements;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowelementlist_h_*/
