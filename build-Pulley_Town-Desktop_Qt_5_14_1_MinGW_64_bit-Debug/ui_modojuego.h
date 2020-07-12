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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modojuego
{
public:
    QLabel *label;
    QLabel *Modojuego_2;
    QPushButton *Cargar;
    QLabel *Dficultad;
    QLabel *Mensaje;
    QPushButton *Empezar;
    QLabel *label_3;
    QRadioButton *novato;
    QRadioButton *Aprendiz;
    QRadioButton *Experto;
    QLabel *label_4;
    QLabel *Mensaje1;
    QLabel *Mensaje2;

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
        Modojuego_2->setGeometry(QRect(450, 240, 241, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setPointSize(15);
        Modojuego_2->setFont(font);
        Modojuego_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Cargar = new QPushButton(Modojuego);
        Cargar->setObjectName(QString::fromUtf8("Cargar"));
        Cargar->setGeometry(QRect(240, 510, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("8514oem"));
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        Cargar->setFont(font1);
        Dficultad = new QLabel(Modojuego);
        Dficultad->setObjectName(QString::fromUtf8("Dficultad"));
        Dficultad->setGeometry(QRect(660, 500, 141, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("8514oem"));
        font2.setPointSize(10);
        Dficultad->setFont(font2);
        Dficultad->setStyleSheet(QString::fromUtf8("\n"
"\n"
"color: rgb(255, 255, 255);"));
        Mensaje = new QLabel(Modojuego);
        Mensaje->setObjectName(QString::fromUtf8("Mensaje"));
        Mensaje->setGeometry(QRect(330, 310, 401, 20));
        QFont font3;
        font3.setPointSize(10);
        Mensaje->setFont(font3);
        Mensaje->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Empezar = new QPushButton(Modojuego);
        Empezar->setObjectName(QString::fromUtf8("Empezar"));
        Empezar->setGeometry(QRect(880, 510, 91, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("8514oem"));
        Empezar->setFont(font4);
        label_3 = new QLabel(Modojuego);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(390, 510, 251, 20));
        QFont font5;
        font5.setFamily(QString::fromUtf8("8514oem"));
        font5.setBold(true);
        font5.setUnderline(true);
        font5.setWeight(75);
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));
        novato = new QRadioButton(Modojuego);
        novato->setObjectName(QString::fromUtf8("novato"));
        novato->setGeometry(QRect(560, 520, 101, 20));
        novato->setFont(font4);
        novato->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Aprendiz = new QRadioButton(Modojuego);
        Aprendiz->setObjectName(QString::fromUtf8("Aprendiz"));
        Aprendiz->setGeometry(QRect(650, 520, 121, 20));
        Aprendiz->setFont(font4);
        Aprendiz->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Experto = new QRadioButton(Modojuego);
        Experto->setObjectName(QString::fromUtf8("Experto"));
        Experto->setGeometry(QRect(770, 520, 111, 20));
        Experto->setFont(font4);
        Experto->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(Modojuego);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 510, 231, 20));
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Mensaje1 = new QLabel(Modojuego);
        Mensaje1->setObjectName(QString::fromUtf8("Mensaje1"));
        Mensaje1->setGeometry(QRect(340, 370, 411, 20));
        QFont font6;
        font6.setFamily(QString::fromUtf8("8514oem"));
        font6.setPointSize(8);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        Mensaje1->setFont(font6);
        Mensaje1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 8pt \"8514oem\";"));
        Mensaje2 = new QLabel(Modojuego);
        Mensaje2->setObjectName(QString::fromUtf8("Mensaje2"));
        Mensaje2->setGeometry(QRect(330, 410, 411, 20));
        Mensaje2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 8pt \"8514oem\";"));
        label->raise();
        Modojuego_2->raise();
        Dficultad->raise();
        Mensaje->raise();
        Empezar->raise();
        label_3->raise();
        Cargar->raise();
        novato->raise();
        Aprendiz->raise();
        Experto->raise();
        label_4->raise();
        Mensaje1->raise();
        Mensaje2->raise();

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
        Modojuego_2->setText(QCoreApplication::translate("Modojuego", "BIENVENID@(S) ", nullptr));
#if QT_CONFIG(whatsthis)
        Cargar->setWhatsThis(QCoreApplication::translate("Modojuego", "<html><head/><body><p align=\"center\">CARGAR PARTIDA</p><p align=\"center\">ANTERIOR</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Cargar->setText(QCoreApplication::translate("Modojuego", "CARGAR", nullptr));
        Dficultad->setText(QCoreApplication::translate("Modojuego", "DIFICULTAD:", nullptr));
        Mensaje->setText(QString());
        Empezar->setText(QCoreApplication::translate("Modojuego", "EMPEZAR", nullptr));
        label_3->setText(QCoreApplication::translate("Modojuego", "NUEVA PARTIDA:", nullptr));
        novato->setText(QCoreApplication::translate("Modojuego", "Novato", nullptr));
        Aprendiz->setText(QCoreApplication::translate("Modojuego", "Aprendiz", nullptr));
        Experto->setText(QCoreApplication::translate("Modojuego", "Experto", nullptr));
        label_4->setText(QCoreApplication::translate("Modojuego", "PARTIDA ANTERIOR:", nullptr));
        Mensaje1->setText(QString());
        Mensaje2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Modojuego: public Ui_Modojuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODOJUEGO_H
