/*****************************************************************************
 * FILE NAME    : ApplicationConfiguration.cpp
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Static Data
 *****************************************************************************/
QString
ApplicationConfiguration::OrganizationName = "White Barn";

QString
ApplicationConfiguration::ApplicationName = "WindowsHierarchy";

QString
ApplicationConfiguration::OrganizationURL = "www.whitebarn.com";

ApplicationLog*
ApplicationConfiguration::MainApplicationLog = NULL;

QStatusBar*
ApplicationConfiguration::StatusBar = NULL;

QList<WindowElement*>
ApplicationConfiguration::WindowElements;

/*****************************************************************************!
 * Function : ApplicationConfiguration
 *****************************************************************************/
ApplicationConfiguration::ApplicationConfiguration
()
{

}

/*****************************************************************************!
 * Function : ~ApplicationConfiguration
 *****************************************************************************/
ApplicationConfiguration::~ApplicationConfiguration
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ApplicationConfiguration::initialize()
{
}

/*****************************************************************************!
 * Function : FindWindowElementByIDs
 *****************************************************************************/
WindowElement*
ApplicationConfiguration::FindWindowElementByIDs
(int InClassID, int InElementID)
{
  int                                   i;
  int                                   n;
  WindowElement*                        element;
  
  n = WindowElements.size();

  for ( i = 0 ; i < n ; i++ ) {
    element = WindowElements[i];
    if ( element->GetClassID() == InClassID && element->GetElementID() == InElementID ) {
      return element;
    }
  }
  return NULL;
}

