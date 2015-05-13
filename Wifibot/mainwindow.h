#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "communication.h"
#include <QTimer>
#include <qmediaplayer.h>

#include <QtGui/QMovie>
#include <QtWidgets/QWidget>
#include "connexion.h"
#include "camera.h"
#include "viewergl.h"

#include <unistd.h>
#include <QtWidgets>
#include <qvideowidget.h>
#include <qvideosurfaceformat.h>
#include <QKeyEvent>


#define cameraup "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200"
#define cameradown "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200"
#define cameraleft "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"
#define cameraright "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200"

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
    Ui::MainWindow * getUI();
    void initComponents();
    bool foreward;
    bool backward;
    bool left;
    bool right;
    QTimer *timer;
    Communication* co;
    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *event);

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

    void on_actionConnexion_triggered();

    void update();

    void on_actionDeconnexion_triggered();

    void on_buttonCamera_clicked();

private:
    Ui::MainWindow *ui;

    Camera *w;

    QMediaPlayer *mediaPlayer;
    QProgressBar *battery;
    QRadioButton *forewardSensor;
    QRadioButton *backwardSensor;
    ViewerGl *videoWidget;

    void setInterfaceEnabled(bool b);

};

#endif // MAINWINDOW_H
