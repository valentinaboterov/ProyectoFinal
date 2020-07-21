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
        paquetes->setGeometry(QRect(160, 10, 51, 31));

        retranslateUi(Niveles);

        QMetaObject::connectSlotsByName(Niveles);
    } // setupUi

    void retranslateUi(QWidget *Niveles)
    {
        Niveles->setWindowTitle(QCoreApplication::translate("Niveles", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Niveles: public Ui_Niveles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELES_H
