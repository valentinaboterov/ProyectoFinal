#include "niveles.h"
#include "ui_niveles.h"

Niveles::Niveles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Niveles)

{
    ui->setupUi(this);
    /*
    if(dificultad==0 && modojuego==0){ //Novato,un solo jugador

    }
    if(dificultad==0 && modojuego==1){ //Novato,multijugador

    }
    if(dificultad==1 && modojuego==0){ //Aprendiz,un solo jugador

    }
    if(dificultad==1 && modojuego==1){ //Aprendiz,multijugador jugador

    }
    if(dificultad==2 && modojuego==0){ //Experto ,un solo jugador

    }
    if(dificultad==2 && modojuego==1){ //Experto,multijugador

    }
    */
}

Niveles::~Niveles()
{
    delete ui;
}

void Niveles::Definicion(int nivel, int modo)
{
    dificultad=nivel;
    modojuego=modo;
}
