#include "resorte.h"
//RECIBE LA MAXIMA ELONGACION DON QUIERO QUE ESTE +40 en x
Resorte::Resorte(int _x,int _y,float _m,float _k,float _amplitud,int _modo)
{
    x0=_x;
    y0=_y;
    k=_k;
    m=_m;
    w=sqrt(k/m);
    modo=_modo;
    t=0;
    amplitud=_amplitud;
    if(modo==0){ //horizontal
        posA[0]=x0;
        posA[1]=y0;
        pos[0]=x0-amplitud;
        pos[1]=y0;
    }else{
        posA[0]=x0;
        posA[1]=y0;
        pos[0]=x0;
        pos[1]=y0-amplitud;
    }
}
QRectF Resorte::boundingRect() const
{
    if(modo==0){
        return QRectF(posA[0],posA[1]-10,20,20);
    }
    else{
        return QRectF(posA[0]-10,posA[1],20,20);
    }
}

void Resorte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);        //asigna el color
    painter->drawLine(pos[0],pos[1],posA[0],posA[1]); //dibuja la cuerda
    if(modo==0){
        painter->drawRect(posA[0],posA[1]-10,20,20);    //dibuja una elipse encerrada en la boundingRect
    }else{
        painter->drawRect(posA[0]-10,posA[1],20,20);    //dibuja una elipse encerrada en la boundingRect
    }
    }
void Resorte::actualizar(){//actualiza posiciones y aceleracion y angulo
    t+=0.001;
    if(modo==0){
        posA[0]=x0+amplitud*sin(w*t);
    }else{
        posA[1]=y0+amplitud*sin(w*t);
    }

    this->update();
}


float Resorte::getx(){//retorna pos x
    return posA[0];
}

float Resorte::gety(){//retorna pos y
    return posA[1];
}
