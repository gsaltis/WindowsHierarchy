/*****************************************************************************
 * FILE NAME    : WindowElement.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowelement_h_
#define _windowelement_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowElementSlot.h"
#include "WindowElementSignal.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : WindowElement
 *****************************************************************************/
class WindowElement : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowElement                 ();
  WindowElement                 (QString InName, bool InTransient = false);
  WindowElement                 (int InClassID, int InElementID, int InParentID, QString InName, bool InTransient = false);
  
  //! Destructor
 public :
  ~WindowElement                ();

 //! Public Methods
 public :
  QString                       GetName                 (void);
  void                          SetName                 (QString InName);
  QString                       GetClassName            (void);
  void                          SetClassName            (QString InClassName);
  int                           GetLevel                (void);
  void                          SetLevel                (int InLevel);
  bool                          GetTransient            (void);
  void                          SetTransient            (bool InTransient);
  void                          AddWindowSignal         (WindowElementSignal* InWindowSignal);
  void                          AddWindowSlot           (WindowElementSlot* InWindowSlot);
  QSize                         SlotSignalPaint         (QPainter* InPainter, QPoint InLocation, QSize InSize);
  QSize                         GetDrawSize             ();
  int                           GetClassID              ();
  void                          SetClassID              (int InClassID);
  int                           GetElementID            ();
  void                          SetElementID            (int InElementID);
  int                           GetParentID             ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              ();
  void                          Set                     (int InClassID, int InElementID, int InParentID, QString InName, bool InTransient);
  
 //! Private Data
 private :
  int                           elementID;
  int                           classID;
  int                           parentID;
  QString                       name;
  QList<WindowElementSignal*>   elementSignals;
  QList<WindowElementSlot*>     elementSlots;
  bool                          transient;
};

#endif /* _windowelement_h_*/
