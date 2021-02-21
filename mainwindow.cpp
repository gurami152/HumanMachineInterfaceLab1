#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double res = 0;
    QString formula = "";
    QString  x = ui->lineEdit->text();
    if(ui->radioButton->isChecked()){
        formula = "y=5^(1+x^2) - 5^(1-x^2)";
        res = qPow(5,1+qPow(x.toDouble(),2))-qPow(5,1-qPow(x.toDouble(),2));
    }
    else if (ui->radioButton_2->isChecked()) {
        formula = "1+(1/1-sin^-1(2x+(8PI)/13))";
        res = 1+(1/(1-qPow(qSin(2*x.toDouble()+((8*M_PI)/13)),-1)));
    }
    QMessageBox::about(this, "Результат","Результат обчислення формули "+formula+" в точці " +x+" = "+QString::number(res));
    ui->label_2->setNum(res);
}
