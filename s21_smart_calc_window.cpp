#include "s21_smart_calc_window.h"
#include "./ui_s21_smart_calc_window.h"
#include "s21_plotwindow.h"

using namespace std;

extern "C" {
#include "s21_shunting_yard.h"
}

      /**
       * Constructor of class MainWindow. It displays all the apps.
       *
       */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->CalcDisplay->setText("");
    connect(ui->CalculateButton, SIGNAL(released()), this, SLOT(CalculateButtonPressed()));
    connect(ui->creditCalcButton, SIGNAL(released()), this, SLOT(CreditCalcButtonPressed()));
    plotWindow = new PlotWindow();
    ui->stackedWidget->setCurrentIndex(0);
    this->setFixedSize(800,400);

}

MainWindow::~MainWindow()
{
    delete ui;
}

      /**
       * This method is used when '=' button is pressed in Clac mode. It evaluates given expression and returns an Error if there was one;
       */
void MainWindow::CalculateButtonPressed() {
    QLineEdit* ExpressionContainer = ui->ExpressionInput;
    double answ;

    int status = parse((char *)ExpressionContainer->text().toStdString().c_str(), 0, &answ);

    if ( status == 0 && answ == answ) {
        ui->CalcDisplay->setText(QString::number(answ));
    } else if ( status == 2 ) {
        ui->CalcDisplay->setText("Here might have been your plot data but i am lazy !");
        plotWindow->plotExpression(ExpressionContainer->text().toStdString());
        plotWindow->show();
    } else {
        ui->CalcDisplay->setText("Error !");
    }
}
      /**
       * Helper method that check if string is numeric or not
       */
bool MainWindow::isNumeric(QString str) {
    bool status = true;
    if ( str.size() == 0 ) {
        status = false;
    }
    for (int i =0;i<str.size();i++) {
        if (!(str[i].isDigit()) && str[i] != '.') {
            status = false;
        }
    }
    return status;
}

      /**
       * Helper method that check if string is integer or not. Floating point numbers are not allowed
       */

bool MainWindow::isNumericInt(QString str) {
    bool status = true;
    if ( str.size() == 0 ) {
        status = false;
    }
    for (int i =0;i<str.size();i++) {
        if (!(str[i].isDigit())) {
            status = false;
        }
    }
    return status;
}

      /**
       * This method is used when 'Calculate' button is pressed in Credit mode. It computes all the statistics of credit and outputs them
       */
void MainWindow::CreditCalcButtonPressed() {
    double creditAmount;
    int termMonths;
    double percent;
    bool isDiff;
    if ( !isNumeric(ui->creditAmount->text()) || !isNumericInt(ui->term->text()) || !isNumeric(ui->interestRate->text()) || ( !ui->anButton->isChecked() && !ui->diffButton->isChecked())) {
        QMessageBox::warning(this, "Warning","All the fields must be filled with correct data");
    } else {
        creditAmount = ui->creditAmount->text().toDouble();
        if ( ui->termBox->currentText() == "Years" ) {
            termMonths = 12*ui->term->text().toInt();
        } else {
            termMonths = ui->term->text().toInt();
        }
        isDiff = ui->diffButton->isChecked();
        percent = ui->interestRate->text().toDouble()/(12*100);
        double d = creditAmount/termMonths;
        if ( percent <= 0 || termMonths <= 0 || creditAmount == 0 ) {
            QMessageBox::warning(this, "Warning","All the fields must be filled with correct data");
        } else if (!isDiff) {
            string output = "monthly payment:" + std::to_string(creditAmount*(percent/(1-pow(1+percent,-1*termMonths)))) +  "\n" + "overpaymanet:" +std::to_string((creditAmount*termMonths*percent/(1-pow(1+percent,-1*termMonths)))-creditAmount) +  "\n" + "total payment:" + std::to_string(creditAmount*termMonths*percent/(1-pow(1+percent,-1*termMonths)));
            ui->creditOutput->setText(QString::fromStdString(output));
        } else {
            double sum = 0;
            string output = "monthly payments:\n";
            for(int n = 1;n<=termMonths; n++) {
                sum+=d+(creditAmount - d*(n-1))*percent;
                output+= std::to_string(d+(creditAmount - d*(n-1))*percent) + "\n";

            }
            output += "overpaymanet:" +std::to_string(sum-creditAmount) +  "\n" + "total payment:" + std::to_string(sum);
            ui->creditOutput->setText(QString::fromStdString(output));
        }

    }
}


      /**
       * This method is used when user changes mode of the app. It also rescales window.
       */
void MainWindow::on_actionSmartCalc_triggered() {
    ui->stackedWidget->setCurrentIndex(0);
    this->setFixedSize(800,400);
}


      /**
       * This method is used when user changes mode of the app. It also rescales window.
       */
void MainWindow::on_actionCredit_triggered() {
    ui->stackedWidget->setCurrentIndex(1);
    this->setFixedSize(800,400);
}









