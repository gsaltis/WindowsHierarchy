/*****************************************************************************
 * FILE NAME    : ApplicationLogDialog.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _applicationlogdialog_h_
#define _applicationlogdialog_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QPushButton>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ApplicationLogDialogScrollWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define APPLICATION_LOG_DIALOG_WIDTH            800
#define APPLICATION_LOG_DIALOG_HEIGHT           400

/*****************************************************************************!
 * Exported Class : ApplicationLogDialog
 *****************************************************************************/
class ApplicationLogDialog : public QDialog
{
  Q_OBJECT;

 //! Constructors
 public :
  ApplicationLogDialog          ();

 //! Destructor
 public :
  ~ApplicationLogDialog         ();

 //! Public Methods
 public :

 //! Public Data
 public :

 //! Protected Methods
 protected :
  void                          resizeEvent             (QResizeEvent* InEvent);
  
 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              (void);
  void                          CreateConnections       (void);
  void                          CreateSubWindows        (void);
  void                          Populate                ();
  void                          closeEvent              (QCloseEvent* InEvent);
  void                          ReadSettings            ();
  void                          SaveSettings            ();
  
 //! Private Data
 private :
  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;
  ApplicationLogDialogScrollWindow* scrollWindow;
  
 //! Public Slots
 public slots :
  void                          SlotOKButtonPressed     ();
  void                          SlotCancelButtonPressed ();

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _applicationlogdialog_h_*/
