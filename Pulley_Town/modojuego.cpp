#include "modojuego.h"
#include "ui_modojuego.h"

Modojuego::Modojuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modojuego)
{
    ui->setupUi(this);
    setWindowTitle("Modo de juego");
}

Modojuego::~Modojuego()
{
    delete ui;
}



void Modojuego::on_Jugador_clicked()
{

}

void Modojuego::on_Multijugador_clicked()
{

}

void Modojuego::on_Novato_clicked()
{

}

void Modojuego::on_Aprendiz_clicked()
{

}

void Modojuego::on_Experto_clicked()
{

}

void Modojuego::on_Empezar_clicked()
{

}


