#include "connexion.h"

connexion::connexion(QObject *parent) : QObject(parent)
{
    this->connecte = false;
    this->battery = 0;
    timer = new QTimer();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
}

void connexion::Connexion(){
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << "Connexion à " << this->adresse << ":" << this->port << endl;
    tcp.connectToHost(this->adresse, this->port.toInt());
    if(tcp.waitForConnected(5000)){
        cout << "Connecté" << endl;
        this->connecte = true;
        timer->start();
    }
    else{
        cout << "Echec de la connexion" << endl;
        this->connecte = false;
    }
}

void connexion::tick(){
    GenMessage();
    sendMessage();
    recvMessage();
}

void connexion::Deconnexion(){
    tcp.disconnectFromHost();
    this->connecte = false;
    timer->stop();
}
void connexion::GenMessage(){
    buf.clear();
    buf.append((char)0xff);
    buf.append((char)0x07);
    buf.append((char)vitesse);
    buf.append((char)0x00);
    buf.append((char)vitesse);
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
void connexion::sendMessage(){
    tcp.write(buf);
    tcp.flush();
}

void connexion::recvMessage(){
    char recv[21];
    tcp.read(recv, 21);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << (-(int) recv[2]) << endl;
    this->battery = -(int) recv[2];
    cout << ( (int) recv[3]) << endl;
    cout << ( (int) recv[4]) << endl;
    cout << endl;
}

quint16 connexion::crc16(QByteArray byteArray, int pos){
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