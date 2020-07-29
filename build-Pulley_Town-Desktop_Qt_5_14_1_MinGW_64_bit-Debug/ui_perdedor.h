/********************************************************************************
** Form generated from reading UI file 'perdedor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERDEDOR_H
#define UI_PERDEDOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Perdedor
{
public:
    QLabel *label;
    QPushButton *cerrar;
    QLabel *label_2;
    QLabel *mensaje;
    QLabel *mensaje1;
    QLabel *nombre;

    void setupUi(QWidget *Perdedor)
    {
        if (Perdedor->objectName().isEmpty())
            Perdedor->setObjectName(QString::fromUtf8("Perdedor"));
        Perdedor->resize(400, 600);
        Perdedor->setMaximumSize(QSize(400, 600));
        label = new QLabel(Perdedor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -10, 400, 600));
        label->setMaximumSize(QSize(400, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondoperdedor.jpeg")));
        label->setScaledContents(true);
        cerrar = new QPushButton(Perdedor);
        cerrar->setObjectName(QString::fromUtf8("cerrar"));
        cerrar->setGeometry(QRect(140, 500, 131, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setBold(true);
        font.setWeight(75);
        cerrar->setFont(font);
        label_2 = new QLabel(Perdedor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 450, 231, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("8514oem"));
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"background-color: rgb(214, 214, 214);"));
        mensaje = new QLabel(Perdedor);
        mensaje->setObjectName(QString::fromUtf8("mensaje"));
        mensaje->setGeometry(QRect(150, 420, 111, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("8514oem"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        mensaje->setFont(font2);
        mensaje->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 8pt \"8514oem\";\n"
"background-color: rgb(214, 214, 214);"));
        mensaje1 = new QLabel(Perdedor);
        mensaje1->setObjectName(QString::fromUtf8("mensaje1"));
        mensaje1->setGeometry(QRect(30, 390, 351, 20));
        mensaje1->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 8pt \"8514oem\";\n"
"background-color: rgb(214, 214, 214);\n"
""));
        nombre = new QLabel(Perdedor);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(140, 360, 131, 21));
        nombre->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"background-color: rgb(214, 214, 214);\n"
"font: 8pt \"8514oem\";"));

        retranslateUi(Perdedor);

        QMetaObject::connectSlotsByName(Perdedor);
    } // setupUi

    void retranslateUi(QWidget *Perdedor)
    {
        Perdedor->setWindowTitle(QCoreApplication::translate("Perdedor", "Form", nullptr));
        label->setText(QString());
        cerrar->setText(QCoreApplication::translate("Perdedor", "CERRAR", nullptr));
        label_2->setText(QCoreApplication::translate("Perdedor", "VUELVE A INTENTARLO!", nullptr));
        mensaje->setText(QString());
        mensaje1->setText(QString());
        nombre->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Perdedor: public Ui_Perdedor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERDEDOR_H
