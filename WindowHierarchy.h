/*****************************************************************************
 * FILE NAME    : WindowHierarchy.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowhierarchy_h_
#define _windowhierarchy_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowHierarchyScrollArea.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define WINDOW_HIERARCHY_X              200
#define WINDOW_HIERARCHY_Y              200
#define WINDOW_HIERARCHY_WIDTH          200
#define WINDOW_HIERARCHY_HEIGHT         200

/*****************************************************************************!
 * Exported Class : WindowHierarchy
 *****************************************************************************/
class WindowHierarchy : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowHierarchy               ();

 //! Destructor
 public :
  ~WindowHierarchy              ();

 //! Public Methods
 public :
  void                          AddWindowElement        (WindowElement* InElement);

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
  WindowHierarchyScrollArea*    scrollArea;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowhierarchy_h_*/
