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

    initComponents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComponents()
{
    ui->mainToolBar->addWidget(ui->battery);

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(ui->ir_arriere);
    ui->mainToolBar->addWidget(ui->ir_avant);
    ui->mainToolBar->addSeparator();
}

Ui::MainWindow *MainWindow::getUI()
{
    return this->ui;
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

/** BUTTON DIRECTIONS **/


// Foreward
void MainWindow::on_buttonForeward_pressed()
{
    ui->buttonForeward->setIcon(QIcon(":/foreward_enable.png"));
    this->foreward = true;
}
void MainWindow::on_buttonForeward_released()
{
    ui->buttonForeward->setIcon(QIcon(":/foreward_disable.png"));
    this->foreward = false;
}

// Right
void MainWindow::on_buttonRight_pressed()
{
    ui->buttonRight->setIcon(QIcon(":/right_enable.png"));
    this->right = true;
}
void MainWindow::on_buttonRight_released()
{
    ui->buttonRight->setIcon(QIcon(":/right_disable.png"));
    this->right = false;
}


// Left
void MainWindow::on_buttonLeft_pressed()
{
    ui->buttonLeft->setIcon(QIcon(":/left_enable.png"));
    this->left = true;
}

void MainWindow::on_buttonLeft_released()
{
    ui->buttonLeft->setIcon(QIcon(":/left_disable.png"));
    this->left = false;
}

// Backward
void MainWindow::on_buttonBackward_pressed()
{
    ui->buttonBackward->setIcon(QIcon(":/backward_enable.png"));
    this->backward = true;
}

void MainWindow::on_buttonBackward_released()
{
    ui->buttonBackward->setIcon(QIcon(":/backward_disable.png"));
    this->backward = false;
}

/** CAMERA **/

void MainWindow::on_buttonCamera_clicked()
{
    if (co->webcam)
    {
        ui->buttonCamera->setIcon(QIcon(":/robot.png"));
        co->webcam = false;
    }
    else
    {
        ui->buttonCamera->setIcon(QIcon(":/camera.png"));
        co->webcam = true;
    }
}

/** MENU ACTIONS **/


// Exit
void MainWindow::on_actionQuitter_triggered()
{
    exit(0);
}


// Connection
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

void MainWindow::on_actionDeconnexion_triggered()
{
    co->Deconnexion();
    QMessageBox::information(this, "Deconnexion","Deconnexion réussi",QMessageBox::Ok);
}


