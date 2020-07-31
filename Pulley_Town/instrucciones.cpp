#include "instrucciones.h"
#include "ui_instrucciones.h"

instrucciones::instrucciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::instrucciones)
{
    ui->setupUi(this);
}

instrucciones::~instrucciones()
{
    delete ui;
}

//Boton para salir
void instrucciones::on_pushButton_clicked()
{
    this->close();
}
