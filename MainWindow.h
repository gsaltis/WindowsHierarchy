/*****************************************************************************
 * FILE NAME    : MainWindow.h
 * DATE         : November 01 2023
 * PROJECT      : WindowsHierarchy
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainwindow_h_
#define _mainwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "SystemConfig.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_WINDOW_WIDTH                       640
#define MAIN_WINDOW_HEIGHT                      480
#define MAIN_WINDOW_Y                           100
#define MAIN_WINDOW_X                           100

/*****************************************************************************!
 * Exported Class : MainWindow
 *****************************************************************************/
class MainWindow : public QMainWindow
{
  Q_OBJECT;

 //! Constructors
 public :
  MainWindow                    (QString InFilename);

 //! Destructor
 public :
  ~MainWindow                   ();

 //! Public Methods
 public :

 //! Public Data
 public :

 //! Protected Methods
 protected :
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          closeEvent              (QCloseEvent* InEvent);
  
 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          CreateActions           ();
  void                          CreateMenus             ();
  void                          ReadSettings            ();
  void                          CreateConnections       ();
  
 //! Private Data
 private :
  MainDisplayWindow*            displayWindow;
  QMenuBar*                     menubar;
  QMenu*                        fileMenu;
  QMenu*                        windowMenu;
  QStatusBar*                   statusbar;
  QString                       filename;
  
 //! Public Slots
 public slots :
  void                          SlotExit                (void);
  void                          SlotShowApplicationLog  (void);
  void                          SlotSelectHierarchyWindow (void);
  void                          SlotSelectSignalSlotWindow (void);

 //! Public Signals
 signals :
  void                          SignalSelectHierarchyWindow     ();
  void                          SignalSelectSignalSlotWindow    ();
  
 //! Public Actions
 public :
  QAction*                      ActionExit;
  QAction*                      ActionShowApplicationLog;
  QAction*                      ActionSelectHierarchyWindow;
  QAction*                      ActionSelectSignalSlotWindow;

};

#endif /* _mainwindow_h_*/
