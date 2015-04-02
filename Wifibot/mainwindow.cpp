#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

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

void MainWindow::Connexion(){
    QString port = ui->port->text();
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << "Connexion à " << ui->adIP->text() << ":" << port << endl;
    connexion.connectToHost(ui->adIP->text(), port.toInt());
    if(connexion.waitForConnected(5000)){
        cout << "Connecté" << endl;
        ui->buttonConnect->setText("Déconnecter");
        this->connecte = true;
    }
    else{
        cout << "Echec de la connexion" << endl;
        this->connecte = false;
    }
}
void MainWindow::Deconnexion(){
    connexion.disconnectFromHost();
    ui->buttonConnect->setText("Connecter");
    this->connecte = false;
}
void MainWindow::GenMessage(){
    buf.clear();
    buf.append((char)0xff);
    buf.append((char)0x07);
    buf.append((char)ui->vitesse->value());
    buf.append((char)0x00);
    buf.append((char)ui->vitesse->value());
    buf.append((char)0x00);
    //avant / avant
    buf.append((char)0b01010000);
    //arrière / avant
    //buf.append((char)0b00010000);
    //avant / arrière
    //buf.append((char)0b01000000);
    //arrière / arrière
    //buf.append((char)0b00000000);
    quint16 crc = this->crc16(buf, 1);
    buf.append((char)crc);
    buf.append((char)(crc>>8));
}
void MainWindow::sendMessage(){
    connexion.write(buf);
    connexion.flush();
}

void MainWindow::recvMessage(){
    char recv[21];
    connexion.read(recv, 21);
    int i;
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << (-(int) recv[2]) << endl;
    cout << ( (int) recv[3]) << endl;
    cout << ( (int) recv[4]) << endl;
    cout << endl;
}

void MainWindow::on_buttonConnect_triggered()
{
    this->Connexion();
    if(this->connecte == true){
        int i;
        QTextStream cout(stdout, QIODevice::WriteOnly);
        cout << "envoie" << endl;
        for(i=0;i<50;i++){
            ui->vitesse->setValue(ui->vitesse->value()+1);
            this->GenMessage();
            this->sendMessage();
            this->recvMessage();
            usleep(100000);
        }
        this->Deconnexion();
        cout << "Déconnecté" << endl;
     }
}
quint16 MainWindow::crc16(QByteArray byteArray, int pos){
    unsigned char *data = (unsigned char* )byteArray.constData();
    quint16 crc = 0xFFFF;
    quint16 Polynome = 0xA001;
    quint16 Parity = 0;
    for(; pos < byteArray.length(); pos++){
        crc ^= *(data+pos);
        for (unsigned int CptBit = 0; CptBit <= 7 ; CptBit++){
            Parity= crc;
            crc >>= 1;
            if (Parity%2 == true) crc ^= Polynome;
        }
    }
    return crc;
}
