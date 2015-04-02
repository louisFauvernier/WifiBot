#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void modifyLabel(QString, QString);
    bool foreward;
    bool backward;
    bool left;
    bool right;
    bool connecte;
    QByteArray buf;
    QTcpSocket connexion;
    void Connexion();
    void Deconnexion();
    void GenMessage();
    void sendMessage();
    void recvMessage();
    quint16 crc16(QByteArray byteArray, int pos);

private slots:
    
    void on_buttonRight_pressed();
    
    void on_buttonLeft_pressed();
    
    void on_buttonLeft_released();
    
    void on_buttonForeward_pressed();

    void on_buttonForeward_released();

    void on_buttonRight_released();

    void on_buttonBackward_pressed();

    void on_buttonBackward_released();

    void on_actionQuitter_triggered();

    void on_buttonConnect_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
