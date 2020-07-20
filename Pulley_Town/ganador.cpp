#include "ganador.h"
#include "ui_ganador.h"

Ganador::Ganador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ganador)
{
    ui->setupUi(this);
}

Ganador::~Ganador()
{
    delete ui;
}
