/*****************************************************************************
 * FILE NAME    : ApplicationConfiguration.h
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _applicationconfiguration_h_
#define _applicationconfiguration_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QStatusBar>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ApplicationLog.h"
#include "WindowElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : ApplicationConfiguration
 *****************************************************************************/
class ApplicationConfiguration
{
 //! Constructors
 public :
  ApplicationConfiguration      ();

 //! Destructor
 public :
  ~ApplicationConfiguration     ();

 //! Public Methods
 public :

 //! Public Data
 public :
  static QString                OrganizationName;
  static QString                ApplicationName;
  static QString                OrganizationURL;
  static ApplicationLog*        MainApplicationLog;
  static QStatusBar*            StatusBar;
  static QList<WindowElement*>  WindowElements;
  
 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();

 //! Private Data
 private :
};

#endif /* _applicationconfiguration_h_*/
