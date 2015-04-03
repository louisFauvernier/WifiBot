#ifndef CONNEXION_H
#define CONNEXION_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

class connexion : public QObject
{
    Q_OBJECT
public:
    connexion(QObject *parent = 0);
    QByteArray buf;
    QString adresse;
    QString port;
    bool connecte;
    bool foreward;

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

#endif // CONNEXION_H
