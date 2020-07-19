#include "pesos.h"
#include "niveles.h"
extern Niveles *nivel;


//Inicializar variables.
Pesos::Pesos(int x,int y)
{
    setPos(x,y);
    ancho=30;
    alto=32;
    pixmap = new QPixmap(":/Imagenes/peso.png");
}
//Funciones propias de QT:
//Generar cuadrados para poner imagen.
QRectF Pesos::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}
//Pinta la imagen guardada en pixmap.
void Pesos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,0,0,ancho,alto);
}


