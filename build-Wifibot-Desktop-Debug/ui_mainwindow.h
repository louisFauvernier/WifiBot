/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *buttonConnect;
    QWidget *centralWidget;
    QPushButton *buttonForeward;
    QPushButton *buttonLeft;
    QPushButton *buttonRight;
    QPushButton *buttonBackward;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *forward_label;
    QLabel *right_label;
    QLabel *left_label;
    QLabel *backward_label;
    QLineEdit *adIP;
    QLineEdit *port;
    QSlider *vitesse;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionQuitter->setMenuRole(QAction::ApplicationSpecificRole);
        buttonConnect = new QAction(MainWindow);
        buttonConnect->setObjectName(QStringLiteral("buttonConnect"));
        buttonConnect->setMenuRole(QAction::ApplicationSpecificRole);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        buttonForeward = new QPushButton(centralWidget);
        buttonForeward->setObjectName(QStringLiteral("buttonForeward"));
        buttonForeward->setGeometry(QRect(240, 150, 80, 23));
        buttonLeft = new QPushButton(centralWidget);
        buttonLeft->setObjectName(QStringLiteral("buttonLeft"));
        buttonLeft->setGeometry(QRect(160, 180, 80, 23));
        buttonRight = new QPushButton(centralWidget);
        buttonRight->setObjectName(QStringLiteral("buttonRight"));
        buttonRight->setGeometry(QRect(320, 180, 80, 23));
        buttonBackward = new QPushButton(centralWidget);
        buttonBackward->setObjectName(QStringLiteral("buttonBackward"));
        buttonBackward->setGeometry(QRect(240, 210, 80, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 57, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 57, 15));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 57, 15));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 57, 15));
        forward_label = new QLabel(centralWidget);
        forward_label->setObjectName(QStringLiteral("forward_label"));
        forward_label->setGeometry(QRect(80, 10, 57, 15));
        right_label = new QLabel(centralWidget);
        right_label->setObjectName(QStringLiteral("right_label"));
        right_label->setGeometry(QRect(80, 70, 57, 15));
        left_label = new QLabel(centralWidget);
        left_label->setObjectName(QStringLiteral("left_label"));
        left_label->setGeometry(QRect(80, 50, 57, 15));
        backward_label = new QLabel(centralWidget);
        backward_label->setObjectName(QStringLiteral("backward_label"));
        backward_label->setGeometry(QRect(80, 30, 57, 15));
        adIP = new QLineEdit(centralWidget);
        adIP->setObjectName(QStringLiteral("adIP"));
        adIP->setGeometry(QRect(250, 20, 113, 23));
        port = new QLineEdit(centralWidget);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(250, 50, 113, 23));
        vitesse = new QSlider(centralWidget);
        vitesse->setObjectName(QStringLiteral("vitesse"));
        vitesse->setGeometry(QRect(200, 0, 16, 160));
        vitesse->setMinimum(60);
        vitesse->setMaximum(240);
        vitesse->setOrientation(Qt::Vertical);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionQuitter);
        menuMenu->addAction(buttonConnect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WifiBot Alpha V1.00", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        buttonConnect->setText(QApplication::translate("MainWindow", "Connexion", 0));
        buttonForeward->setText(QApplication::translate("MainWindow", "Avancer", 0));
        buttonLeft->setText(QApplication::translate("MainWindow", "Gauche", 0));
        buttonRight->setText(QApplication::translate("MainWindow", "Droite", 0));
        buttonBackward->setText(QApplication::translate("MainWindow", "Reculer", 0));
        label->setText(QApplication::translate("MainWindow", "Foreward", 0));
        label_2->setText(QApplication::translate("MainWindow", "Backward", 0));
        label_3->setText(QApplication::translate("MainWindow", "left", 0));
        label_4->setText(QApplication::translate("MainWindow", "right", 0));
        forward_label->setText(QApplication::translate("MainWindow", "false", 0));
        right_label->setText(QApplication::translate("MainWindow", "false", 0));
        left_label->setText(QApplication::translate("MainWindow", "false", 0));
        backward_label->setText(QApplication::translate("MainWindow", "false", 0));
        adIP->setText(QApplication::translate("MainWindow", "192.168.1.106", 0));
        port->setText(QApplication::translate("MainWindow", "15020", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
