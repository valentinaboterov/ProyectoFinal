/*
Ventana principal.
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMessageBox>
#include"registro.h"
#include"creditos.h"
#include"extra.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int tipo=0; //Registro nuevo por defecto

private slots:
    //Botones:
   void on_Registro_clicked();  //Nuevo usuario.

    void on_Inicarsesion_clicked(); //Usuario antiguo

    void on_Creditos_clicked(); //Ver creditos.

    void on_practicar_clicked();

private:
    Ui::Widget *ui;
    Registro registro;
    Creditos creditos;
    Extra *extra=new Extra;
};
#endif // WIDGET_H
