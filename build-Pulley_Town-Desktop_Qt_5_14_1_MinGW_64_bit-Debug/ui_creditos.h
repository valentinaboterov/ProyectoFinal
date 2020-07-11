/********************************************************************************
** Form generated from reading UI file 'creditos.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITOS_H
#define UI_CREDITOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Creditos
{
public:
    QLabel *label;

    void setupUi(QWidget *Creditos)
    {
        if (Creditos->objectName().isEmpty())
            Creditos->setObjectName(QString::fromUtf8("Creditos"));
        Creditos->resize(637, 900);
        Creditos->setMaximumSize(QSize(700, 900));
        label = new QLabel(Creditos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 637, 898));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Creditos.jpeg")));
        label->setScaledContents(true);

        retranslateUi(Creditos);

        QMetaObject::connectSlotsByName(Creditos);
    } // setupUi

    void retranslateUi(QWidget *Creditos)
    {
        Creditos->setWindowTitle(QCoreApplication::translate("Creditos", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Creditos: public Ui_Creditos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITOS_H
