#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"registro.h"
#include"creditos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Jugador_clicked();

    void on_Multi_clicked();

    void on_Creditos_clicked();

    void on_Registro_clicked();

    void on_Inicarsesion_clicked();

private:
    Ui::Widget *ui;
    Registro registro;
    Creditos creditos;
    int tipo=0; //Registro nuevo por defecto

};
#endif // WIDGET_H
