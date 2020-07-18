#include "polea.h"
#include "ui_polea.h"

Polea::Polea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Polea)
{
    ui->setupUi(this);
}

Polea::~Polea()
{
    delete ui;
}
