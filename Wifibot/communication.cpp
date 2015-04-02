#include "communication.h"
#include <iostream>

Communication::Communication(QString adresse, Qint port){
    this->adresse = adresse;
    this->port = port;
    buf->clear();
    connexion = new QTcpSocket();
}

