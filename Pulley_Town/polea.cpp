#include "polea.h"

Polea::Polea(int _x,int _y,int _masa1,int _nivel)
{
    x=_x;
    y=_y;
    pixmap = new QPixmap(":/Imagenes/polea.png");
    gravedad=9.8;
    masa1=_masa1;
    nivel=_nivel;
    if(nivel==0){
        masa2=40;
    }else if(nivel==1){
        masa2=50;
    }else if(nivel==2){
        masa2=100;
    }
    t1=masa1*gravedad;      //Tension masa fija
    t2=masa2*gravedad;      //Tension contrapeso
    ancho=200;
    alto=200;
    posA[0]=216;
    posA[1]=65;
    posA[2]=216;
    posA[3]=265;
    posB[0]=334;
    posB[1]=65;
    posB[2]=334;
    posB[3]=265;
}

void Polea::Comparacion()
{
    if(t1<t2){        //No es sufiente peso.
            posA[3]-=100;
            posB[3]+=100;
            this->update(posA[2],posA[3],posB[2],posB[3]);
    }
    if(t1>t2){       //Sufiente peso
            posA[3]+=100;
            posB[3]-=100;
            this->update(posA[2],posA[3],posB[2],posB[3]);
    }
}

int Polea::getx1()
{
    return posA[2];
}
int Polea::getx2()
{
    return posB[2];
}
int Polea::gety1()
{
    return posA[3];
}
int Polea::gety2()
{
    return posB[3];
}

QRectF Polea::boundingRect() const
{
    return QRectF(x,y,ancho,alto);
}

void Polea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);        //asigna el color
    painter->drawPixmap(x,y,*pixmap,0,0,ancho,alto);
    painter->drawLine(posA[0],posA[1],posA[2],posA[3]); //dibuja la cuerda
    painter->drawLine(posB[0],posB[1],posB[2],posB[3]); //dibuja la cuerda
    painter->drawRect(posA[2]-25,posA[3],50,50);
    painter->drawRect(posB[2]-25,posB[3],50,50);
}


