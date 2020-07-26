#include "ganador.h"
#include "ui_ganador.h"

Ganador::Ganador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ganador)
{
    ui->setupUi(this);
    setWindowTitle("Ganador");
}

Ganador::~Ganador()
{
    delete ui;
}

void Ganador::Nombre(string _nombre)
{
    nombre=_nombre;
    QString texto1= QString::fromStdString(nombre);
    ui->nombre->setText(texto1);
}

void Ganador::on_menu_clicked()
{
    this->close();
}
