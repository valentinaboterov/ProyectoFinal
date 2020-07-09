#include "widget.h"
#include "ui_widget.h"
#include"registro.h"


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

void Widget::on_Registro_clicked()
{
    modo.show();
    this->close();
}

void Widget::on_Creditos_clicked()
{
    creditos.show();
}

void Widget::on_Cargarpartida_clicked()
{

}
