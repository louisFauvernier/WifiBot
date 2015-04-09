#include "communication.h"

Communication::Communication(QObject *parent) :
    QObject(parent)
{
    this->connecte = false;
    this->webcam = false;
    this->foreward = false;
    this->backward = false;
    this->left = false;
    this->right = false;
    this->battery = 0;
    this->cameraup = "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200";
    this->cameradown = "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200";
    this->cameraleft = "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200";
    this->cameraright = "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200";
    //camera = new QNetworkAccessManager(this);
    timer = new QTimer();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
}

void Communication::Connexion(){
    qDebug() << "Connexion à " << this->adresse << ":" << this->port;
    tcp.connectToHost(this->adresse, this->port.toInt());
    if(tcp.waitForConnected(5000)){
        qDebug() << "Connecté";
        this->connecte = true;
        timer->start();
    }
    else{
        QMessageBox::critical(0, QObject::tr("Erreur"), QObject::tr("Echec de la Connexion"));
        this->connecte = false;
    }
}

void Communication::tick(){
    GenMessage();
    sendMessage();
    recvMessage();
}

void Communication::Deconnexion(){
    tcp.disconnectFromHost();
    this->connecte = false;
    timer->stop();
    this->cpt_ir1 = 0;
    this->cpt_ir2 = 0;
    this->battery = 0;
}

void Communication::GenMessage(){
    if(webcam){
        QUrl url("http://" + this->adresse +":8080" + cameraup);

    }
    else{
        buf.clear();
        buf.append((char)0xff);
        buf.append((char)0x07);
        if(foreward || backward || left || right)
            if((foreward|| left || right) && this->cpt_ir1 > 0)
                buf.append((char)vitesse);
            else if(backward && this->cpt_ir2 > 0)
                buf.append((char)vitesse);
            else
                buf.append((char)0x00);
        else
            buf.append((char)0x00);
        buf.append((char)0x00);
        if(foreward || backward || left || right)
            if((foreward|| left || right) && this->cpt_ir1 > 0)
                buf.append((char)vitesse);
            else if(backward && this->cpt_ir2 > 0)
                buf.append((char)vitesse);
            else
                buf.append((char)0x00);
        else
            buf.append((char)0x00);
        buf.append((char)0x00);
        if(this->foreward)
        //avant / avant
            buf.append((char)0b01010000);
        //arrière / avant
        else if(this->left)
            buf.append((char)0b00010000);
        //avant / arrière
        else if(this->right)
            buf.append((char)0b01000000);
        //arrière / arrière
        else if(this->backward)
            buf.append((char)0b00000000);
        quint16 crc = this->crc16(buf, 1);
        buf.append((char)crc);
        buf.append((char)(crc>>8));
    }
}

void Communication::sendMessage(){
    tcp.write(buf);
    tcp.flush();
}

void Communication::recvMessage(){
    char recv[21];
    tcp.read(recv, 21);
    qDebug() << "Batterie " << (-(int) recv[2]) << endl;
    this->battery = (-(int) recv[2]);
    qDebug() << "cpt_ir1" << ( (int) recv[3]) << endl;
    this->cpt_ir1 = (int) recv[3];
    qDebug() << "cpt_ir2" << ( (int) recv[4]) << endl;
    this->cpt_ir2 = (int) recv[4];
}

quint16 Communication::crc16(QByteArray byteArray, int pos){
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
