#include "perdedor.h"
#include "ui_perdedor.h"

Perdedor::Perdedor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Perdedor)
{
    ui->setupUi(this);
    setWindowTitle("Perdedor");
}

Perdedor::~Perdedor()
{
    delete ui;
}

void Perdedor::Causa(int _mensaje)
{
    if(_mensaje==0){        //Pierde por choque con pendulo
        texto="Lo siento";
        ui->mensaje->setText(texto);
        texto="Chocaste con un pendulo!";
        ui->mensaje1->setText(texto);
    }
    if(_mensaje==1){        //Pierde por choque con resorte
        texto="Lo siento";
        ui->mensaje->setText(texto);
        texto="Chocaste con un resorte!";
        ui->mensaje1->setText(texto);
    }
    if(_mensaje==2){        //Se acaba el tiempo
        texto="Lo siento";
        ui->mensaje->setText(texto);
        texto="Tu tiempo se acabo!";
        ui->mensaje1->setText(texto);
    }
    if(_mensaje==3){        //No es suficiente contrapeso
        texto="Lo siento";
        ui->mensaje->setText(texto);
        texto="El peso recolectado no fue suficiente!";
        ui->mensaje1->setText(texto);
    }
}

void Perdedor::on_pushButton_clicked()
{

}

void Perdedor::on_pushButton_2_clicked()
{

}
