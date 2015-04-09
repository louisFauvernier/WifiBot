#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QIcon>
#include <QNetworkAccessManager>
#include <QUrl>



class Communication : public QObject
{
    Q_OBJECT
public:
    Communication(QObject *parent = 0);
    QByteArray buf;
    QString adresse;
    QString port;
    QString cameraup;
    QString cameradown;
    QString cameraleft;
    QString cameraright;
    QNetworkAccessManager camera;
    bool connecte;
    bool webcam;
    bool foreward;
    bool backward;
    bool left;
    bool right;
    int cpt_ir1;
    int cpt_ir2;
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
