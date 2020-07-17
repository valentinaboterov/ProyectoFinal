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
    QLCDNumber *lcdNumber;
    QLabel *label;

    void setupUi(QWidget *Niveles)
    {
        if (Niveles->objectName().isEmpty())
            Niveles->setObjectName(QString::fromUtf8("Niveles"));
        Niveles->setWindowModality(Qt::NonModal);
        Niveles->resize(800, 800);
        Niveles->setMaximumSize(QSize(800, 800));
        graphicsView = new QGraphicsView(Niveles);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 50, 800, 750));
        graphicsView->setMaximumSize(QSize(800, 800));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lcdNumber = new QLCDNumber(Niveles);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(90, 10, 91, 31));
        label = new QLabel(Niveles);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 61, 16));

        retranslateUi(Niveles);

        QMetaObject::connectSlotsByName(Niveles);
    } // setupUi

    void retranslateUi(QWidget *Niveles)
    {
        Niveles->setWindowTitle(QCoreApplication::translate("Niveles", "Form", nullptr));
        label->setText(QCoreApplication::translate("Niveles", "TIEMPO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Niveles: public Ui_Niveles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELES_H
