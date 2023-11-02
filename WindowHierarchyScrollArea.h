/*****************************************************************************
 * FILE NAME    : WindowHierarchyScrollArea.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowhierarchyscrollarea_h_
#define _windowhierarchyscrollarea_h_

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
#include "WindowHierarchyContainer.h"
#include "WindowElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define WINDOW_HIERARCHY_SCROLL_AREA_X  200
#define WINDOW_HIERARCHY_SCROLL_AREA_Y  200
#define WINDOW_HIERARCHY_SCROLL_AREA_WIDTH 200
#define WINDOW_HIERARCHY_SCROLL_AREA_HEIGHT 200

/*****************************************************************************!
 * Exported Class : WindowHierarchyScrollArea
 *****************************************************************************/
class WindowHierarchyScrollArea : public QScrollArea
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowHierarchyScrollArea     ();

 //! Destructor
 public :
  ~WindowHierarchyScrollArea    ();

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
  WindowHierarchyContainer*     hierarchyWindow;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowhierarchyscrollarea_h_*/
