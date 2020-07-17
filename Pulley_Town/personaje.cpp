#include "personaje.h"

Personaje::Personaje(QObject *parent) : QObject(parent)
{
    timer = new QTimer();   //Variable para cambiar imagenes con el tiempo
    filas = 0;
    columnas=0;
    pixmap = new QPixmap(":/Imagenes/j1_inicio.png");
    //Dimensiones de cada imagen.
    ancho = 60;
    alto  = 80;
    vx=10;
    vy=10;
    posx=345;
    posy=500;
    t=0;
    //timer->start(100);
    //Se conecta el tiempo y el slot de actualizar la foto.
    connect(timer,&QTimer::timeout,this,&Personaje::Actualizacion);

}
//Actualiza las fotos:
void Personaje::Actualizacion()
{
    columnas +=80;
    if(columnas >=320)
    {
        columnas=0;
    }
    //Se refresca la información.
    this->update(-ancho/2,-alto/2,ancho,alto);
}
//Movimiento
void Personaje::Up()    //Arriba
{
    for(int i=0;i<20;i++){
        t+=16;
        posx=posx+vx*t;
        posy=posy+vy*t+4.9*pow(t,2);
        this->update();
        setPos(posx,posy);
    }

}

void Personaje::Down() //Abajo
{
    posy +=10;
    setPos(posx,posy);
}

void Personaje::Left()  //Izquierda
{
    pixmap->load(":/Imagenes/c_izqu.png");
    posx -= 10;
    this->update();
    setPos(posx,posy);
}

void Personaje::Rigth() //Derecha
{
    posx += 10;
    setPos(posx,posy);
}

int Personaje::getx()
{
    return posx;
}

int Personaje::gety()
{
   return posy;
}
//Funciones propias de QT:
QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}
//Pinta la imagen guardada en pixmap.
void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}










