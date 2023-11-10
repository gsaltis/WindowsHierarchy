/*****************************************************************************
 * FILE NAME    : ApplicationLogDisplayWindowElement.cpp
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
#include "ApplicationLogDisplayWindowElement.h"
#include "ApplicationLogEntry.h"

/*****************************************************************************!
 * Function : ApplicationLogDisplayWindowElement
 *****************************************************************************/
ApplicationLogDisplayWindowElement::ApplicationLogDisplayWindowElement
(ApplicationLogEntry* InEntry) : QWidget()
{
  QPalette pal;

  logEntry = InEntry;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ApplicationLogDisplayWindowElement
 *****************************************************************************/
ApplicationLogDisplayWindowElement::~ApplicationLogDisplayWindowElement
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ApplicationLogDisplayWindowElement::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ApplicationLogDisplayWindowElement::CreateSubWindows()
{

  //! Create label  
  timeLabel = new QLabel();
  timeLabel->setParent(this);
  timeLabel->move(10, 1);
  timeLabel->resize(160, 20);
  timeLabel->setText(logEntry->GetTime().toString("MM/dd/yyyy hh:mm:ss.zzz"));
  timeLabel->setAlignment(Qt::AlignRight);
  timeLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));

  //! Create label
  lineLabel = new QLabel();
  lineLabel->setParent(this);
  lineLabel->move(10, 1);
  lineLabel->resize(100, 20);
  lineLabel->setText(logEntry->GetLine());
  lineLabel->setAlignment(Qt::AlignLeft);
  lineLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ApplicationLogDisplayWindowElement::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ApplicationLogDisplayWindowElement::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  int                                   timeLabelX;
  int                                   timeLabelY;
  int                                   timeLabelW;
  int                                   timeLabelH;
  
  int                                   lineLabelX;
  int                                   lineLabelY;
  int                                   lineLabelW;
  int                                   lineLabelH;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  
  timeLabelW = timeLabel->size().width();
  timeLabelX = 10;
  timeLabelH = height - 2;
  timeLabelY = 1;

  lineLabelW = width - (timeLabelW + 30);
  lineLabelH = height - 2;
  lineLabelY = 1;
  lineLabelX = timeLabelX + timeLabelW + 10;

  timeLabel->move(timeLabelX, timeLabelY);
  timeLabel->resize(timeLabelW, timeLabelH);

  lineLabel->move(lineLabelX, lineLabelY);
  lineLabel->resize(lineLabelW, lineLabelH);
}
