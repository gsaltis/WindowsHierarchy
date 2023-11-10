/*****************************************************************************
 * FILE NAME    : WindowElement.cpp
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
#include "WindowElement.h"
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Function : WindowElement
 *****************************************************************************/
WindowElement::WindowElement
() : QWidget()
{
  Initialize();
}

/*****************************************************************************!
 * Function : WindowElement
 *****************************************************************************/
WindowElement::WindowElement
(int InClassID, int InElementID, int InParentID, QString InName, bool InTransient)
{
  Initialize();
  Set(InClassID, InElementID, InParentID, InName, InTransient);
}

/*****************************************************************************!
 * Function : WindowElement
 *****************************************************************************/
WindowElement::WindowElement
(QString InName, bool InTransient) : QWidget()
{
  Initialize();
  Set(0, 0, 0, InName, InTransient);
}

/*****************************************************************************!
 * Function : Set
 *****************************************************************************/
void
WindowElement::Set
(int InClassID, int InElementID, int InParentID, QString InName, bool InTransient)
{
  classID       = InClassID;
  elementID     = InElementID;
  parentID      = InParentID;
  name          = InName;
  transient     = InTransient;
}

#if 0
/*****************************************************************************!
 * Function : WindowElement
 *****************************************************************************/
WindowElement::WindowElement
(QString InLine)
{
  QStringList                   elements;
  int                           i;
  int                           n;
  int                           j;
  int                           m;
  QString                       st;
  QStringList                   signalTexts;
  QString                       signalText;
  WindowElementSignal*          elementSignal;
  QStringList                   slotTexts;
  QString                       slotText;
  WindowElementSlot*            elementSlot;
  
  elements = InLine.split(",");
  n = elements.count();
  
  if ( n < 4 ) {
    return;
  }
  i = 0;

  name = elements[i].remove('"');
  i++;

  className = elements[i].remove('"');
  i++;
  
  level = elements[i].toInt();
  i++;
  
  if ( elements[i] == "true" ) {
    transient = true;
  }
  i++;

  if ( i == n ) {
    return;
  }

  //!
  st = elements[i];
  signalTexts = st.split(' ');
  m = signalTexts.count();
  ApplicationConfiguration::MainApplicationLog->AddEntry(QString("%1 %2 %3 %4").
                                                         arg(__FILE__).
                                                         arg(__LINE__).
                                                         arg(name).
                                                         arg(m));
  for ( j = 0 ; j < m ; j++ ) {
    signalText = signalTexts[j].trimmed();
    if ( signalText.isEmpty() ) {
      continue;
    }
    elementSignal = new WindowElementSignal(signalText);
    AddWindowSignal(elementSignal);
  }
  i++;
  
  if ( i == n ) {
    return;
  }

  //!
  st = elements[i];
  slotTexts = st.split(' ');
  m = slotTexts.count();
  for ( j = 0 ; j < m ; j++ ) {
    slotText = slotTexts[j].trimmed();
    if ( slotText.isEmpty() ) {
      continue;
    }
    elementSlot = new WindowElementSlot(slotText);
    AddWindowSlot(elementSlot);
  }
}
#endif

/*****************************************************************************!
 * Function : ~WindowElement
 *****************************************************************************/
WindowElement::~WindowElement
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
WindowElement::Initialize
()
{
  classID       = 0;
  elementID     = 0;
  parentID      = 0;
  name          = QString("");
  transient     = false;
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
WindowElement::GetName(void)
{
  return name;  
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
WindowElement::SetName
(QString InName)
{
  name = InName;  
}

/*****************************************************************************!
 * Function : GetTransient
 *****************************************************************************/
bool
WindowElement::GetTransient(void)
{
  
  return transient;
}

/*****************************************************************************!
 * Function : SetTransient
 *****************************************************************************/
void
WindowElement::SetTransient
(bool InTransient)
{
  
  transient = InTransient;
}

/*****************************************************************************!
 * Function : AddWindowSignal
 *****************************************************************************/
void
WindowElement::AddWindowSignal
(WindowElementSignal* InWindowSignal)
{
  if ( NULL == InWindowSignal ) {
    return;
  }
  elementSignals << InWindowSignal;
}

/*****************************************************************************!
 * Function : AddWindowSlot
 *****************************************************************************/
void
WindowElement::AddWindowSlot
(WindowElementSlot* InWindowSlot)
{
  if ( NULL == InWindowSlot ) {
    return;
  }
  elementSlots << InWindowSlot;  
}

/*****************************************************************************!
 * Function : SlotSignalPaint
 *****************************************************************************/
QSize
WindowElement::SlotSignalPaint
(QPainter* InPainter, QPoint InLocation, QSize InSize)
{
  QRect                                 rect;
  QPoint                                textLocation;
  QPoint                                location;
  QColor                                color = QColor(224, 224, 224);
  QPen                                  pen;
  QBrush                                brush;
  QFont                                 font = QFont("Segoe UI", 11, QFont::Bold);
  QFontMetrics                          fm(font);
  QSize                                 textSize;
  QString                               text;
  WindowElementSignal*                  elementSignal;
  WindowElementSlot*                    elementSlot;
  QSize                                 s;
  
  textSize = QSize(0, 0);

  text = name;
  if ( name.isEmpty() ) {
    color = QColor(128, 128, 255);
  }
  if ( text.isEmpty() ) {
    return textSize;
  }

  brush = QBrush(color);
  pen = QPen(color.darker(300));

  InPainter->setPen(pen);
  InPainter->setBrush(brush);
  textSize = fm.size(Qt::TextSingleLine, text);
  location = InLocation + QPoint(0, textSize.height() / 2);
  textLocation = location + QPoint(2, 5);

  rect = QRect(InLocation, InSize);
  InPainter->drawRect(rect);
  InPainter->drawText(textLocation, text);

  if ( elementSignals.count() > 0 ) {
    elementSignal  = elementSignals[0];
    elementSignal->move(rect.right()+2, rect.top() + 2);
    elementSignal->Paint(InPainter);
  }
  if ( elementSlots.count() > 0 ) {
    elementSlot  = elementSlots[0];
    s = elementSlot->size();
    elementSlot->move(rect.left()-(s.width() + 1), rect.top() + 2);
    elementSlot->Paint(InPainter);
  }
  return textSize;
}

/*****************************************************************************!
 * Function : SlotSignalPaint
 *****************************************************************************/
QSize
WindowElement::GetDrawSize
()
{
  QRect                                 rect;
  QFont                                 font = QFont("Segoe UI", 11, QFont::Bold);
  QFontMetrics                          fm(font);
  QSize                                 textSize;
  QString                               text;

  textSize = QSize(0, 0);

  text = name;
  if ( text.isEmpty() ) {
    return textSize;
  }

  textSize = fm.size(Qt::TextSingleLine, text);
  rect = QRect(QPoint(0, 0), textSize + QSize(text.length()*-2+8, 0));
  return rect.size();
}

/*****************************************************************************!
 * Function : GetClassID
 *****************************************************************************/
int
WindowElement::GetClassID
()
{
  return classID;
}

/*****************************************************************************!
 * Function : SetClassID
 *****************************************************************************/
void
WindowElement::SetClassID
(int InClassID)
{
  classID = InClassID;
}

/*****************************************************************************!
 * Function : GetElementID
 *****************************************************************************/
int
WindowElement::GetElementID
()
{
  return elementID;
}

/*****************************************************************************!
 * Function : SetElementID
 *****************************************************************************/
void
WindowElement::SetElementID
(int InElementID)
{
  elementID = InElementID;
}

/*****************************************************************************!
 * Function : GetParentID
 *****************************************************************************/
int
WindowElement::GetParentID
()
{
  return parentID;
}
