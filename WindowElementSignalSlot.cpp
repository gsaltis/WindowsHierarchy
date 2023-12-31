/*****************************************************************************
 * FILE NAME    : WindowElementSignalSlot.cpp
 * DATE         : November 02 2023
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
#include "WindowElementSignalSlot.h"
#include "WindowElement.h"

/*****************************************************************************!
 * Function : WindowElementSignalSlot
 *****************************************************************************/
WindowElementSignalSlot::WindowElementSignalSlot
(int InClassID, int InElementID, int InID, QString InName, QColor InColor) : QWidget()
{
  name = InName;
  color = InColor;
  classID = InClassID;
  elementID = InElementID;
  id = InID;
  resize(8, 8);
}

/*****************************************************************************!
 * Function : ~WindowElementSignalSlot
 *****************************************************************************/
WindowElementSignalSlot::~WindowElementSignalSlot
()
{
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
WindowElementSignalSlot::GetName(void)
{
  return name;  
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
WindowElementSignalSlot::SetName
(QString InName)
{
  name = InName;  
}

/*****************************************************************************!
 * Function : GetClassID
 *****************************************************************************/
int
WindowElementSignalSlot::GetClassID
()
{
  return classID;
}

/*****************************************************************************!
 * Function : GetElementID
 *****************************************************************************/
int
WindowElementSignalSlot::GetElementID
()
{
  return elementID;
}

/*****************************************************************************!
 * Function : GetID
 *****************************************************************************/
int
WindowElementSignalSlot::GetID
()
{
  return id;
}

/*****************************************************************************!
 * Function : Paint
 *****************************************************************************/
void
WindowElementSignalSlot::Paint
(QPainter* InPainter)
{
  QRect                                 rect(pos(), size());
  QBrush                                brush;
  QPen                                  pen;

  pen = QPen(color.darker(150));
  brush = QBrush(color);

  InPainter->setPen(pen);
  InPainter->setBrush(brush);

  InPainter->drawRect(rect);
}
