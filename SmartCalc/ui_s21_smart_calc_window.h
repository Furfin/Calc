/********************************************************************************
** Form generated from reading UI file 's21_smart_calc_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S21_SMART_CALC_WINDOW_H
#define UI_S21_SMART_CALC_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSmartCalc;
    QAction *actionCredit;
    QAction *actionDeposit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *SmartCalc;
    QLineEdit *CalcDisplay;
    QPushButton *CalculateButton;
    QLineEdit *ExpressionInput;
    QWidget *Credit;
    QLabel *label_2;
    QLineEdit *creditAmount;
    QLabel *label_3;
    QLineEdit *term;
    QComboBox *termBox;
    QLabel *label_4;
    QLineEdit *interestRate;
    QRadioButton *anButton;
    QRadioButton *diffButton;
    QLabel *label_5;
    QPushButton *creditCalcButton;
    QTextEdit *creditOutput;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menumode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(847, 862);
        actionSmartCalc = new QAction(MainWindow);
        actionSmartCalc->setObjectName(QString::fromUtf8("actionSmartCalc"));
        actionCredit = new QAction(MainWindow);
        actionCredit->setObjectName(QString::fromUtf8("actionCredit"));
        actionDeposit = new QAction(MainWindow);
        actionDeposit->setObjectName(QString::fromUtf8("actionDeposit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        SmartCalc = new QWidget();
        SmartCalc->setObjectName(QString::fromUtf8("SmartCalc"));
        CalcDisplay = new QLineEdit(SmartCalc);
        CalcDisplay->setObjectName(QString::fromUtf8("CalcDisplay"));
        CalcDisplay->setGeometry(QRect(0, 3, 782, 291));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalcDisplay->sizePolicy().hasHeightForWidth());
        CalcDisplay->setSizePolicy(sizePolicy);
        CalcDisplay->setMouseTracking(false);
        CalcDisplay->setReadOnly(true);
        CalculateButton = new QPushButton(SmartCalc);
        CalculateButton->setObjectName(QString::fromUtf8("CalculateButton"));
        CalculateButton->setGeometry(QRect(702, 300, 80, 25));
        ExpressionInput = new QLineEdit(SmartCalc);
        ExpressionInput->setObjectName(QString::fromUtf8("ExpressionInput"));
        ExpressionInput->setGeometry(QRect(0, 300, 696, 25));
        stackedWidget->addWidget(SmartCalc);
        Credit = new QWidget();
        Credit->setObjectName(QString::fromUtf8("Credit"));
        label_2 = new QLabel(Credit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 141, 31));
        creditAmount = new QLineEdit(Credit);
        creditAmount->setObjectName(QString::fromUtf8("creditAmount"));
        creditAmount->setGeometry(QRect(160, 10, 113, 25));
        label_3 = new QLabel(Credit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 40, 41, 31));
        term = new QLineEdit(Credit);
        term->setObjectName(QString::fromUtf8("term"));
        term->setGeometry(QRect(160, 50, 113, 25));
        termBox = new QComboBox(Credit);
        termBox->addItem(QString());
        termBox->addItem(QString());
        termBox->setObjectName(QString::fromUtf8("termBox"));
        termBox->setGeometry(QRect(290, 50, 86, 25));
        label_4 = new QLabel(Credit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 90, 91, 31));
        interestRate = new QLineEdit(Credit);
        interestRate->setObjectName(QString::fromUtf8("interestRate"));
        interestRate->setGeometry(QRect(160, 90, 113, 25));
        anButton = new QRadioButton(Credit);
        anButton->setObjectName(QString::fromUtf8("anButton"));
        anButton->setGeometry(QRect(160, 150, 112, 23));
        diffButton = new QRadioButton(Credit);
        diffButton->setObjectName(QString::fromUtf8("diffButton"));
        diffButton->setGeometry(QRect(160, 170, 121, 23));
        label_5 = new QLabel(Credit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 120, 41, 31));
        creditCalcButton = new QPushButton(Credit);
        creditCalcButton->setObjectName(QString::fromUtf8("creditCalcButton"));
        creditCalcButton->setGeometry(QRect(170, 220, 89, 25));
        creditOutput = new QTextEdit(Credit);
        creditOutput->setObjectName(QString::fromUtf8("creditOutput"));
        creditOutput->setGeometry(QRect(410, 10, 301, 261));
        creditOutput->setReadOnly(true);
        stackedWidget->addWidget(Credit);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 847, 22));
        menumode = new QMenu(menuBar);
        menumode->setObjectName(QString::fromUtf8("menumode"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menumode->menuAction());
        menumode->addAction(actionSmartCalc);
        menumode->addAction(actionCredit);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc", nullptr));
        actionSmartCalc->setText(QCoreApplication::translate("MainWindow", "SmartCalc", nullptr));
        actionCredit->setText(QCoreApplication::translate("MainWindow", "Credit", nullptr));
        actionDeposit->setText(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        CalcDisplay->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        CalcDisplay->setPlaceholderText(QString());
        CalculateButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        ExpressionInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your expression here !", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Total credit amount:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Term:", nullptr));
        termBox->setItemText(0, QCoreApplication::translate("MainWindow", "Years", nullptr));
        termBox->setItemText(1, QCoreApplication::translate("MainWindow", "Months", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Interest rate:", nullptr));
        anButton->setText(QCoreApplication::translate("MainWindow", "Annuity", nullptr));
        diffButton->setText(QCoreApplication::translate("MainWindow", "Differentiated", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        creditCalcButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        menumode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_SMART_CALC_WINDOW_H
