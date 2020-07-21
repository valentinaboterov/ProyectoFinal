#include "personaje.h"

Personaje::Personaje(QObject *parent) : QObject(parent)
{
    timer = new QTimer();   //Variable para cambiar imagenes con el tiempo
    filas = 0;
    columnas=0;
    pixmap = new QPixmap(":/Imagenes/quieto.png");
    //Dimensiones de cada imagen.
    ancho = 52;
    alto  = 70;
    v=20;
    a=5;
    posx=35;
    posy=75;
    miu=0.1;
    normal=150;
    t=0.5;
    timer->start(1000);
    //Se conecta el tiempo y el slot de actualizar la foto.
    connect(timer,&QTimer::timeout,this,&Personaje::Actualizacion);

}
//Actualiza las fotos:
void Personaje::Actualizacion()
{
    columnas +=54;
    if(columnas>=162)
    {
        columnas=0;
    }
    //Se refresca la información.
    this->update(-ancho/2,-alto/2,ancho,alto);
}
//Movimiento
void Personaje::Up()    //Arriba
{
    pixmap->load(":/Imagenes/arriba.png");
    posy-=10;
    setPos(posx,posy);
}

void Personaje::Down() //Abajo
{
    pixmap->load(":/Imagenes/abajo.png");
    posy +=10;
    setPos(posx,posy);
}

void Personaje::Left()  //Izquierda
{
    pixmap->load(":/Imagenes/izquierda.png");
    posx=posx-v*t-a/2*pow(t,2);
    this->update();
    setPos(posx,posy);
}

void Personaje::Rigth() //Derecha
{
    pixmap->load(":/Imagenes/derecha.png");
    posx=posx+v*t+a/2*pow(t,2);
    setPos(posx,posy);
}

void Personaje::puente()
{
    posx+=40;
}

void Personaje::friccion_derecha()
{
    pixmap->load(":/Imagenes/derecha.png");
    posx=posx+v*t+a/2*pow(t,2)-miu*normal;
    setPos(posx,posy);
}

void Personaje::friccion_izquierda()
{
    pixmap->load(":/Imagenes/izquierda.png");
    posx=posx-v*t-a/2*pow(t,2)+miu*normal;
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










