/*****************************************************************************
 * FILE NAME    : WindowHierarchyContainerElement.cpp
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
#include "WindowHierarchyContainerElement.h"
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Function : WindowHierarchyContainerElement
 *****************************************************************************/
WindowHierarchyContainerElement::WindowHierarchyContainerElement
() : QWidget()
{
  windowElement = NULL;
  initialize();
}

/*****************************************************************************!
 * Function : WindowHierarchyContainerElement
 *****************************************************************************/
WindowHierarchyContainerElement::WindowHierarchyContainerElement
(WindowElement* InWindowElement) : QWidget()
{
  QPalette pal;
  windowElement = InWindowElement;
  initialize();
}

/*****************************************************************************!
 * Function : ~WindowHierarchyContainerElement
 *****************************************************************************/
WindowHierarchyContainerElement::~WindowHierarchyContainerElement
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
WindowHierarchyContainerElement::initialize()
{
  QPalette                              pal;
  
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
WindowHierarchyContainerElement::CreateSubWindows()
{
  QPalette                              pal;
  QFont                                 font;
  int                                   height = 20;
  QColor                                color;
  
  if ( windowElement == NULL ) {
    return;
  }

  color = QColor(0, 0, 0);
  font = QFont("Segoe UI", 10, QFont::Normal);
  if ( windowElement->GetTransient() ) {
    font.setItalic(true);
    font.setWeight(QFont::Bold);
    color = QColor(128, 0, 128);
  }
  //! Create label  
  NameLabel = new QLabel();
  NameLabel->setParent(this);
  NameLabel->move(windowElement->GetLevel() * 10, 1);
  NameLabel->resize(200, height);
  NameLabel->setText(windowElement->GetName());
  NameLabel->setAlignment(Qt::AlignLeft);
  NameLabel->setFont(font);
  pal = NameLabel->palette();
  pal.setBrush(QPalette::WindowText, QBrush(color));
  NameLabel->setPalette(pal);

  //! Create label  
  ClassNameLabel = new QLabel();
  ClassNameLabel->setParent(this);
  ClassNameLabel->move(10, 1);
  ClassNameLabel->resize(100, height);
  ClassNameLabel->setText(windowElement->GetClassName());
  ClassNameLabel->setAlignment(Qt::AlignLeft);
  ClassNameLabel->setFont(font);
  pal = ClassNameLabel->palette();
  pal = NameLabel->palette();
  pal.setBrush(QPalette::WindowText, QBrush(color));
  ClassNameLabel->setPalette(pal);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
WindowHierarchyContainerElement::InitializeSubWindows()
{
  NameLabel = NULL;
  ClassNameLabel = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
WindowHierarchyContainerElement::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int                                   nameLabelX;
  int                                   nameLabelY;
  int                                   nameLabelW;
  int                                   nameLabelH;
  int                                   classNameLabelX;
  int                                   classNameLabelY;
  int                                   classNameLabelW;
  int                                   classNameLabelH;

  
  if ( NULL == NameLabel && NULL == ClassNameLabel ) {
    return;
  }
  size = InEvent->size();
  width = size.width();
  
  nameLabelX = windowElement->GetLevel() * 10;
  nameLabelY = 1;
  nameLabelW = 200 - nameLabelX;
  nameLabelH = NameLabel->size().height();;

  classNameLabelX = 205;
  classNameLabelY = 1;
  classNameLabelW = width - 205;
  classNameLabelH = ClassNameLabel->size().height();

  NameLabel->move(nameLabelX, nameLabelY);
  NameLabel->resize(nameLabelW, nameLabelH);

  ClassNameLabel->move(classNameLabelX, classNameLabelY);
  ClassNameLabel->resize(classNameLabelW, classNameLabelH);
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
WindowHierarchyContainerElement::paintEvent
(QPaintEvent*)
{
  QPen                                  pen = QPen(QColor(128, 0, 0, 64));
  QColor                                color = QColor(224, 224, 224);
  QColor                                color1;
  
  QPainter                              painter(this);
  int                                   y;
  int                                   x2;
  QRect                                 rect;
  int                                   width;
  
  if ( NULL == windowElement ) {
    return;
  }
  y = size().height() - 1;
  x2 = size().width();

  painter.setPen(pen);
  painter.drawLine(0, y, x2, y);

  color1 = color.darker(100 + windowElement->GetLevel() * 20);
  painter.setBrush(QBrush(color1));
  painter.setPen(QPen(color1));
  width = windowElement->GetLevel() * 10 - 3;
  
  rect = QRect(1, 1, width, size().height() - 4);
  painter.drawRect(rect);
}
