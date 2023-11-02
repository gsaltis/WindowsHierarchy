/*****************************************************************************
 * FILE NAME    : WindowHierarchyScrollArea.cpp
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
#include "WindowHierarchyScrollArea.h"

/*****************************************************************************!
 * Function : WindowHierarchyScrollArea
 *****************************************************************************/
WindowHierarchyScrollArea::WindowHierarchyScrollArea
() : QScrollArea()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~WindowHierarchyScrollArea
 *****************************************************************************/
WindowHierarchyScrollArea::~WindowHierarchyScrollArea
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
WindowHierarchyScrollArea::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
WindowHierarchyScrollArea::CreateSubWindows()
{
  hierarchyWindow = new WindowHierarchyContainer();  
  setWidget(hierarchyWindow);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
WindowHierarchyScrollArea::InitializeSubWindows()
{
  hierarchyWindow = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
WindowHierarchyScrollArea::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;

  size = InEvent->size();
  width = size.width();
  (void)width;
  if ( hierarchyWindow ) {
    hierarchyWindow->resize(width, hierarchyWindow->size().height());
  }
}

/*****************************************************************************!
 * Function : AddWindowElement
 *****************************************************************************/
void
WindowHierarchyScrollArea::AddWindowElement
(WindowElement* InElement)
{
  hierarchyWindow->AddWindowElement(InElement);
}
