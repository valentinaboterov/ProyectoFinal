#include "personaje.h"

Personaje::Personaje(QObject *parent) : QObject(parent)
{
    timer = new QTimer();   //Variable para cambiar el pacman con el tiempo(Hacer el parezca comiendo)
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/Imagenes/c_izqu.png");

    //Dimensiones de cada imagen.
    ancho = 50;
    alto  = 50;
    posx=345;
    posy=500;
    timer->start(100); //Modifica la velocidad en que itera entre las imagenes
    //Se conecta el tiempo y el slot de actualizar la foto.
    connect(timer,&QTimer::timeout,this,&Personaje::Actualizacion);
}
//Actualiza las fotos:
/* La imagen guardada en recursos es una imagen de 400x100
Cada 100 de ancho hay una figura de PACMAN en diferente posicion.
La funioón incrementa de a 100pixeles por cada timer para que el
pacman se vea comiendo, además cuando llega a 400 vuelve a empezar.
*/
void Personaje::Actualizacion()
{
    columnas +=50;
    if(columnas >=200)
    {
        columnas =0;
    }
    //Se refresca la información.
    this->update(-ancho/2,-alto/2,ancho,alto);

}
//Movimiento del pacman.
//Adiciona o resta 10 posiciones según la letra.
void Personaje::Up()    //Arriba
{
    posy -=25;
    setPos(posx,posy);
}

void Personaje::Down() //Abajo
{
    posy +=25;
    setPos(posx,posy);
}

void Personaje::Left()  //Izquierda
{
    posx -= 25;
    setPos(posx,posy);
}

void Personaje::Rigth() //Derecha
{
    posx += 25;
    setPos(posx,posy);
}
//Funciones propias de QT:
//Organiza la ventana por cuadros.
QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}
//Pinta la imagen guardada en pixmap.
void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}










