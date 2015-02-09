#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_buttonTopward_pressed()
{

}

void MainWindow::on_buttonTopward_released()
{

}

void MainWindow::on_buttonRight_pressed()
{

}

void MainWindow::on_buttonRight_released()
{

}

void MainWindow::on_buttonbackward_pressed()
{

}

void MainWindow::on_buttonbackward_released()
{

}

void MainWindow::on_buttonLeft_pressed()
{

}

void MainWindow::on_buttonLeft_released()
{

}
