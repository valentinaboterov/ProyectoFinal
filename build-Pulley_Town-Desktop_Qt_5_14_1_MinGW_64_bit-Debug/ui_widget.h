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
    QPushButton *Creditos;
    QPushButton *Registro;
    QPushButton *Inicarsesion;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(852, 480);
        Widget->setMaximumSize(QSize(852, 480));
        Widget->setAutoFillBackground(false);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 852, 480));
        label->setMaximumSize(QSize(852, 480));
        label->setAutoFillBackground(false);
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondoinicio.jpeg")));
        label->setScaledContents(true);
        Creditos = new QPushButton(Widget);
        Creditos->setObjectName(QString::fromUtf8("Creditos"));
        Creditos->setGeometry(QRect(620, 400, 100, 40));
        Registro = new QPushButton(Widget);
        Registro->setObjectName(QString::fromUtf8("Registro"));
        Registro->setGeometry(QRect(380, 400, 121, 40));
        Inicarsesion = new QPushButton(Widget);
        Inicarsesion->setObjectName(QString::fromUtf8("Inicarsesion"));
        Inicarsesion->setGeometry(QRect(110, 400, 121, 40));
        QWidget::setTabOrder(Inicarsesion, Creditos);
        QWidget::setTabOrder(Creditos, Registro);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        Creditos->setText(QCoreApplication::translate("Widget", "Creditos", nullptr));
        Registro->setText(QCoreApplication::translate("Widget", "Registro", nullptr));
        Inicarsesion->setText(QCoreApplication::translate("Widget", "Iniciar sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
