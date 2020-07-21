#include "friccion.h"


Friccion::Friccion(int _x, int _y)
{
    x=_x;
    y=_y;
    pixmap=new QPixmap(":/Imagenes/charco.png");
    ancho=100;
    alto=100;
}

QRectF Friccion::boundingRect() const
{
    return QRectF(x,y,ancho,alto);
}

void Friccion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(x,y,*pixmap,0,0,ancho,alto);

}
