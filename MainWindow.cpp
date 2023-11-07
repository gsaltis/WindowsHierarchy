/*****************************************************************************
 * FILE NAME    : MainWindow.cpp
 * DATE         : November 01 2023
 * PROJECT      : WindowsHierarchy
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMenuBar>
#include <QStatusBar>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "ApplicationLogDialog.h"
#include "ApplicationConfiguration.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : MainWindow
 *****************************************************************************/
MainWindow::MainWindow
(QString InFilename) : QMainWindow(NULL)
{
  filename = InFilename;
  Initialize();
  CreateActions();
  CreateMenus();
  InitializeSubWindows();
  CreateSubWindows();
  CreateConnections();
  ReadSettings();
}

/*****************************************************************************!
 * Function : ~MainWindow
 *****************************************************************************/
MainWindow::~MainWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainWindow::Initialize()
{
  setWindowIcon(QIcon(":/Images/MainWindowIcon.png"));
  setWindowTitle(SystemConfig::SystemName);  
}

/*****************************************************************************!
 * Function : CreateSubWindows
 * Purpose  : Create Sub Windows
 *****************************************************************************/
void
MainWindow::CreateSubWindows()
{
  displayWindow = new MainDisplayWindow(filename);
  displayWindow->setParent(this);
  statusbar = statusBar();
  ApplicationConfiguration::StatusBar = statusbar;
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 * Purpose  : Create Sub Windows
 *****************************************************************************/
void
MainWindow::InitializeSubWindows()
{
  displayWindow = NULL;
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainWindow::CreateConnections
()
{
  connect(this,
          SIGNAL(SignalSelectHierarchyWindow()),
          displayWindow,
          SLOT(SlotSelectHierarchyWindow()));

  connect(this,
          SIGNAL(SignalSelectSignalSlotWindow()),
          displayWindow,
          SLOT(SlotSelectSignalSlotWindow()));
}

/*****************************************************************************!
 * Function : resizeEvent
 * Purpose  : Handle Resize Event
 *****************************************************************************/
void
MainWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   width;
  int                                   height;
  QSize                                 size;
  QSize                                 statusbar_size;
  QSize                                 menu_size;
  size = InEvent->size();  
  menu_size = menubar->size();
  statusbar_size = statusbar->size();
  width = size.width();
  height = size.height() - (menu_size.height() + statusbar_size.height());
  if ( displayWindow ) {
    displayWindow->move(0, menu_size.height());
    displayWindow->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : CreateActions
 * Purpose  : Create New Actions
 *****************************************************************************/
void
MainWindow::CreateActions()
{
  ActionExit = new QAction("E&xit", this);
  connect(ActionExit, SIGNAL(triggered()), this, SLOT(SlotExit()));
  ActionShowApplicationLog = new QAction("Log", this);
  connect(ActionShowApplicationLog, SIGNAL(triggered()), this, SLOT(SlotShowApplicationLog()));

  ActionSelectHierarchyWindow = new QAction("Hierarchy Window", this);
  ActionSelectHierarchyWindow->setCheckable(true);
  ActionSelectHierarchyWindow->setChecked(true);
  
  connect(ActionSelectHierarchyWindow, SIGNAL(triggered()), this, SLOT(SlotSelectHierarchyWindow()));

  ActionSelectSignalSlotWindow = new QAction("Slot/Signal Window", this);
  connect(ActionSelectSignalSlotWindow, SIGNAL(triggered()), this, SLOT(SlotSelectSignalSlotWindow()));
  ActionSelectSignalSlotWindow->setCheckable(true);
  ActionSelectSignalSlotWindow->setChecked(false);
}

/*****************************************************************************!
 * Function : CreateMenus
 * Purpose  : Create New Menus
 *****************************************************************************/
void
MainWindow::CreateMenus()
{
  menubar = menuBar();  
  fileMenu = menubar->addMenu("&File");
  fileMenu->addAction(ActionExit);
  windowMenu = menubar->addMenu("&Windows");
  windowMenu->addAction(ActionShowApplicationLog);
  windowMenu->addSeparator();
  windowMenu->addAction(ActionSelectHierarchyWindow);
  windowMenu->addAction(ActionSelectSignalSlotWindow);
}

/*****************************************************************************!
 * Function : closeEvent
 *****************************************************************************/
void
MainWindow::closeEvent
(QCloseEvent* InEvent)
{
  QSettings                             settings(ApplicationConfiguration::OrganizationName,
                                                 ApplicationConfiguration::ApplicationName);
  settings.beginGroup("MainWindow");
  settings.setValue("X", pos().x());
  settings.setValue("Y", pos().y());
  settings.setValue("Width", size().width());
  settings.setValue("Height", size().height());
  settings.endGroup();
  QMainWindow::closeEvent(InEvent);
}

/*****************************************************************************!
 * Function : ReadSettings
 *****************************************************************************/
void
MainWindow::ReadSettings
()
{
  QSettings                             settings(ApplicationConfiguration::OrganizationName,
                                                 ApplicationConfiguration::ApplicationName);
  int                                   x;
  int                                   y;
  int                                   width;
  int                                   height;
  
  settings.beginGroup("MainWindow");
  x = settings.value("X").toInt();
  y = settings.value("Y").toInt();
  width = settings.value("Width").toInt();
  height = settings.value("Height").toInt();
  move(x, y);
  resize(width, height);
  settings.endGroup();
}

/*****************************************************************************!
 * Function : SlotExit
 *****************************************************************************/
void
MainWindow::SlotExit(void)
{
  exit(EXIT_SUCCESS);  
}

/*****************************************************************************!
 * Function : SlotShowApplicationLog
 *****************************************************************************/
void
MainWindow::SlotShowApplicationLog(void)
{
  ApplicationLogDialog*                 dialog;

  dialog = new ApplicationLogDialog();
  dialog->exec();
  delete dialog;
}

/*****************************************************************************!
 * Function : SlotSelectHierarchyWindow
 *****************************************************************************/
void
MainWindow::SlotSelectHierarchyWindow(void)
{
  ActionSelectHierarchyWindow->setChecked(true);
  ActionSelectSignalSlotWindow->setChecked(false);
  emit SignalSelectHierarchyWindow();
}

/*****************************************************************************!
 * Function : SlotSelectSignalSlotWindow
 *****************************************************************************/
void
MainWindow::SlotSelectSignalSlotWindow(void)
{
  ActionSelectHierarchyWindow->setChecked(false);
  ActionSelectSignalSlotWindow->setChecked(true);
  emit SignalSelectSignalSlotWindow();
}
