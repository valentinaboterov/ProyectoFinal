#include "modojuego.h"
#include "ui_modojuego.h"

Modojuego::Modojuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modojuego)
{
    ui->setupUi(this);
    setWindowTitle("Modo de juego");
    modo=0; //Un jugador por defecto
    nivel=new Niveles;
}

Modojuego::~Modojuego()
{
    delete ui;
}



void Modojuego::on_Jugador_clicked()
{
    modo=0;
}

void Modojuego::on_Multijugador_clicked()
{
    modo=1;
}

void Modojuego::on_Novato_clicked()
{
    nivel->Definicion(0,modo);
}

void Modojuego::on_Aprendiz_clicked()
{
    nivel->Definicion(1,modo);
}

void Modojuego::on_Experto_clicked()
{
    nivel->Definicion(2,modo);
}

void Modojuego::on_Empezar_clicked()
{

}


