/********************************************************************************
** Form generated from reading UI file 's21_plotwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S21_PLOTWINDOW_H
#define UI_S21_PLOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PlotWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlotWindow)
    {
        if (PlotWindow->objectName().isEmpty())
            PlotWindow->setObjectName(QString::fromUtf8("PlotWindow"));
        PlotWindow->resize(800, 600);
        centralwidget = new QWidget(PlotWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        PlotWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlotWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        PlotWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PlotWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlotWindow->setStatusBar(statusbar);

        retranslateUi(PlotWindow);

        QMetaObject::connectSlotsByName(PlotWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlotWindow)
    {
        PlotWindow->setWindowTitle(QCoreApplication::translate("PlotWindow", "Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotWindow: public Ui_PlotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_PLOTWINDOW_H
