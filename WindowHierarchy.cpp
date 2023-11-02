/*****************************************************************************
 * FILE NAME    : WindowHierarchy.cpp
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
#include "WindowHierarchy.h"

/*****************************************************************************!
 * Function : WindowHierarchy
 *****************************************************************************/
WindowHierarchy::WindowHierarchy
() : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~WindowHierarchy
 *****************************************************************************/
WindowHierarchy::~WindowHierarchy
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
WindowHierarchy::initialize()
{
  setFrameShadow(QFrame::Sunken);
  setFrameShape(QFrame::Box);
  setLineWidth(4);
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
WindowHierarchy::CreateSubWindows()
{
  scrollArea = new WindowHierarchyScrollArea();  
  scrollArea->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
WindowHierarchy::InitializeSubWindows()
{
  scrollArea = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
WindowHierarchy::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
  if ( scrollArea ) {
    scrollArea->move(0, 0);
    scrollArea->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : AddWindowElement
 *****************************************************************************/
void
WindowHierarchy::AddWindowElement
(WindowElement* InElement)
{
  scrollArea->AddWindowElement(InElement);
}
