/*****************************************************************************
 * FILE NAME    : WindowHierarchyContainerElement.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowhierarchycontainerelement_h_
#define _windowhierarchycontainerelement_h_

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
#include "WindowElement.h"
#include "WindowElementList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define WINDOW_HIERARCHY_CONTAINER_ELEMENT_HEIGHT       20

/*****************************************************************************!
 * Exported Class : WindowHierarchyContainerElement
 *****************************************************************************/
class WindowHierarchyContainerElement : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowHierarchyContainerElement (WindowElement* InWindowElement, WindowElementList * InElements);

 //! Destructor
 public :
  ~WindowHierarchyContainerElement ();

 //! Public Methods
 public :
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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  QLabel*                       NameLabel;
  QLabel*                       ClassNameLabel;
  WindowElement*                windowElement;  
  WindowElementList*            elements;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowhierarchycontainerelement_h_*/
