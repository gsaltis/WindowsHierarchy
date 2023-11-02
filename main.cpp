/*****************************************************************************
 FILE NAME      : main.cpp
 DATE           : November 01 2023
 PROJECT        : WindowsHierarchy
 COPYRIGHT      : Copyright (C) 2023 by Gregory R Saltis
******************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QtGui>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "ApplicationLog.h"
#include "main.h"
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  QApplication 				application(argc, argv);
  MainWindow* 				w;
  ApplicationLog*                       log = new ApplicationLog();

  ApplicationConfiguration::MainApplicationLog = log;
  application.setApplicationName(ApplicationConfiguration::ApplicationName);
  application.setApplicationVersion("0.0.0");
  application.setOrganizationName(ApplicationConfiguration::OrganizationName);
  application.setOrganizationDomain(ApplicationConfiguration::OrganizationURL);

  log->AddEntry("Initialize");
  w = new MainWindow("Windows.txt");
  w->show();
  
  return application.exec();
}
