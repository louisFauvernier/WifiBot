/********************************************************************************
** Form generated from reading UI file 'connexion.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXION_H
#define UI_CONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connexion
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_address;
    QLineEdit *lineEdit_address;
    QLabel *label_port;
    QLineEdit *lineEdit_port;

    void setupUi(QDialog *Connexion)
    {
        if (Connexion->objectName().isEmpty())
            Connexion->setObjectName(QStringLiteral("Connexion"));
        Connexion->resize(200, 100);
        buttonBox = new QDialogButtonBox(Connexion);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 70, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(Connexion);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 181, 62));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_address = new QLabel(gridLayoutWidget);
        label_address->setObjectName(QStringLiteral("label_address"));

        gridLayout->addWidget(label_address, 0, 0, 1, 1);

        lineEdit_address = new QLineEdit(gridLayoutWidget);
        lineEdit_address->setObjectName(QStringLiteral("lineEdit_address"));

        gridLayout->addWidget(lineEdit_address, 0, 1, 1, 1);

        label_port = new QLabel(gridLayoutWidget);
        label_port->setObjectName(QStringLiteral("label_port"));

        gridLayout->addWidget(label_port, 1, 0, 1, 1);

        lineEdit_port = new QLineEdit(gridLayoutWidget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        gridLayout->addWidget(lineEdit_port, 1, 1, 1, 1);


        retranslateUi(Connexion);
        QObject::connect(buttonBox, SIGNAL(accepted()), Connexion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Connexion, SLOT(reject()));

        QMetaObject::connectSlotsByName(Connexion);
    } // setupUi

    void retranslateUi(QDialog *Connexion)
    {
        Connexion->setWindowTitle(QApplication::translate("Connexion", "Connexion", 0));
        label_address->setText(QApplication::translate("Connexion", "IP", 0));
        lineEdit_address->setText(QApplication::translate("Connexion", "192.168.1.106", 0));
        label_port->setText(QApplication::translate("Connexion", "Port", 0));
        lineEdit_port->setText(QApplication::translate("Connexion", "15020", 0));
    } // retranslateUi

};

namespace Ui {
    class Connexion: public Ui_Connexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXION_H
