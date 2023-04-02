#include "s21_plotwindow.h"
#include "ui_s21_plotwindow.h"

extern "C" {
#include "s21_shunting_yard.h"
}
      /**
       * Constructor of th PlotWindow that displays plots in clac mode. Only one object of PlotWindow is created so that state of the plot could be saved.
       *
       */
PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    ui->setupUi(this);
    h = 0.01;
    xBegin = -10;
    xEnd = 10+h;

}

      /**
       * This method only used only when there is correct expression containing x
       * @param expr Expression that will be displayed as plot
       */
void PlotWindow::plotExpression(std::string expr) {
    x.clear();
    y.clear();
    expression = expr;

    double y_val = 0;

    ui->widget->xAxis->setRange(xBegin, xEnd);
    ui->widget->yAxis->setRange(xBegin, xEnd);

    N = (xEnd - xBegin)/h + 2;

    for(X = xBegin; X < xEnd; X+=h) {
            parse((char *)expr.c_str(), X, &y_val);
            x.push_back(X);
            y.push_back(y_val);
    }
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

      /**
       * This method used in rescaling plot using keyboard input
       * @param expr Expression that will be displayed as plot
       */
void PlotWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        if ( xBegin <= -10 ) {
            xBegin-=10;
            xEnd+=10;
        } else {
            xBegin-=0.1;
            xEnd+=0.1;
        }
    } else if (event->key() == Qt::Key_Down) {
        if ( xBegin < -10 ) {
            xBegin+=10;
            xEnd-=10;
        } else if ( xBegin < -0.1 ) {
            xBegin+=0.1;
            xEnd-=0.1;
        }
    }
    if ( xBegin < -100 ) {
        h = 0.1;
    } else if ( xBegin < -1000 ) {
        h = 1;
    } else if ( xBegin < -5000 ) {
        h = 10;
    } else if ( xBegin < -10000 ) {
        h = 100;
    } else {
        h = 0.01;
    }
    plotExpression(expression);
}

PlotWindow::~PlotWindow()
{

    delete ui;
}
