/*****************************************************************************
 * FILE NAME    : WindowHierarchyContainer.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowhierarchycontainer_h_
#define _windowhierarchycontainer_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowHierarchyContainerElement.h"
#include "WindowElement.h"
#include "WindowElementList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : WindowHierarchyContainer
 *****************************************************************************/
class WindowHierarchyContainer : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowHierarchyContainer      (WindowElementList* InElements);

 //! Destructor
 public :
  ~WindowHierarchyContainer     ();

 //! Public Methods
 public :
  void                          AddWindowElement        (WindowElement* InElement);
  WindowElementList*            GetElements             (void);
  void                          SetElements             (WindowElementList* InElements);
  
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
  QList<WindowHierarchyContainerElement*>       elements;
  
  WindowElementList*            windowElements;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowhierarchycontainer_h_*/
