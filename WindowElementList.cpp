/*****************************************************************************
 * FILE NAME    : WindowElementList.cpp
 * DATE         : November 09 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include "trace_winnet.h"
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowElementList.h"

/*****************************************************************************!
 * Function : WindowElementList
 *****************************************************************************/
WindowElementList::WindowElementList
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~WindowElementList
 *****************************************************************************/
WindowElementList::~WindowElementList
()
{
}

/*****************************************************************************!
 * Function : AddElement
 *****************************************************************************/
void
WindowElementList::AddElement
(WindowElement* InElement)
{
  if ( NULL == InElement ) {
    return;
  }

  elements << InElement;
}

/*****************************************************************************!
 * Function : FindElementByID
 *****************************************************************************/
WindowElement*
WindowElementList::FindElementByID
(int InID)
{
  for ( auto element : elements ) {
    if ( element->GetClassID() == InID ) {
      return element;
    }
  }
  return NULL;
}

/*****************************************************************************!
 * Function : GetElementDepth
 *****************************************************************************/
int
WindowElementList::GetElementDepth
(WindowElement* InElement)
{
  int                                   depth;
  int                                   id;
  WindowElement*                        element;

  TRACE_FUNCTION_START();
  depth = 1;

  if( InElement->GetElementID() == 0 ) {
    return 0;
  }
  element = InElement; 
  id = element->GetParentID();

  TRACE_FUNCTION_INT(id);
  while ( element ) {
    if ( id == 0 ) {
      break;
    }
    element = FindElementByID(id);
    if ( NULL == element ) {
      TRACE_FUNCTION_LOCATION();
      break;
    }
    depth++;
    id = element->GetParentID();
    TRACE_FUNCTION_INT(id);
  }
  TRACE_FUNCTION_INT(depth);
  TRACE_FUNCTION_END();
  return depth;
}

/*****************************************************************************!
 * Function : GetElementCount
 *****************************************************************************/
int
WindowElementList::GetElementCount
()
{
  return elements.size();
}

/*****************************************************************************!
 * Function : GetElementByIndex
 *****************************************************************************/
WindowElement*
WindowElementList::GetElementByIndex
(int InIndex)
{
  if ( InIndex >= elements.size() ) {
    return NULL;
  }

  return elements[InIndex];
}
