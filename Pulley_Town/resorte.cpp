#include "resorte.h"

Resorte::Resorte(int _x, int _y,float _m, float _k)
{
    posA[0]=_x;
    posA[1]=_y;
    x0=_x;
    y0=_y;
    k=_k;
    m=_m;
    w=sqrt(k/m);
    R=10;
    t=0;
    posB[0]=posA[0]+5;
    posB[1]=posA[1]-5;
    posC[0]=posB[0]+5;
    posC[1]=posB[1]+10;
    posD[0]=posC[0]+5;
    posD[1]=posC[1]-10;
    posE[0]=posD[0]+5;
    posE[1]=posD[1]+5;
}
QRectF Resorte::boundingRect() const
{
        return QRectF(posE[0],posE[1]-10,50*R,50*R);
}

void Resorte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);        //asigna el color
    painter->drawLine(posA[0],posA[1],posB[0],posB[1]); //dibuja la cuerda

    painter->drawLine(posB[0],posB[1],posC[0],posC[1]); //dibuja la cuerda
    painter->drawLine(posC[0],posC[1],posD[0],posD[1]); //dibuja la cuerda
    painter->drawLine(posD[0],posD[1],posE[0],posE[1]); //dibuja la cuerda
    painter->drawRect(posE[0],posE[1]-10,2*R,2*R);    //dibuja una elipse encerrada en la boundingRect
}
void Resorte::actualizar(){//actualiza posiciones y aceleracion y angulo
    t+=30;
    t=t/1000.0;
    posE[0]=posE[0]*sin(w*t);
    posD[0]=posD[0]*sin(w*t);
    posC[0]=posC[0]*sin(w*t);
    posB[0]=posB[0]*sin(w*t);
    posA[0]=posA[0]*sin(w*t);
    this->update();
}


float Resorte::getx(){//retorna pos x
    return posA[0];
}

float Resorte::gety(){//retorna pos y
    return posA[1];
}

float Resorte::getR(){//retorna el radio
    return R;
}

float Resorte::getL(){//retorna el largo
    return longitud;
}
