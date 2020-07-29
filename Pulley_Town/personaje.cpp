#include "personaje.h"

Personaje::Personaje(int _tipo,int _posx,int _posy)
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
    v=10;
    a=40;
    posx=_posx;
    posy=_posy;
    miu=0.2;
    normal=60;
    t=0.5;
    alfa=1.24;
    vx=v*cos(alfa);
    vy=v*sin(alfa);
    t1=0;
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

void Personaje::friccion()
{
    pixmap->load(":/Imagenes/derecha1.png");
    posx=posx+v*t+a*pow(t,2)-miu*normal;
    setPos(posx,posy);
}

void Personaje::Saltar(){
    for(int i=0;i<28;i++){
        t1+=0.1;
        posx=posx+vx*t1;
        posy=posy-(vy*t1-5*pow(t1,2));
        setPos(posx,posy);
    }
    t1=0;
}

int Personaje::getx()
{
    return posx;
}

int Personaje::gety()
{
   return posy;
}
void Personaje::setx(int _x){
    posx=_x;
}
void Personaje::sety(int _y){
    posy=_y;
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










