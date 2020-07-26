/********************************************************************************
** Form generated from reading UI file 'ganador.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANADOR_H
#define UI_GANADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ganador
{
public:
    QLabel *label;
    QPushButton *menu;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *nombre;

    void setupUi(QWidget *Ganador)
    {
        if (Ganador->objectName().isEmpty())
            Ganador->setObjectName(QString::fromUtf8("Ganador"));
        Ganador->resize(440, 600);
        Ganador->setMaximumSize(QSize(440, 600));
        Ganador->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Ganador);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 440, 600));
        label->setMaximumSize(QSize(440, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondoganador.jpeg")));
        label->setScaledContents(true);
        menu = new QPushButton(Ganador);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(120, 440, 211, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setBold(true);
        font.setWeight(75);
        menu->setFont(font);
        label_2 = new QLabel(Ganador);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 350, 181, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("8514oem"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0,0, 0);\n"
"font: 75 8pt \"8514oem\";\n"
"background-color: rgb(255, 255, 255);\n"
""));
        label_3 = new QLabel(Ganador);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 370, 201, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("8514oem"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 8pt \"8514oem\";"));
        nombre = new QLabel(Ganador);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(170, 400, 111, 16));
        nombre->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 8pt \"8514oem\";\n"
""));

        retranslateUi(Ganador);

        QMetaObject::connectSlotsByName(Ganador);
    } // setupUi

    void retranslateUi(QWidget *Ganador)
    {
        Ganador->setWindowTitle(QCoreApplication::translate("Ganador", "Ganador", nullptr));
        label->setText(QString());
        menu->setText(QCoreApplication::translate("Ganador", "VOLVER AL MENU", nullptr));
        label_2->setText(QCoreApplication::translate("Ganador", "FELICITACIONES!", nullptr));
        label_3->setText(QCoreApplication::translate("Ganador", "JUEGA DE NUEVO!", nullptr));
        nombre->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ganador: public Ui_Ganador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANADOR_H
