/*****************************************************************************
 * FILE NAME    : WindowElementSignalSlot.h
 * DATE         : November 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowelementsignalslot_h_
#define _windowelementsignalslot_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : WindowElementSignalSlot
 *****************************************************************************/
class WindowElementSignalSlot : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowElementSignalSlot       (int InClassID, int InElementID, int InID, QString InName, QColor InColor);

 //! Destructor
 public :
  ~WindowElementSignalSlot      ();

 //! Public Methods
 public :
  QString                       GetName                 (void);
  void                          SetName                 (QString InName);
  void                          Paint                   (QPainter* InPainter);
  int                           GetClassID              ();
  int                           GetElementID            ();
  int                           GetID                   ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :
  QString                       name;
  QColor                        color;
  int                           classID;
  int                           elementID;
  int                           id;

 //! Private Methods
 private :

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowelementsignalslot_h_*/
