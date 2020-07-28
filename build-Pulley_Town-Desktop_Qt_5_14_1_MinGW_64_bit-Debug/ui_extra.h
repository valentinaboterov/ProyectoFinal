/********************************************************************************
** Form generated from reading UI file 'extra.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRA_H
#define UI_EXTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Extra
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Extra)
    {
        if (Extra->objectName().isEmpty())
            Extra->setObjectName(QString::fromUtf8("Extra"));
        Extra->resize(400, 220);
        Extra->setMaximumSize(QSize(1400, 220));
        graphicsView = new QGraphicsView(Extra);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 401, 440));
        graphicsView->setMaximumSize(QSize(16777215, 440));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        retranslateUi(Extra);

        QMetaObject::connectSlotsByName(Extra);
    } // setupUi

    void retranslateUi(QWidget *Extra)
    {
        Extra->setWindowTitle(QCoreApplication::translate("Extra", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Extra: public Ui_Extra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRA_H
