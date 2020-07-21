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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *mensaje;
    QLabel *mensaje1;

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
        pushButton = new QPushButton(Perdedor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 470, 131, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Perdedor);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 470, 131, 51));
        pushButton_2->setFont(font);
        label_2 = new QLabel(Perdedor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 420, 311, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("8514oem"));
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 0);"));
        mensaje = new QLabel(Perdedor);
        mensaje->setObjectName(QString::fromUtf8("mensaje"));
        mensaje->setGeometry(QRect(140, 370, 101, 20));
        mensaje->setFont(font);
        mensaje->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 0);"));
        mensaje1 = new QLabel(Perdedor);
        mensaje1->setObjectName(QString::fromUtf8("mensaje1"));
        mensaje1->setGeometry(QRect(100, 390, 211, 20));
        mensaje1->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 0);\n"
"font: 75 8pt \"MS Shell Dlg 2\";"));

        retranslateUi(Perdedor);

        QMetaObject::connectSlotsByName(Perdedor);
    } // setupUi

    void retranslateUi(QWidget *Perdedor)
    {
        Perdedor->setWindowTitle(QCoreApplication::translate("Perdedor", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Perdedor", "SI", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Perdedor", "NO", nullptr));
        label_2->setText(QCoreApplication::translate("Perdedor", "Deseas volver a intentarlo?", nullptr));
        mensaje->setText(QString());
        mensaje1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Perdedor: public Ui_Perdedor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERDEDOR_H
