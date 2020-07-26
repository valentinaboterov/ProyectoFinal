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
    QLabel *partida;

    void setupUi(QWidget *Modojuego)
    {
        if (Modojuego->objectName().isEmpty())
            Modojuego->setObjectName(QString::fromUtf8("Modojuego"));
        Modojuego->resize(800, 841);
        Modojuego->setMaximumSize(QSize(800, 841));
        label = new QLabel(Modojuego);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 800, 841));
        label->setMaximumSize(QSize(800, 841));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondomodojuego.png")));
        label->setScaledContents(true);
        Cargar = new QPushButton(Modojuego);
        Cargar->setObjectName(QString::fromUtf8("Cargar"));
        Cargar->setGeometry(QRect(40, 770, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        Cargar->setFont(font);
        Dficultad = new QLabel(Modojuego);
        Dficultad->setObjectName(QString::fromUtf8("Dficultad"));
        Dficultad->setGeometry(QRect(330, 800, 111, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("8514oem"));
        font1.setPointSize(10);
        Dficultad->setFont(font1);
        Dficultad->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(170, 0, 255);"));
        Mensaje = new QLabel(Modojuego);
        Mensaje->setObjectName(QString::fromUtf8("Mensaje"));
        Mensaje->setGeometry(QRect(220, 480, 401, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("8514oem"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        Mensaje->setFont(font2);
        Mensaje->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);\n"
"font: 75 8pt \"8514oem\";\n"
"background-color: rgb(232, 232, 232);"));
        Empezar = new QPushButton(Modojuego);
        Empezar->setObjectName(QString::fromUtf8("Empezar"));
        Empezar->setGeometry(QRect(590, 740, 161, 71));
        QFont font3;
        font3.setFamily(QString::fromUtf8("8514oem"));
        Empezar->setFont(font3);
        label_3 = new QLabel(Modojuego);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 730, 151, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("8514oem"));
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(170, 0, 255);"));
        novato = new QRadioButton(Modojuego);
        novato->setObjectName(QString::fromUtf8("novato"));
        novato->setGeometry(QRect(220, 760, 91, 20));
        novato->setFont(font3);
        novato->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(255, 0, 127);"));
        Aprendiz = new QRadioButton(Modojuego);
        Aprendiz->setObjectName(QString::fromUtf8("Aprendiz"));
        Aprendiz->setGeometry(QRect(320, 760, 111, 20));
        Aprendiz->setFont(font3);
        Aprendiz->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(255, 0, 127);"));
        Experto = new QRadioButton(Modojuego);
        Experto->setObjectName(QString::fromUtf8("Experto"));
        Experto->setGeometry(QRect(450, 760, 101, 21));
        Experto->setFont(font3);
        Experto->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(255, 0, 127);"));
        label_4 = new QLabel(Modojuego);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 730, 191, 20));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(170, 0, 255);"));
        Mensaje1 = new QLabel(Modojuego);
        Mensaje1->setObjectName(QString::fromUtf8("Mensaje1"));
        Mensaje1->setGeometry(QRect(240, 510, 371, 20));
        Mensaje1->setFont(font2);
        Mensaje1->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);\n"
"background-color: rgb(232, 232, 232);\n"
"font: 75 8pt \"8514oem\";"));
        Mensaje2 = new QLabel(Modojuego);
        Mensaje2->setObjectName(QString::fromUtf8("Mensaje2"));
        Mensaje2->setGeometry(QRect(240, 540, 371, 20));
        Mensaje2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);\n"
"font: 75 8pt \"8514oem\";\n"
"background-color: rgb(232, 232, 232);"));
        partida = new QLabel(Modojuego);
        partida->setObjectName(QString::fromUtf8("partida"));
        partida->setGeometry(QRect(220, 600, 401, 31));
        partida->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"font: 75 8pt \"8514oem\";\n"
"background-color: rgb(232, 232, 232);"));
        label->raise();
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
        partida->raise();

        retranslateUi(Modojuego);

        QMetaObject::connectSlotsByName(Modojuego);
    } // setupUi

    void retranslateUi(QWidget *Modojuego)
    {
        Modojuego->setWindowTitle(QCoreApplication::translate("Modojuego", "Form", nullptr));
        label->setText(QString());
#if QT_CONFIG(whatsthis)
        Cargar->setWhatsThis(QCoreApplication::translate("Modojuego", "<html><head/><body><p align=\"center\">CARGAR PARTIDA</p><p align=\"center\">ANTERIOR</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Cargar->setText(QCoreApplication::translate("Modojuego", "CARGAR", nullptr));
        Dficultad->setText(QCoreApplication::translate("Modojuego", "DIFICULTAD", nullptr));
        Mensaje->setText(QString());
        Empezar->setText(QCoreApplication::translate("Modojuego", "EMPEZAR", nullptr));
        label_3->setText(QCoreApplication::translate("Modojuego", "NUEVA PARTIDA:", nullptr));
        novato->setText(QCoreApplication::translate("Modojuego", "Novato", nullptr));
        Aprendiz->setText(QCoreApplication::translate("Modojuego", "Aprendiz", nullptr));
        Experto->setText(QCoreApplication::translate("Modojuego", "Experto", nullptr));
        label_4->setText(QCoreApplication::translate("Modojuego", "PARTIDA ANTERIOR:", nullptr));
        Mensaje1->setText(QString());
        Mensaje2->setText(QString());
        partida->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Modojuego: public Ui_Modojuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODOJUEGO_H
