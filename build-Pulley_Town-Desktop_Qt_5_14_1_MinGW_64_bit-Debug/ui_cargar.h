/********************************************************************************
** Form generated from reading UI file 'cargar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGAR_H
#define UI_CARGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cargar
{
public:
    QLabel *label;
    QLabel *nombre;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_2;
    QListWidget *lista;
    QLabel *mensaje;
    QLineEdit *partida;

    void setupUi(QWidget *Cargar)
    {
        if (Cargar->objectName().isEmpty())
            Cargar->setObjectName(QString::fromUtf8("Cargar"));
        Cargar->resize(800, 841);
        Cargar->setMaximumSize(QSize(800, 841));
        label = new QLabel(Cargar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 841));
        label->setMaximumSize(QSize(800, 841));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondo_carga.png")));
        label->setScaledContents(true);
        nombre = new QLabel(Cargar);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(350, 320, 171, 31));
        nombre->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"8514oem\";"));
        label_3 = new QLabel(Cargar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 590, 201, 21));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background-color: rgb(223, 223, 223);\n"
"font: 8pt \"8514oem\";"));
        label_4 = new QLabel(Cargar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 620, 81, 21));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background-color: rgb(223, 223, 223);\n"
"font: 8pt \"8514oem\";"));
        pushButton = new QPushButton(Cargar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 670, 101, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 8pt \"8514oem\";\n"
"text-decoration: underline;"));
        label_2 = new QLabel(Cargar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 350, 271, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 8pt \"8514oem\";"));
        lista = new QListWidget(Cargar);
        lista->setObjectName(QString::fromUtf8("lista"));
        lista->setGeometry(QRect(220, 400, 421, 171));
        mensaje = new QLabel(Cargar);
        mensaje->setObjectName(QString::fromUtf8("mensaje"));
        mensaje->setGeometry(QRect(300, 710, 411, 21));
        mensaje->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 0);\n"
"font: 75 8pt \"8514oem\";\n"
""));
        partida = new QLineEdit(Cargar);
        partida->setObjectName(QString::fromUtf8("partida"));
        partida->setGeometry(QRect(390, 620, 51, 21));

        retranslateUi(Cargar);

        QMetaObject::connectSlotsByName(Cargar);
    } // setupUi

    void retranslateUi(QWidget *Cargar)
    {
        Cargar->setWindowTitle(QCoreApplication::translate("Cargar", "Form", nullptr));
        label->setText(QString());
        nombre->setText(QString());
        label_3->setText(QCoreApplication::translate("Cargar", "Cual deseas cargar?", nullptr));
        label_4->setText(QCoreApplication::translate("Cargar", "PARTIDA:", nullptr));
        pushButton->setText(QCoreApplication::translate("Cargar", "CARGAR", nullptr));
        label_2->setText(QCoreApplication::translate("Cargar", "Tus partidas guardadas son:", nullptr));
        mensaje->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cargar: public Ui_Cargar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGAR_H
