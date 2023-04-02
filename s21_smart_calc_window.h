#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "s21_plotwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  PlotWindow *plotWindow;
  bool isNumeric(QString str);
  bool isNumericInt(QString str);

 private slots:
  void CalculateButtonPressed();
  void CreditCalcButtonPressed();
  void on_actionSmartCalc_triggered();
  void on_actionCredit_triggered();
};
#endif  // MAINWINDOW_H
