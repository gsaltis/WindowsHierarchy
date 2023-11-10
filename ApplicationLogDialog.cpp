/*****************************************************************************
 * FILE NAME    : ApplicationLogDialog.cpp
 * DATE         : November 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <QSettings>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ApplicationLogDialog.h"
#include "ApplicationConfiguration.h"

/*****************************************************************************!
 * Function : ApplicationLogDialog
 *****************************************************************************/
ApplicationLogDialog::ApplicationLogDialog
() : QDialog()
{
  Initialize();
  Populate();
}

/*****************************************************************************!
 * Function : ~ApplicationLogDialog
 *****************************************************************************/
ApplicationLogDialog::~ApplicationLogDialog
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
ApplicationLogDialog::Initialize(void)
{
  CreateSubWindows();  
  CreateConnections();
  resize(APPLICATION_LOG_DIALOG_WIDTH, APPLICATION_LOG_DIALOG_HEIGHT);
}

/*****************************************************************************!
 * Function : Populate
 *****************************************************************************/
void
ApplicationLogDialog::Populate
()
{
  ApplicationLogEntry*                  entry;
  ApplicationLog*                       log = ApplicationConfiguration::MainApplicationLog;
  int                                   n = log->GetCount();
  int                                   i;
  
  for ( i = 0 ; i < n; i++) {
    entry = log->GetEntryByIndex(i);
    scrollWindow->AddEntry(entry);
  }
  scrollWindow->ResizeEntryWindow();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
ApplicationLogDialog::CreateConnections(void)
{
  connect(OKButton, SIGNAL(pressed()), this, SLOT(SlotOKButtonPressed()));  
  connect(CancelButton, SIGNAL(pressed()), this, SLOT(SlotCancelButtonPressed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ApplicationLogDialog::CreateSubWindows(void)
{
  int                                   buttonHeight;
  int                                   buttonGap;
  int                                   cancelButtonX;
  int                                   okButtonX;
  int                                   buttonY;
  int                                   cancelButtonWidth;
  int                                   okButtonWidth;
  
  okButtonWidth = 40;
  cancelButtonWidth = 60;
  buttonGap = 5;
  buttonHeight = 20;
  okButtonX = APPLICATION_LOG_DIALOG_WIDTH - (okButtonWidth + cancelButtonWidth + (2 * buttonGap));
  cancelButtonX = APPLICATION_LOG_DIALOG_WIDTH - (cancelButtonWidth + buttonGap);
  buttonY = APPLICATION_LOG_DIALOG_HEIGHT - (buttonGap + buttonHeight);
 
  OKButton = new QPushButton();
  OKButton->setParent(this);
  OKButton->setText("OK");
  OKButton->move(okButtonX, buttonY);
  OKButton->resize(okButtonWidth, buttonHeight);
  
  CancelButton = new QPushButton();
  CancelButton->setParent(this);
  CancelButton->setText("Cancel");
  CancelButton->move(cancelButtonX, buttonY);
  CancelButton->resize(cancelButtonWidth, buttonHeight);

  scrollWindow = new ApplicationLogDialogScrollWindow(ApplicationConfiguration::MainApplicationLog);
  scrollWindow->setParent(this);
}

/*****************************************************************************!
 * Function : SlotOKButtonPressed
 *****************************************************************************/
void
ApplicationLogDialog::SlotOKButtonPressed()
{
  accept();
}

/*****************************************************************************!
 * Function : SlotCancelButtonPressed
 *****************************************************************************/
void
ApplicationLogDialog::SlotCancelButtonPressed()
{
  reject();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ApplicationLogDialog::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size = InEvent->size();
  int                                   width;
  int                                   height;
  int                                   scrollWindowX;
  int                                   scrollWindowY;
  int                                   scrollWindowW;
  int                                   scrollWindowH;
  int                                   okbuttonX;
  int                                   okbuttonY;
  int                                   okbuttonW;
  int                                   okbuttonH;
  int                                   cancelButtonX;
  int                                   cancelButtonY;
  int                                   cancelButtonW;
  int                                   cancelButtonH;
  
  width = size.width();
  height = size.height();
  
  okbuttonW = OKButton->size().width();
  okbuttonH = OKButton->size().height();

  cancelButtonW = CancelButton->size().width();
  cancelButtonH = CancelButton->size().height();

  cancelButtonY = height - 30;
  cancelButtonX = width - (cancelButtonW + 10);

  okbuttonY = height - 30;
  okbuttonX = cancelButtonX - (okbuttonW + 10);
  
  scrollWindowX = 10;
  scrollWindowY = 10;
  scrollWindowW = width - 20;
  scrollWindowH = okbuttonY - 20;

  scrollWindow->resize(scrollWindowW, scrollWindowH);
  scrollWindow->move(scrollWindowX, scrollWindowY);

  OKButton->move(okbuttonX, okbuttonY);
  OKButton->resize(okbuttonW, okbuttonH);

  CancelButton->move(cancelButtonX, cancelButtonY);
  CancelButton->resize(cancelButtonW, cancelButtonH);
}

/*****************************************************************************!
 * Function : closeEvent
 *****************************************************************************/
void
ApplicationLogDialog::closeEvent
(QCloseEvent*)
{
  SaveSettings();
}

/*****************************************************************************!
 * Function : SaveSettings
 *****************************************************************************/
void
ApplicationLogDialog::SaveSettings
()
{
  QSettings                             settings(ApplicationConfiguration::OrganizationName,
                                                 ApplicationConfiguration::ApplicationName);
  int                                   x;
  int                                   y;
  int                                   width;
  int                                   height;
  
  settings.beginGroup("ApplicationLogDialog");
  x = settings.value("X").toInt();
  y = settings.value("Y").toInt();
  width = settings.value("Width").toInt();
  height = settings.value("Height").toInt();
  move(x, y);
  resize(width, height);
  settings.endGroup();
 
}
/*****************************************************************************!
 * Function : ReadSettings
 *****************************************************************************/
void
ApplicationLogDialog::ReadSettings
()
{
  QSettings                             settings(ApplicationConfiguration::OrganizationName,
                                                 ApplicationConfiguration::ApplicationName);
  int                                   x;
  int                                   y;
  int                                   width;
  int                                   height;
  
  settings.beginGroup("ApplicationLogDialog");
  x = settings.value("X").toInt();
  y = settings.value("Y").toInt();
  width = settings.value("Width").toInt();
  height = settings.value("Height").toInt();
  move(x, y);
  resize(width, height);
  settings.endGroup();
}





















