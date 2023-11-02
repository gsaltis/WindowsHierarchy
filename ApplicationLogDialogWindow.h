/*****************************************************************************
 * FILE NAME    : ApplicationLogDialogWindow.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _applicationlogdialogwindow_h_
#define _applicationlogdialogwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ApplicationLog.h"
#include "ApplicationLogEntry.h"
#include "ApplicationLogDisplayWindowElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define APPLICATION_LOG_DIALOG_WINDOW_X 200
#define APPLICATION_LOG_DIALOG_WINDOW_Y 200
#define APPLICATION_LOG_DIALOG_WINDOW_WIDTH 200
#define APPLICATION_LOG_DIALOG_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : ApplicationLogDialogWindow
 *****************************************************************************/
class ApplicationLogDialogWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ApplicationLogDialogWindow    (ApplicationLog* InLog);

 //! Destructor
 public :
  ~ApplicationLogDialogWindow   ();

 //! Public Methods
 public :
  void                          ResizeWindow            ();
  void                          AddEntry                (ApplicationLogEntry* InEntry);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  ApplicationLog*               log;
  QList<ApplicationLogDisplayWindowElement*>    elements;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _applicationlogdialogwindow_h_*/
