/********************************************************************************
** Form generated from reading UI file 'niveles.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVELES_H
#define UI_NIVELES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Niveles
{
public:
    QGraphicsView *graphicsView;
    QLCDNumber *tiempo;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *paquetes;
    QPushButton *pausa;
    QPushButton *Guardar;
    QPushButton *Salir;
    QLabel *jugador1;
    QLCDNumber *paquetes1;
    QLabel *jugador2;
    QPushButton *musica;

    void setupUi(QWidget *Niveles)
    {
        if (Niveles->objectName().isEmpty())
            Niveles->setObjectName(QString::fromUtf8("Niveles"));
        Niveles->setWindowModality(Qt::NonModal);
        Niveles->resize(800, 800);
        Niveles->setMaximumSize(QSize(800, 800));
        Niveles->setAutoFillBackground(false);
        Niveles->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        graphicsView = new QGraphicsView(Niveles);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 50, 800, 750));
        graphicsView->setMaximumSize(QSize(800, 800));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tiempo = new QLCDNumber(Niveles);
        tiempo->setObjectName(QString::fromUtf8("tiempo"));
        tiempo->setGeometry(QRect(50, 10, 51, 31));
        label = new QLabel(Niveles);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 31, 31));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/reloj .png")));
        label->setScaledContents(true);
        label_2 = new QLabel(Niveles);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 10, 31, 31));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/peso.png")));
        label_2->setScaledContents(true);
        paquetes = new QLCDNumber(Niveles);
        paquetes->setObjectName(QString::fromUtf8("paquetes"));
        paquetes->setGeometry(QRect(180, 0, 51, 31));
        pausa = new QPushButton(Niveles);
        pausa->setObjectName(QString::fromUtf8("pausa"));
        pausa->setGeometry(QRect(610, 10, 51, 41));
        pausa->setStyleSheet(QString::fromUtf8("font: 8pt \"8514oem\";\n"
"border-color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);"));
        Guardar = new QPushButton(Niveles);
        Guardar->setObjectName(QString::fromUtf8("Guardar"));
        Guardar->setGeometry(QRect(670, 10, 51, 41));
        Salir = new QPushButton(Niveles);
        Salir->setObjectName(QString::fromUtf8("Salir"));
        Salir->setGeometry(QRect(730, 10, 51, 41));
        jugador1 = new QLabel(Niveles);
        jugador1->setObjectName(QString::fromUtf8("jugador1"));
        jugador1->setGeometry(QRect(160, 30, 91, 16));
        jugador1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 8pt \"8514oem\";"));
        paquetes1 = new QLCDNumber(Niveles);
        paquetes1->setObjectName(QString::fromUtf8("paquetes1"));
        paquetes1->setGeometry(QRect(290, 0, 51, 31));
        jugador2 = new QLabel(Niveles);
        jugador2->setObjectName(QString::fromUtf8("jugador2"));
        jugador2->setGeometry(QRect(280, 30, 91, 16));
        jugador2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 8pt \"8514oem\";"));
        musica = new QPushButton(Niveles);
        musica->setObjectName(QString::fromUtf8("musica"));
        musica->setGeometry(QRect(550, 10, 51, 41));

        retranslateUi(Niveles);

        QMetaObject::connectSlotsByName(Niveles);
    } // setupUi

    void retranslateUi(QWidget *Niveles)
    {
        Niveles->setWindowTitle(QCoreApplication::translate("Niveles", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pausa->setText(QString());
        Guardar->setText(QString());
        Salir->setText(QString());
        jugador1->setText(QString());
        jugador2->setText(QString());
        musica->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Niveles: public Ui_Niveles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELES_H
