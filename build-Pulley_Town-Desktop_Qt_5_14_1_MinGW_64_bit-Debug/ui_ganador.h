/********************************************************************************
** Form generated from reading UI file 'ganador.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANADOR_H
#define UI_GANADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ganador
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Ganador)
    {
        if (Ganador->objectName().isEmpty())
            Ganador->setObjectName(QString::fromUtf8("Ganador"));
        Ganador->resize(440, 600);
        Ganador->setMaximumSize(QSize(440, 600));
        Ganador->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Ganador);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 440, 600));
        label->setMaximumSize(QSize(440, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondoganador.jpeg")));
        label->setScaledContents(true);
        pushButton = new QPushButton(Ganador);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 420, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Ganador);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 420, 121, 41));
        pushButton_2->setFont(font);
        label_2 = new QLabel(Ganador);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 350, 181, 16));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(Ganador);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 370, 201, 21));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"background-color: rgb(255, 255, 255);"));

        retranslateUi(Ganador);

        QMetaObject::connectSlotsByName(Ganador);
    } // setupUi

    void retranslateUi(QWidget *Ganador)
    {
        Ganador->setWindowTitle(QCoreApplication::translate("Ganador", "Ganador", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Ganador", "SI", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Ganador", "NO", nullptr));
        label_2->setText(QCoreApplication::translate("Ganador", "FELICITACIONES!", nullptr));
        label_3->setText(QCoreApplication::translate("Ganador", "Quieres jugar otra vez?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ganador: public Ui_Ganador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANADOR_H
