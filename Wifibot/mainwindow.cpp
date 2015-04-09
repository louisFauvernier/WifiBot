#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    co = new Communication(this);
    timer = new QTimer();
    timer->setInterval(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();

    ui->mainToolBar->addWidget(ui->battery);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow *MainWindow::getUI()
{
    return this->ui;
}


void MainWindow::on_buttonForeward_pressed()
{
    this->foreward = true;
}
void MainWindow::on_buttonForeward_released()
{
    this->foreward = false;
}
void MainWindow::on_buttonRight_pressed()
{
    this->right = true;
}
void MainWindow::on_buttonRight_released()
{
    this->right = false;
}

void MainWindow::on_buttonLeft_pressed()
{
    this->left = true;
}

void MainWindow::on_buttonLeft_released()
{
    this->left = false;
}

void MainWindow::on_buttonBackward_pressed()
{
    this->backward = true;
}

void MainWindow::on_buttonBackward_released()
{
    this->backward = false;
}

void MainWindow::on_actionQuitter_triggered()
{
    exit(0);
}

void MainWindow::on_buttonConnect_triggered()
{
        Connexion* conn = new Connexion(this, co);

        // Accepted
        if (conn->exec() == 1)
        {
            QMessageBox::information(this, "Connexion","Connexion réussi",QMessageBox::Ok);
        }
        // Refused
        else
        {
            QMessageBox::warning(this, "Connexion","Connexion impossible", QMessageBox::Ok);
        }
}

void MainWindow::update(){
    co->vitesse = ui->vitesse->value();
    if(co->connecte == true){
        ui->battery->setValue(co->battery);
        ui->ir_avant->setChecked(co->cpt_ir1<0);
        ui->ir_arriere->setChecked(co->cpt_ir2<0);
    }
    co->foreward = this->foreward;
    co->backward = this->backward;
    co->left = this->left;
    co->right = this->right;
}
