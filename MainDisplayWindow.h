/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.h
 * DATE         : November 01 2023
 * PROJECT      : WindowsHierarchy
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maindisplaywindow_h_
#define _maindisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WindowHierarchy.h"
#include "SignalSlotWindow.h"
#include "sqlite3.h"
#include "WindowElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MainDisplayWindow
 *****************************************************************************/
class MainDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayWindow             (QString InFilename);

 //! Destructor
 public :
  ~MainDisplayWindow            ();

 //! Public Methods
 public :
  WindowHierarchy*              GetHierarchWindow       ();
  sqlite3*                      GetWindowDB             ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              ();
  void                          InitializeSubWindows    ();
  void                          CreateSubWindows        ();
  void                          PopulateHierarchyWindow ();
  static void                   ReadElementSlots        (WindowElement* InElement, sqlite3* InWindowDB);
  
  static int                    PopulateHierarchyWindowCB (void* InPointer,
                                                           int InColumnCount,
                                                           char** InColumnNames,
                                                           char** InColumnValues);
  static int                    ReadElementSlotsCB        (void* InPointer,
                                                           int InColumnCount,
                                                           char** InColumnNames,
                                                           char** InColumnValues);
 //! Private Data
 private :
  WindowHierarchy*              hierarchyWindow;
  SignalSlotWindow*             signalSlotWindow;
  QString                       filename;
  sqlite3*                      windowsdb;
  
 //! Public Slots
 public slots :
  void                          SlotSelectHierarchyWindow ();
  void                          SlotSelectSignalSlotWindow ();

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _maindisplaywindow_h_*/
