#include "puente.h"

Puente::Puente(int _x,int _y)
{
    x=_x;
    y=_y;
    pixmap=new QPixmap(":/Imagenes/puente.png");
    ancho=30;
    alto=20;
}
QRectF Puente::boundingRect() const
{
    return QRectF(x,y,ancho,alto);
}

void Puente::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(x,y,*pixmap,0,0,ancho,alto);

}
