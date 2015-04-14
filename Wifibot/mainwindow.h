#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "communication.h"
#include <QTimer>

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

    void update();

    void on_actionDeconnexion_triggered();

    void on_buttonCamera_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
