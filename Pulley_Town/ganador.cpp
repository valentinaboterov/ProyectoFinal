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
