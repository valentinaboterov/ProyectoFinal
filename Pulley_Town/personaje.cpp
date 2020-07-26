#include "personaje.h"

Personaje::Personaje(int _tipo)
{
    timer = new QTimer();   //Variable para cambiar imagenes con el tiempo
    filas = 0;
    columnas=0;
    tipo=_tipo;
    if(_tipo==1){
        pixmap = new QPixmap(":/Imagenes/quieto.png");
    }else{
        pixmap = new QPixmap(":/Imagenes/quieto1.png");
    }
    //Dimensiones de cada imagen.
    ancho = 55;
    alto  = 70;
    v=20;
    a=5;
    posx=35;
    posy=75;
    miu=0.2;
    normal=100;
    t=0.5;
    timer->start(1000);
    //Se conecta el tiempo y el slot de actualizar la foto.
    connect(timer,&QTimer::timeout,this,&Personaje::Actualizacion);
}
//Actualiza las fotos:
void Personaje::Actualizacion()
{
    columnas +=60;
    if(columnas>=170)
    {
        columnas=0;
    }
    //Se refresca la información.
    this->update(-ancho/2,-alto/2,ancho,alto);
}
//Movimiento
void Personaje::Up()    //Arriba
{
    if(tipo==1){
        pixmap->load(":/Imagenes/arriba.png");
    }else{
        pixmap->load(":/Imagenes/arriba1.png");
    }

    posy-=10;
    setPos(posx,posy);
}

void Personaje::Down() //Abajo
{
    if(tipo==1){
        pixmap->load(":/Imagenes/abajo.png");
    }else{
        pixmap->load(":/Imagenes/abajo1.png");
    }
    posy +=10;
    setPos(posx,posy);
}

void Personaje::Left()  //Izquierda
{
    if(tipo==1){
        pixmap->load(":/Imagenes/izquierda.png");
    }else{
        pixmap->load(":/Imagenes/izquierda1.png");
    }
    posx=posx-v*t-a/2*pow(t,2);
    this->update();
    setPos(posx,posy);
}

void Personaje::Rigth() //Derecha
{
    if(tipo==1){
        pixmap->load(":/Imagenes/derecha.png");
    }else{
        pixmap->load(":/Imagenes/derecha1.png");
    }
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
    posx=posx+(v-20)*t+a/2*pow(t,2)-miu*normal;
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










