/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QAction *actionConnexion;
    QAction *actionDeconnexion;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *vitesse;
    QGridLayout *gridLayout;
    QPushButton *buttonLeft;
    QPushButton *buttonForeward;
    QPushButton *buttonCamera;
    QPushButton *buttonBackward;
    QPushButton *buttonRight;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetCamera;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionQuitter->setMenuRole(QAction::ApplicationSpecificRole);
        actionConnexion = new QAction(MainWindow);
        actionConnexion->setObjectName(QStringLiteral("actionConnexion"));
        actionConnexion->setMenuRole(QAction::ApplicationSpecificRole);
        actionDeconnexion = new QAction(MainWindow);
        actionDeconnexion->setObjectName(QStringLiteral("actionDeconnexion"));
        actionDeconnexion->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 381, 154));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        vitesse = new QSlider(horizontalLayoutWidget);
        vitesse->setObjectName(QStringLiteral("vitesse"));
        vitesse->setEnabled(false);
        vitesse->setMinimumSize(QSize(20, 0));
        vitesse->setMinimum(60);
        vitesse->setMaximum(240);
        vitesse->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(vitesse);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonLeft = new QPushButton(horizontalLayoutWidget);
        buttonLeft->setObjectName(QStringLiteral("buttonLeft"));
        buttonLeft->setEnabled(false);
        buttonLeft->setMinimumSize(QSize(0, 0));
        buttonLeft->setMaximumSize(QSize(50, 50));
        buttonLeft->setStyleSheet(QStringLiteral("border: 0; border-radius: 3px; outline: 0px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/left_disable.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLeft->setIcon(icon);
        buttonLeft->setIconSize(QSize(50, 50));
        buttonLeft->setFlat(true);

        gridLayout->addWidget(buttonLeft, 1, 0, 1, 1);

        buttonForeward = new QPushButton(horizontalLayoutWidget);
        buttonForeward->setObjectName(QStringLiteral("buttonForeward"));
        buttonForeward->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonForeward->sizePolicy().hasHeightForWidth());
        buttonForeward->setSizePolicy(sizePolicy);
        buttonForeward->setMaximumSize(QSize(50, 50));
        buttonForeward->setToolTipDuration(-1);
        buttonForeward->setStyleSheet(QStringLiteral("border: 0; border-radius: 3px; outline: 0px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/foreward_disable.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonForeward->setIcon(icon1);
        buttonForeward->setIconSize(QSize(50, 50));
        buttonForeward->setFlat(true);

        gridLayout->addWidget(buttonForeward, 0, 1, 1, 1);

        buttonCamera = new QPushButton(horizontalLayoutWidget);
        buttonCamera->setObjectName(QStringLiteral("buttonCamera"));
        buttonCamera->setEnabled(true);
        buttonCamera->setMaximumSize(QSize(50, 50));
        buttonCamera->setStyleSheet(QStringLiteral("border: 0; border-radius: 3px; outline: 0px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/robot.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCamera->setIcon(icon2);
        buttonCamera->setIconSize(QSize(50, 50));
        buttonCamera->setFlat(true);

        gridLayout->addWidget(buttonCamera, 1, 1, 1, 1);

        buttonBackward = new QPushButton(horizontalLayoutWidget);
        buttonBackward->setObjectName(QStringLiteral("buttonBackward"));
        buttonBackward->setEnabled(false);
        buttonBackward->setMaximumSize(QSize(50, 50));
        buttonBackward->setStyleSheet(QStringLiteral("border: 0; border-radius: 3px; outline: 0px;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/backward_disable.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonBackward->setIcon(icon3);
        buttonBackward->setIconSize(QSize(50, 50));
        buttonBackward->setFlat(true);

        gridLayout->addWidget(buttonBackward, 2, 1, 1, 1);

        buttonRight = new QPushButton(horizontalLayoutWidget);
        buttonRight->setObjectName(QStringLiteral("buttonRight"));
        buttonRight->setEnabled(true);
        buttonRight->setMaximumSize(QSize(50, 50));
        buttonRight->setStyleSheet(QStringLiteral("border: 0; border-radius: 3px; outline: 0px;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/right_disable.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRight->setIcon(icon4);
        buttonRight->setIconSize(QSize(50, 50));
        buttonRight->setFlat(true);

        gridLayout->addWidget(buttonRight, 1, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidgetCamera = new QDockWidget(MainWindow);
        dockWidgetCamera->setObjectName(QStringLiteral("dockWidgetCamera"));
        dockWidgetCamera->setEnabled(false);
        dockWidgetCamera->setMinimumSize(QSize(400, 41));
        dockWidgetCamera->setLayoutDirection(Qt::LeftToRight);
        dockWidgetCamera->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidgetCamera->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetCamera);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionQuitter);
        menuMenu->addAction(actionConnexion);
        menuMenu->addAction(actionDeconnexion);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WifiBot Alpha V1.04", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionConnexion->setText(QApplication::translate("MainWindow", "Connexion", 0));
        actionDeconnexion->setText(QApplication::translate("MainWindow", "Deconnexion", 0));
        buttonLeft->setText(QString());
        buttonForeward->setText(QString());
        buttonCamera->setText(QString());
        buttonBackward->setText(QString());
        buttonRight->setText(QString());
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
