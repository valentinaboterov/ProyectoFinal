/********************************************************************************
** Form generated from reading UI file 'polea_ventana.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLEA_VENTANA_H
#define UI_POLEA_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Polea_ventana
{
public:
    QGraphicsView *graphicsView;
    QPushButton *Comparar;
    QLabel *label;
    QLCDNumber *masa1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *paquetes;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *Polea_ventana)
    {
        if (Polea_ventana->objectName().isEmpty())
            Polea_ventana->setObjectName(QString::fromUtf8("Polea_ventana"));
        Polea_ventana->resize(740, 400);
        Polea_ventana->setMaximumSize(QSize(740, 400));
        graphicsView = new QGraphicsView(Polea_ventana);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 600, 386));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMaximumSize(QSize(600, 386));
        graphicsView->setTabletTracking(false);
        graphicsView->setAcceptDrops(true);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        Comparar = new QPushButton(Polea_ventana);
        Comparar->setObjectName(QString::fromUtf8("Comparar"));
        Comparar->setGeometry(QRect(630, 330, 101, 41));
        label = new QLabel(Polea_ventana);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 210, 171, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setPointSize(6);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        masa1 = new QLCDNumber(Polea_ventana);
        masa1->setObjectName(QString::fromUtf8("masa1"));
        masa1->setGeometry(QRect(640, 170, 61, 41));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        masa1->setFont(font1);
        masa1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Polea_ventana);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(610, 30, 131, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("8514oem"));
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_3 = new QLabel(Polea_ventana);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 50, 101, 20));
        label_3->setFont(font2);
        paquetes = new QLabel(Polea_ventana);
        paquetes->setObjectName(QString::fromUtf8("paquetes"));
        paquetes->setGeometry(QRect(650, 80, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("8514oem"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        paquetes->setFont(font3);
        label_4 = new QLabel(Polea_ventana);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(630, 120, 141, 20));
        label_4->setFont(font2);
        label_5 = new QLabel(Polea_ventana);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(620, 140, 111, 20));
        label_5->setFont(font2);
        label_6 = new QLabel(Polea_ventana);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(650, 280, 81, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("8514oem"));
        font4.setBold(true);
        font4.setUnderline(false);
        font4.setWeight(75);
        label_6->setFont(font4);
        label_7 = new QLabel(Polea_ventana);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(620, 300, 121, 20));
        label_7->setFont(font2);
        label_8 = new QLabel(Polea_ventana);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(630, 260, 91, 16));
        QFont font5;
        font5.setFamily(QString::fromUtf8("8514oem"));
        font5.setPointSize(8);
        font5.setBold(true);
        font5.setUnderline(true);
        font5.setWeight(75);
        label_8->setFont(font5);

        retranslateUi(Polea_ventana);

        QMetaObject::connectSlotsByName(Polea_ventana);
    } // setupUi

    void retranslateUi(QWidget *Polea_ventana)
    {
        Polea_ventana->setWindowTitle(QCoreApplication::translate("Polea_ventana", "Form", nullptr));
        Comparar->setText(QCoreApplication::translate("Polea_ventana", "Comparar!", nullptr));
        label->setText(QCoreApplication::translate("Polea_ventana", "KILOS", nullptr));
        label_2->setText(QCoreApplication::translate("Polea_ventana", "CANTIDAD DE", nullptr));
        label_3->setText(QCoreApplication::translate("Polea_ventana", "PAQUETES:", nullptr));
        paquetes->setText(QString());
        label_4->setText(QCoreApplication::translate("Polea_ventana", "PARA UN", nullptr));
        label_5->setText(QCoreApplication::translate("Polea_ventana", "TOTAL DE:", nullptr));
        label_6->setText(QCoreApplication::translate("Polea_ventana", "SI ES", nullptr));
        label_7->setText(QCoreApplication::translate("Polea_ventana", "SUFICIENTE", nullptr));
        label_8->setText(QCoreApplication::translate("Polea_ventana", "AVERIGUA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Polea_ventana: public Ui_Polea_ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLEA_VENTANA_H
