/*****************************************************************************
 FILE NAME      : main.cpp
 DATE           : November 01 2023
 PROJECT        : WindowsHierarchy
 COPYRIGHT      : Copyright (C) 2023 by Gregory R Saltis
******************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include "trace_winnet.h"
#include <QtCore>
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QtGui>
#include <QCommandLineParser>
#include <QMessageBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "ApplicationLog.h"
#include "main.h"
#include "ApplicationConfiguration.h"
#include "sqlite3.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void
MainCreateNewDatabase
();

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
QString
MainFilename = "Windows.db";

static bool
MainCreateDatabase = false;

static bool
MainOverFileDatabase = false;

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  QStringList                           overwriteFileOptions;
  QApplication 				application(argc, argv);
  MainWindow* 				w;
  ApplicationLog*                       log = new ApplicationLog();
  QCommandLineParser                    parser;
  QStringList                           filenameOptions;
  QString                               st;
  QStringList                           createDatabaseOptions;

  TRACE_FUNCTION_START();
  ApplicationConfiguration::MainApplicationLog = log;
  application.setApplicationName(ApplicationConfiguration::ApplicationName);
  application.setApplicationVersion("0.0.0");
  application.setOrganizationName(ApplicationConfiguration::OrganizationName);
  application.setOrganizationDomain(ApplicationConfiguration::OrganizationURL);

  log->AddEntry("Initialize");

  parser.setApplicationDescription("Windows Hierarchy Viewer");
  parser.addHelpOption();
  parser.addVersionOption();

  filenameOptions << "f" << "file"; 
  QCommandLineOption filenameOption(filenameOptions,
		                    QString("Specify the input database filename"), 
				    QString("filename"));

  createDatabaseOptions << "c" << "createdatabase";
  QCommandLineOption createDatabaseOption(createDatabaseOptions, 
		                          QString("Create a new database"));
  overwriteFileOptions << "o" << "overwrite";
  QCommandLineOption overwriteFileOption(overwriteFileOptions,
                                         QString("Overwrite a database (when creating a new one)"));

  
  parser.addOption(filenameOption);
  parser.addOption(createDatabaseOption);
  parser.addOption(overwriteFileOption);

  parser.process(application); 
  st = parser.value(filenameOption);
  MainCreateDatabase = parser.isSet(createDatabaseOption);
  MainOverFileDatabase = parser.isSet(overwriteFileOption);
  
  if ( !st.isEmpty() ) {
    MainFilename = st;
  }

  if ( MainCreateDatabase ) {
    MainCreateNewDatabase();
    return EXIT_SUCCESS;
  }  

  w = new MainWindow(MainFilename);
  w->show();

  return application.exec();
}

/*****************************************************************************!
 * Function : MainCreateNewDatabase
 *****************************************************************************/
void
MainCreateNewDatabase
()
{
  QStringList                           sqlStatements;
  int                                   n;
  sqlite3*                              db;

  sqlStatements << "CREATE TABLE Windows (classid int, "
                                         "elementid int, "
                                         "parentid int, "
                                         "name text, "
                                         "transient int);\n"
                << "CREATE TABLE Classes (classid int, "
                                         "name text);\n"
	        << "CREATE TABLE Signals (classid int, "
                                         "signalid int, "
                                         "name string);\n"
		<< "CREATE TABLE Slots   (classid int, "
                                         "slotid int, "
                                         "name text);\n"
		<< "INSERT INTO Windows VALUES(0, 1, 0, 'main', 0);\n";

  QFileInfo				fileInfo(MainFilename);
  if ( ! MainOverFileDatabase ) {
    if ( fileInfo.exists() ) {
      QMessageBox				message(QMessageBox::Critical, "File Exists", QString("%1 exists").arg(MainFilename));
      message.exec();
      exit(EXIT_FAILURE);
    }
  } else {
    QFile::remove(MainFilename);
  }
  n = sqlite3_open(MainFilename.toStdString().c_str(), &db);
  if ( n != SQLITE_OK ) { 
    QMessageBox				message(QMessageBox::Critical, "Sqlite3 Error", QString("Error opening %1 database %2").arg(MainFilename, sqlite3_errstr(n)));
    message.exec();
    exit(EXIT_FAILURE);
  }

  for ( auto stmt : sqlStatements ) {
    n = sqlite3_exec(db, stmt.toStdString().c_str(), NULL, NULL, NULL);
    if ( n != SQLITE_OK ) { 
      QMessageBox			message(QMessageBox::Critical, "Sqlite3 Error", QString("Error opening %1 database %2").arg(MainFilename).arg(sqlite3_errstr(n)));
      message.exec();
      exit(EXIT_FAILURE);
    }
  }
  sqlite3_close(db);
}

