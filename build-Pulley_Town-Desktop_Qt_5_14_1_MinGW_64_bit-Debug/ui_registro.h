/********************************************************************************
** Form generated from reading UI file 'registro.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_H
#define UI_REGISTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registro
{
public:
    QLabel *Nombre;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *Clave;
    QLabel *label_3;
    QPushButton *Entrar;
    QLabel *label;
    QLabel *Mensaje;

    void setupUi(QWidget *Registro)
    {
        if (Registro->objectName().isEmpty())
            Registro->setObjectName(QString::fromUtf8("Registro"));
        Registro->resize(400, 148);
        Registro->setMaximumSize(QSize(400, 300));
        Nombre = new QLabel(Registro);
        Nombre->setObjectName(QString::fromUtf8("Nombre"));
        Nombre->setGeometry(QRect(10, 20, 181, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setPointSize(5);
        Nombre->setFont(font);
        Nombre->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(Registro);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 20, 171, 21));
        lineEdit_2 = new QLineEdit(Registro);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 50, 171, 21));
        Clave = new QLabel(Registro);
        Clave->setObjectName(QString::fromUtf8("Clave"));
        Clave->setGeometry(QRect(70, 50, 111, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("8514oem"));
        Clave->setFont(font1);
        Clave->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(Registro);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 400, 300));
        label_3->setMaximumSize(QSize(400, 300));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Fondoregistro.jpg")));
        label_3->setScaledContents(true);
        Entrar = new QPushButton(Registro);
        Entrar->setObjectName(QString::fromUtf8("Entrar"));
        Entrar->setGeometry(QRect(150, 80, 80, 22));
        label = new QLabel(Registro);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 120, 47, 14));
        Mensaje = new QLabel(Registro);
        Mensaje->setObjectName(QString::fromUtf8("Mensaje"));
        Mensaje->setGeometry(QRect(170, 120, 47, 14));
        label_3->raise();
        Nombre->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        Clave->raise();
        Entrar->raise();
        label->raise();
        Mensaje->raise();

        retranslateUi(Registro);

        QMetaObject::connectSlotsByName(Registro);
    } // setupUi

    void retranslateUi(QWidget *Registro)
    {
        Registro->setWindowTitle(QCoreApplication::translate("Registro", "Form", nullptr));
        Nombre->setText(QCoreApplication::translate("Registro", "Nombre de usuario:", nullptr));
        Clave->setText(QCoreApplication::translate("Registro", "Clave:", nullptr));
        label_3->setText(QString());
        Entrar->setText(QCoreApplication::translate("Registro", "Entrar", nullptr));
        label->setText(QString());
        Mensaje->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Registro: public Ui_Registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H
