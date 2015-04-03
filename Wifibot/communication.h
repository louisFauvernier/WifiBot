#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>


class Communication : public QObject
{
    Q_OBJECT
public:
    Communication(QObject *parent = 0);
    QByteArray buf;
    QString adresse;
    QString port;
    bool connecte;
    bool foreward;
    bool backward;
    bool left;
    bool right;
    QTcpSocket tcp;
    QTimer *timer;
    void Connexion();
    void Deconnexion();
    void GenMessage();
    void sendMessage();
    void recvMessage();
    quint16 vitesse;
    quint16 battery;
    quint16 crc16(QByteArray byteArray, int pos);

public slots:
         void tick();
signals:

};

#endif // COMMUNICATION_H
