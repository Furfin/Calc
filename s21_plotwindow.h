#ifndef S21_PLOTWINDOW_H
#define S21_PLOTWINDOW_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit PlotWindow(QWidget *parent = nullptr);
  void plotExpression(std::string expr);
  ~PlotWindow();

 protected:
  void keyPressEvent(QKeyEvent *event);

 private:
  Ui::PlotWindow *ui;
  double xBegin, xEnd, h, X;
  int N;
  std::string expression;

  QVector<double> x, y;
};

#endif  // S21_PLOTWINDOW_H
