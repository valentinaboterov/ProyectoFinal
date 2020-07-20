#include "resorte.h"
//RECIBE LA MAXIMA ELONGACION DON QUIERO QUE ESTE +40 en x
Resorte::Resorte(int _x,int _y,float _m,float _k,float _amplitud)
{
    x0=_x;
    y0=_y;
    x0=_x;
    y0=_y;
    k=_k;
    m=_m;
    w=sqrt(k/m);
    R=10;
    t=0;
    amplitud=_amplitud;
    posE[0]=x0;
    posE[1]=y0;
    posD[0]=posE[0]-10;
    posD[1]=posE[1]-10;
    posC[0]=posD[0]-10;
    posC[1]=posD[1]+20;
    posB[0]=posC[0]-10;
    posB[1]=posC[1]-20;
    posA[0]=posB[0]-10;
    posA[1]=posB[1]+10;
    pos[0]=posA[0]-10;
    pos[1]=posA[1];
}
QRectF Resorte::boundingRect() const
{
        return QRectF(posE[0],posE[1]-10,20,20);
}

void Resorte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);        //asigna el color
    painter->drawLine(pos[0],pos[1],posA[0],posA[1]);
    painter->drawLine(posA[0],posA[1],posB[0],posB[1]); //dibuja la cuerda
    painter->drawLine(posB[0],posB[1],posC[0],posC[1]); //dibuja la cuerda
    painter->drawLine(posC[0],posC[1],posD[0],posD[1]); //dibuja la cuerda
    painter->drawLine(posD[0],posD[1],posE[0],posE[1]); //dibuja la cuerda
    painter->drawRect(posE[0],posE[1]-10,20,20);    //dibuja una elipse encerrada en la boundingRect
   }
void Resorte::actualizar(){//actualiza posiciones y aceleracion y angulo
    t+=0.001;
    posE[0]=x0+amplitud*sin(w*t);
    posD[0]=posE[0]-10;
    posC[0]=posD[0]-10;
    posB[0]=posC[0]-10;
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
