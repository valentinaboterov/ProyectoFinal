/********************************************************************************
** Form generated from reading UI file 'cargar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGAR_H
#define UI_CARGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cargar
{
public:

    void setupUi(QWidget *Cargar)
    {
        if (Cargar->objectName().isEmpty())
            Cargar->setObjectName(QString::fromUtf8("Cargar"));
        Cargar->resize(400, 300);

        retranslateUi(Cargar);

        QMetaObject::connectSlotsByName(Cargar);
    } // setupUi

    void retranslateUi(QWidget *Cargar)
    {
        Cargar->setWindowTitle(QCoreApplication::translate("Cargar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cargar: public Ui_Cargar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGAR_H
