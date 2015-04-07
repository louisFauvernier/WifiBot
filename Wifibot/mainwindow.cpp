#include "mainwindow.h"
#include "ui_mainwindow.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
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
    if(co->connecte == true){
        co->Deconnexion();
        ui->buttonConnect->setText("Connecter");
        ui->battery->setValue(0);
    }
    else{
        co->adresse = ui->adIP->text();
        co->port = ui->port->text();
        co->Connexion();
        if(co->connecte){
            ui->buttonConnect->setText("Déconnecter");
        }
    }
}

void MainWindow::update(){
    co->vitesse = ui->vitesse->value();
    if(co->connecte == true){
        ui->battery->setValue(co->battery);
    }
    if(this->foreward == true)
        ui->forward_label->setText("True");
    else
        ui->forward_label->setText("False");
    if(this->backward == true)
        ui->backward_label->setText("True");
    else
        ui->backward_label->setText("False");
    if(this->left == true)
        ui->left_label->setText("True");
    else
        ui->left_label->setText("False");
    if(this->right == true)
        ui->right_label->setText("True");
    else
        ui->right_label->setText("False");
    co->foreward = this->foreward;
    co->backward = this->backward;
    co->left = this->left;
    co->right = this->right;
    ui->ir_avant->setChecked(co->cpt_ir1<0);
    ui->ir_arriere->setChecked(co->cpt_ir2<0);
}
