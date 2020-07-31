#include "plataforma.h"

//Inicializacion
plataforma::plataforma(int _x, int _y)
{
    x=_x;
    y=_y;
    pixmap=new QPixmap(":/Imagenes/station.png");
    ancho=80;
    alto=40;
}

//Grafica
QRectF plataforma::boundingRect() const
{
    return QRectF(x,y,ancho,alto);
}

void plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(x,y,*pixmap,0,0,ancho,alto);

}
