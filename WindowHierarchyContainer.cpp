/*****************************************************************************
 * FILE NAME    : WindowHierarchyContainer.cpp
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowHierarchyContainer.h"
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Function : WindowHierarchyContainer
 *****************************************************************************/
WindowHierarchyContainer::WindowHierarchyContainer
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~WindowHierarchyContainer
 *****************************************************************************/
WindowHierarchyContainer::~WindowHierarchyContainer
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
WindowHierarchyContainer::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
WindowHierarchyContainer::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
WindowHierarchyContainer::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
WindowHierarchyContainer::resizeEvent
(QResizeEvent* InEvent)
{
  WindowHierarchyContainerElement*      element;
  QSize					size;  
  int					width;
  int                                   i, n;
  int                                   y;
  
  size = InEvent->size();
  width = size.width();
  n = elements.size();

  y = 0;
  for ( i = 0 ; i < n ; i++ ) {
    element = elements[i];
    element->resize(width, element->size().height());
    element->move(0, y);
    y += element->size().height();
  }
  resize(width, y + 10);
}

/*****************************************************************************!
 * Function : AddWindowElement
 *****************************************************************************/
void
WindowHierarchyContainer::AddWindowElement
(WindowElement* InElement)
{
  WindowHierarchyContainerElement*      element;
  int                                   width;
  int                                   y;
  
  element = new WindowHierarchyContainerElement(InElement);

  width = size().width();
  y = elements.size() * WINDOW_HIERARCHY_CONTAINER_ELEMENT_HEIGHT;
  element->move(0, y);
  element->resize(width, WINDOW_HIERARCHY_CONTAINER_ELEMENT_HEIGHT);
  element->setParent(this);
  elements << element;
  
}
