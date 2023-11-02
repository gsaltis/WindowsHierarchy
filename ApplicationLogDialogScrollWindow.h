/*****************************************************************************
 * FILE NAME    : ApplicationLogDialogScrollWindow.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _applicationlogdialogscrollwindow_h_
#define _applicationlogdialogscrollwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QScrollArea>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ApplicationLogDialogWindow.h"
#include "ApplicationLog.h"
#include "ApplicationLogEntry.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define APPLICATION_LOG_DIALOG_SCROLL_WINDOW_X 200
#define APPLICATION_LOG_DIALOG_SCROLL_WINDOW_Y 200
#define APPLICATION_LOG_DIALOG_SCROLL_WINDOW_WIDTH 200
#define APPLICATION_LOG_DIALOG_SCROLL_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : ApplicationLogDialogScrollWindow
 *****************************************************************************/
class ApplicationLogDialogScrollWindow : public QScrollArea
{
  Q_OBJECT;

 //! Constructors
 public :
  ApplicationLogDialogScrollWindow (ApplicationLog* InLog);

 //! Destructor
 public :
  ~ApplicationLogDialogScrollWindow ();

 //! Public Methods
 public :
  void                          AddEntry                (ApplicationLogEntry* InEntry);
  void                          ResizeEntryWindow       ();

 //! Public Data
 public :

 //! Protected Methods
 protected :
  void                          resizeEvent             (QResizeEvent* InEvent);
  
 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  
 //! Private Data
 private :
  ApplicationLogDialogWindow*   logWindow;
  ApplicationLog*               log;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _applicationlogdialogscrollwindow_h_*/
