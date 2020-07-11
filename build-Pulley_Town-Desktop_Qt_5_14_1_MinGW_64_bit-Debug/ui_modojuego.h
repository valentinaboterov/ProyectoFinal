/********************************************************************************
** Form generated from reading UI file 'modojuego.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODOJUEGO_H
#define UI_MODOJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modojuego
{
public:
    QLabel *label;
    QLabel *Modojuego_2;
    QPushButton *Cargar;
    QLabel *Dficultad;
    QPushButton *Novato;
    QPushButton *Aprendiz;
    QPushButton *Experto;
    QLabel *Mensaje;
    QLabel *label_2;
    QPushButton *Empezar;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Modojuego)
    {
        if (Modojuego->objectName().isEmpty())
            Modojuego->setObjectName(QString::fromUtf8("Modojuego"));
        Modojuego->resize(1000, 562);
        Modojuego->setMaximumSize(QSize(1000, 570));
        label = new QLabel(Modojuego);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1000, 562));
        label->setMaximumSize(QSize(1000, 562));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Modojuego.jpeg")));
        label->setScaledContents(true);
        Modojuego_2 = new QLabel(Modojuego);
        Modojuego_2->setObjectName(QString::fromUtf8("Modojuego_2"));
        Modojuego_2->setGeometry(QRect(310, 160, 131, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setPointSize(10);
        Modojuego_2->setFont(font);
        Modojuego_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Cargar = new QPushButton(Modojuego);
        Cargar->setObjectName(QString::fromUtf8("Cargar"));
        Cargar->setGeometry(QRect(380, 240, 281, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("8514oem"));
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        Cargar->setFont(font1);
        Dficultad = new QLabel(Modojuego);
        Dficultad->setObjectName(QString::fromUtf8("Dficultad"));
        Dficultad->setGeometry(QRect(460, 340, 141, 21));
        Dficultad->setFont(font);
        Dficultad->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Novato = new QPushButton(Modojuego);
        Novato->setObjectName(QString::fromUtf8("Novato"));
        Novato->setGeometry(QRect(440, 370, 141, 31));
        Aprendiz = new QPushButton(Modojuego);
        Aprendiz->setObjectName(QString::fromUtf8("Aprendiz"));
        Aprendiz->setGeometry(QRect(440, 410, 141, 31));
        Experto = new QPushButton(Modojuego);
        Experto->setObjectName(QString::fromUtf8("Experto"));
        Experto->setGeometry(QRect(440, 450, 141, 31));
        Mensaje = new QLabel(Modojuego);
        Mensaje->setObjectName(QString::fromUtf8("Mensaje"));
        Mensaje->setGeometry(QRect(470, 160, 231, 20));
        Mensaje->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Modojuego);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 310, 47, 14));
        Empezar = new QPushButton(Modojuego);
        Empezar->setObjectName(QString::fromUtf8("Empezar"));
        Empezar->setGeometry(QRect(470, 500, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("8514oem"));
        Empezar->setFont(font2);
        label_3 = new QLabel(Modojuego);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 320, 131, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("8514oem"));
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(Modojuego);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 300, 31, 16));
        label_4->setFont(font2);
        label_5 = new QLabel(Modojuego);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 210, 91, 31));
        label_5->setFont(font1);
        label->raise();
        Modojuego_2->raise();
        Dficultad->raise();
        Novato->raise();
        Aprendiz->raise();
        Experto->raise();
        Mensaje->raise();
        label_2->raise();
        Empezar->raise();
        label_3->raise();
        Cargar->raise();
        label_4->raise();
        label_5->raise();

        retranslateUi(Modojuego);

        QMetaObject::connectSlotsByName(Modojuego);
    } // setupUi

    void retranslateUi(QWidget *Modojuego)
    {
        Modojuego->setWindowTitle(QCoreApplication::translate("Modojuego", "Form", nullptr));
        label->setText(QString());
#if QT_CONFIG(whatsthis)
        Modojuego_2->setWhatsThis(QCoreApplication::translate("Modojuego", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Modojuego_2->setText(QCoreApplication::translate("Modojuego", "BIENVENID@ ", nullptr));
#if QT_CONFIG(whatsthis)
        Cargar->setWhatsThis(QCoreApplication::translate("Modojuego", "<html><head/><body><p align=\"center\">CARGAR PARTIDA</p><p align=\"center\">ANTERIOR</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Cargar->setText(QCoreApplication::translate("Modojuego", "CARGAR PARTIDA ANTERIOR", nullptr));
        Dficultad->setText(QCoreApplication::translate("Modojuego", "DIFICULTAD:", nullptr));
        Novato->setText(QCoreApplication::translate("Modojuego", "Novato", nullptr));
        Aprendiz->setText(QCoreApplication::translate("Modojuego", "Aprendiz", nullptr));
        Experto->setText(QCoreApplication::translate("Modojuego", "Experto", nullptr));
        Mensaje->setText(QCoreApplication::translate("Modojuego", "Mensaje", nullptr));
        label_2->setText(QString());
        Empezar->setText(QCoreApplication::translate("Modojuego", "EMPEZAR", nullptr));
        label_3->setText(QCoreApplication::translate("Modojuego", "JUEGO NUEVO:", nullptr));
        label_4->setText(QCoreApplication::translate("Modojuego", "o", nullptr));
        label_5->setText(QCoreApplication::translate("Modojuego", "Deseas:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modojuego: public Ui_Modojuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODOJUEGO_H
