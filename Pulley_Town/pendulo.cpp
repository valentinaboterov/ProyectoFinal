#include "pendulo.h"

Pendulo::Pendulo(int _x,int _y) : escala(1)
{
    x0=_x;y0=_y;
    setPos(_x, _y);
    srand(time(NULL));//todo aleatorio
    theta =(45+(rand()%45))*(3.14/360);//se pone el angulo
    w= 10+rand()%191;//la velocidad angular
    L = 100;//longitud
    R = 5+(rand()%16);//radio
    X = L*sin(theta);//posicion en x
    Y = -L*cos(theta);//posicion en y
    ao = w/L;//aceleracion angular
}
QRectF Pendulo::boundingRect() const
{
        return QRectF(-10*escala*R,-10*escala*R,20*escala*R,20*escala*R);
}

void Pendulo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);        //asigna el color
    painter->drawLine(0,0,-1*x(),-1*y()); //dibuja la cuerda
    painter->drawEllipse(-10,-10, 2*R,2*R);    //dibuja una elipse encerrada en la boundingRect
}
void Pendulo::actualizar(){//actualiza posiciones y aceleracion y angulo
    theta = theta +(ao*0.01);
    X= L*sin(theta);
    Y= -L*cos(theta);
    ao -= (9.8)*sin(theta)*0.01;
    w=w+(ao*0.1);
    setPos(X,Y);// actualiza posiciones en la interfaz
}
float Pendulo::getx(){//retorna pos x
    return X;
}

float Pendulo::gety(){//retorna pos y
    return Y;
}

float Pendulo::getR(){//retorna el radio
    return R;
}

float Pendulo::getL(){//retorna el largo
    return L;
}
