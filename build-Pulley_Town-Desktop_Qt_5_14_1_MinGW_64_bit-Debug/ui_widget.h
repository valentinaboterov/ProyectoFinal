/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *Multi;
    QPushButton *Creditos;
    QPushButton *Jugador;
    QLabel *label_2;
    QPushButton *Registro;
    QPushButton *Inicarsesion;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1000, 562);
        Widget->setMaximumSize(QSize(1000, 562));
        Widget->setAutoFillBackground(false);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1000, 562));
        label->setMaximumSize(QSize(1000, 562));
        label->setAutoFillBackground(false);
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Inicio.png")));
        label->setScaledContents(true);
        Multi = new QPushButton(Widget);
        Multi->setObjectName(QString::fromUtf8("Multi"));
        Multi->setGeometry(QRect(560, 360, 131, 31));
        Creditos = new QPushButton(Widget);
        Creditos->setObjectName(QString::fromUtf8("Creditos"));
        Creditos->setGeometry(QRect(420, 510, 151, 31));
        Jugador = new QPushButton(Widget);
        Jugador->setObjectName(QString::fromUtf8("Jugador"));
        Jugador->setGeometry(QRect(280, 350, 131, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 330, 171, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Registro = new QPushButton(Widget);
        Registro->setObjectName(QString::fromUtf8("Registro"));
        Registro->setGeometry(QRect(370, 270, 101, 31));
        Inicarsesion = new QPushButton(Widget);
        Inicarsesion->setObjectName(QString::fromUtf8("Inicarsesion"));
        Inicarsesion->setGeometry(QRect(510, 270, 111, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        Multi->setText(QCoreApplication::translate("Widget", "Multijugador", nullptr));
        Creditos->setText(QCoreApplication::translate("Widget", "Creditos", nullptr));
        Jugador->setText(QCoreApplication::translate("Widget", "Un solo jugador", nullptr));
#if QT_CONFIG(whatsthis)
        label_2->setWhatsThis(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_2->setText(QCoreApplication::translate("Widget", "MODO DE JUEGO:", nullptr));
        Registro->setText(QCoreApplication::translate("Widget", "Registro", nullptr));
        Inicarsesion->setText(QCoreApplication::translate("Widget", "Iniciar sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
