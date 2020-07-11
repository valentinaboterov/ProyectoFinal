#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("PULLEY TOWN");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Jugador_clicked()
{
    registro.tipo(0,tipo);
    registro.validacion();
    this->close();
}

void Widget::on_Multi_clicked()
{
    registro.tipo(1,tipo);
    registro.validacion();
    this->close();
}

void Widget::on_Creditos_clicked()
{
    creditos.show();
}

void Widget::on_Registro_clicked()
{
    tipo=0;
}

void Widget::on_Inicarsesion_clicked()
{
    tipo=1;
}
