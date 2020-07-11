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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Niveles
{
public:

    void setupUi(QWidget *Niveles)
    {
        if (Niveles->objectName().isEmpty())
            Niveles->setObjectName(QString::fromUtf8("Niveles"));
        Niveles->resize(400, 300);

        retranslateUi(Niveles);

        QMetaObject::connectSlotsByName(Niveles);
    } // setupUi

    void retranslateUi(QWidget *Niveles)
    {
        Niveles->setWindowTitle(QCoreApplication::translate("Niveles", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Niveles: public Ui_Niveles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELES_H
