QT += core gui widgets
TEMPLATE = app
TARGET = QSpreadsheetHeaderView
DEPENDPATH += .
INCLUDEPATH += . ..

# Input
HEADERS += MainWindow.h ../QSpreadsheetHeaderView.h TableModel.h
SOURCES += MainWindow.cpp ../QSpreadsheetHeaderView.cpp TableModel.cpp
