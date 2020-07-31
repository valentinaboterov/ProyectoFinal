#include "puente.h"

//Inicilizacion
Puente::Puente(int _x,int _y)
{
    x=_x;
    y=_y;
    pixmap=new QPixmap(":/Imagenes/puente.png");
    ancho=46;
    alto=20;
}
//Grafica
QRectF Puente::boundingRect() const
{
    return QRectF(x,y,ancho,alto);
}

void Puente::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(x,y,*pixmap,0,0,ancho,alto);

}
