#include "pendulo.h"

Pendulo::Pendulo(int _x, int _y, float _longitud, float _theta)
{
    posA[0]=_x;
    posA[1]=_y;
    longitud=_longitud;
    theta=_theta;
    theta0=_theta;
    R=10;
    w=sqrt(9.8/longitud);
    t=0;
    posB[0]=posA[0]+longitud*sin(theta*rad);
    posB[1]=posA[1]+longitud*cos(theta*rad);
}
QRectF Pendulo::boundingRect() const
{
        return QRectF(posB[0],posB[1],50*R,50*R);
}

void Pendulo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);        //asigna el color
    painter->drawLine(posA[0],posA[1],posB[0],posB[1]); //dibuja la cuerda
    painter->drawEllipse(posB[0],posB[1], 2*R,2*R);    //dibuja una elipse encerrada en la boundingRect
}
void Pendulo::actualizar(){//actualiza posiciones y aceleracion y angulo
    t+=30;
    theta=theta0*cos(w*(t/1000.0));
    posB[0]=posA[0]+longitud*sin(theta*rad);
    posB[1]=posA[1]+longitud*cos(theta*rad);
    this->update(posA[0],posA[1],posB[0],posB[1]);
}


float Pendulo::getx(){//retorna pos x
    return posA[0];
}

float Pendulo::gety(){//retorna pos y
    return posA[1];
}

float Pendulo::getR(){//retorna el radio
    return R;
}

float Pendulo::getL(){//retorna el largo
    return longitud;
}
