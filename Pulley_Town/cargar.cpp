#include "cargar.h"
#include "ui_cargar.h"

Cargar::Cargar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cargar)
{
    ui->setupUi(this);
}

Cargar::~Cargar()
{
    delete ui;
}
