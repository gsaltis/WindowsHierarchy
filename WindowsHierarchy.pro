QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

QMAKE_LFLAGS_WINDOWS            += -mwindows
#QMAKE_LFLAGS_WINDOWS           += -Wl,--subsystem,console

QMAKE_CXXFLAGS                  += 

QMAKE_CFLAGS                    += -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-implicit-fallthrough

QMAKE_LIBS                      = -lwsock32

TARGET                          = WindowsHierarchy

VERSION                         = "0.0.0"
QMAKE_TARGET_COMPANY            = "Greg Saltis"

QMAKE_TARGET_PRODUCT            = "WindowsHierarchy"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2023 Greg Saltis"

RESOURCES                       += WindowsHierarchy.qrc

QT                              += core gui widgets

DEFINES                         += \

SOURCES                         += \
				   ApplicationConfiguration.cpp                 \
				   ApplicationLog.cpp                           \
				   ApplicationLogDialog.cpp                     \
				   ApplicationLogDialogScrollWindow.cpp         \
				   ApplicationLogDialogWindow.cpp               \
				   ApplicationLogDisplayWindowElement.cpp       \
				   ApplicationLogEntry.cpp                      \
				   MainDisplayWindow.cpp                        \
				   MainWindow.cpp                               \
				   SignalSlotContainer.cpp                      \
				   SignalSlotWindow.cpp                         \
				   SignalSlotWindowScrollArea.cpp               \
				   SystemConfig.cpp                             \
				   WindowElement.cpp                            \
				   WindowElementList.cpp                        \
				   WindowElementSignal.cpp                      \
				   WindowElementSignalSlot.cpp                  \
				   WindowElementSlot.cpp                        \
				   WindowHierarchy.cpp                          \
				   WindowHierarchyContainer.cpp                 \
				   WindowHierarchyContainerElement.cpp          \
				   WindowHierarchyScrollArea.cpp                \
				   main.cpp                                     \
				   sqlite3.c                                    \
                                   trace.cpp                                    \

HEADERS                         += \
				   ApplicationConfiguration.h                   \
				   ApplicationLog.h                             \
				   ApplicationLogDialog.h                       \
				   ApplicationLogDialogScrollWindow.h           \
				   ApplicationLogDialogWindow.h                 \
				   ApplicationLogDisplayWindowElement.h         \
				   ApplicationLogEntry.h                        \
				   MainDisplayWindow.h                          \
				   MainWindow.h                                 \
				   SignalSlotContainer.h                        \
				   SignalSlotWindow.h                           \
				   SignalSlotWindowScrollArea.h                 \
				   SystemConfig.h                               \
				   WindowElement.h                              \
				   WindowElementList.h                          \
				   WindowElementSignal.h                        \
				   WindowElementSignalSlot.h                    \
				   WindowElementSlot.h                          \
				   WindowHierarchy.h                            \
				   WindowHierarchyContainer.h                   \
				   WindowHierarchyContainerElement.h            \
				   WindowHierarchyScrollArea.h                  \
				   sqlite3.h                                    \
                                   trace_winnet.h                               \

FORMS                           += \

QMAKE_EXTRA_TARGETS             += junkclean
junkclean.target                = junkclean
junkclean.commands              = @echo Removing junk                           \
                                  && rm -rf $(wildcard core* *~)
junkclean.depends               = 

QMAKE_EXTRA_TARGETS             += cleanall
cleanall.target                 = cleanall
cleanall.commands               = 
cleanall.depends                = junkclean                                     \
                                  clean
