#include "mainwindow.h"
#include "ui_mainwindow.h"


// Constructor
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
    this->foreward = false;
    this->backward = false;
    this->left = false;
    this->right = false;
    initComponents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComponents()
{

    // mainToolBar

    battery = new QProgressBar();
    battery->setFormat("%p%");
    ui->mainToolBar->addWidget(battery);

    ui->mainToolBar->addSeparator();

    forewardSensor = new QRadioButton();
    forewardSensor->setText("Avant");
    backwardSensor = new QRadioButton();
    backwardSensor->setText("Arrière");
    ui->mainToolBar->addWidget(forewardSensor);
    ui->mainToolBar->addWidget(backwardSensor);

    ui->mainToolBar->addSeparator();

    // Camera
    //mediaPlayer = new QMediaPlayer(0, QMediaPlayer::VideoSurface);
    w = new Camera();
    videoWidget = new ViewerGl();
    ui->dockWidgetCamera->setVisible(false);
    ui->dockWidgetCamera->setWidget(videoWidget);
    //mediaPlayer->setVideoOutput(videoWidget);
    w->setVideoOutput(videoWidget);


    //connect(mediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(mediaStateChanged(QMediaPlayer::State)));
    //connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    //connect(mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
    //connect(mediaPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(handleError()));

    ui->dockWidgetCamera->setMinimumHeight(325);


    setInterfaceEnabled(false);
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

/** KEYBOARD **/
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(co->connecte){
        if(event->key() == Qt::Key_Z){
            ui->buttonForeward->setIcon(QIcon(":/foreward_enable.png"));
            this->foreward = true;
        }
        else if(event->key() == Qt::Key_Q){
            ui->buttonLeft->setIcon(QIcon(":/left_enable.png"));
            this->left = true;
        }
        else if(event->key() == Qt::Key_S){
            ui->buttonBackward->setIcon(QIcon(":/backward_enable.png"));
            this->backward = true;
        }
        else if(event->key() == Qt::Key_D){
            ui->buttonRight->setIcon(QIcon(":/right_enable.png"));
            this->right = true;
        }
        else if(event->key() == Qt::Key_R){
            QUrl url("http://"+co->adresse+":8080/?action=command&dest=0&plugin=0&id=10094855&group=1&value=1");
            co->camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_A){
            ui->vitesse->setValue(ui->vitesse->value() + 10);
        }
        else if(event->key() == Qt::Key_E){
            ui->vitesse->setValue(ui->vitesse->value() - 10);
        }
        else if(event->key() == Qt::Key_O){
            QUrl url("http://"+ co->adresse +":8080" + cameraup);
            co->camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_L){
            QUrl url("http://"+ co->adresse +":8080" + cameradown);
            co->camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_K){
            QUrl url("http://"+ co->adresse +":8080" + cameraleft);
            co->camera->get(QNetworkRequest(url));
        }
        else if(event->key() == Qt::Key_M){
            QUrl url("http://"+ co->adresse +":8080" + cameraright);
            co->camera->get(QNetworkRequest(url));
        }
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(co->connecte){
        if(event->key() == Qt::Key_Z){
            ui->buttonForeward->setIcon(QIcon(":/foreward_disable.png"));
            this->foreward = false;
        }
        else if(event->key() == Qt::Key_Q){
            ui->buttonLeft->setIcon(QIcon(":/left_disable.png"));
            this->left = false;
        }
        else if(event->key() == Qt::Key_S){
            ui->buttonBackward->setIcon(QIcon(":/backward_disable.png"));
            this->backward = false;
        }
        else if(event->key() == Qt::Key_D){
            ui->buttonRight->setIcon(QIcon(":/right_disable.png"));
            this->right = false;
        }
    }
}

/** CAMERA **/

void MainWindow::on_buttonCamera_clicked()
{
    if (co->webcam)
    {
        ui->buttonCamera->setIcon(QIcon(":/robot.png"));
        co->webcam = false;
        ui->dockWidgetCamera->setVisible(true);
    }
    else
    {
        ui->buttonCamera->setIcon(QIcon(":/camera.png"));
        co->webcam = true;

        //mediaPlayer->setMedia(QUrl("http://192.168.1.106:8080/?action=stream"));

        //mediaPlayer->mediaStream()

        /*
        cv::VideoCapture capture(url);

        if (!capture->isOpened()) {
            //Error
        }*/


        this->resize(400, 600);
        /*

        switch(mediaPlayer->state()) {
        case QMediaPlayer::PlayingState:
            mediaPlayer->pause();
            break;
        default:
            mediaPlayer->play();
            break;
        }

        */
        ui->dockWidgetCamera->setVisible(true);

        w->start();

    }
}

/** MENU ACTIONS **/


// Exit
void MainWindow::on_actionQuitter_triggered()
{
    exit(0);
}


// Connexion
void MainWindow::on_actionConnexion_triggered()
{
    Connexion* conn = new Connexion(this, co);

    // Accepted
    if (conn->exec() == 1)
    {
        QMessageBox::information(this, "Connexion","Connexion réussi", QMessageBox::Ok);
        setInterfaceEnabled(true);
    }
    // Refused
    else
    {
        QMessageBox::warning(this, "Connexion","Connexion impossible", QMessageBox::Ok);
        setInterfaceEnabled(false);
    }
}

void MainWindow::on_actionDeconnexion_triggered()
{
    co->Deconnexion();
    QMessageBox::information(this, "Deconnexion","Deconnexion réussi", QMessageBox::Ok);
    setInterfaceEnabled(false);
}


/** OTHER **/

// Get the user interface
Ui::MainWindow *MainWindow::getUI()
{
    return this->ui;
}

void MainWindow::update(){
    co->vitesse = ui->vitesse->value();
    if(co->connecte == true){
        battery->setValue(co->battery);
        forewardSensor->setChecked(co->cpt_ir1<0);
        backwardSensor->setChecked(co->cpt_ir2<0);
    }
    co->foreward = this->foreward;
    co->backward = this->backward;
    co->left = this->left;
    co->right = this->right;
}

void MainWindow::setInterfaceEnabled(bool b){
    ui->actionConnexion->setEnabled(!b);
    ui->actionDeconnexion->setEnabled(b);
    ui->buttonForeward->setEnabled(b);
    ui->buttonBackward->setEnabled(b);
    ui->buttonLeft->setEnabled(b);
    ui->buttonRight->setEnabled(b);
    //ui->buttonCamera->setEnabled(b);
    ui->vitesse->setEnabled(b);
    ui->mainToolBar->setVisible(b);
}
