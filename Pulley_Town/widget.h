#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"modojuego.h"
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

    void on_Registro_clicked();

    void on_Creditos_clicked();

    void on_Cargarpartida_clicked();

private:
    Ui::Widget *ui;
    Modojuego modo;
    Creditos creditos;
};
#endif // WIDGET_H
