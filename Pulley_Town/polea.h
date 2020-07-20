#ifndef POLEA_H
#define POLEA_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include<QPixmap>
#include<math.h>



class Polea : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    Polea(int _x,int _y,int _masa1,int _nivel);
    void Comparacion();
    QGraphicsScene *escena;
    int getx1();
    int gety1();
    int getx2();
    int gety2();
private:
    QPixmap *pixmap;
    int nivel,x,y;
    int ancho,alto;
    float betha,masa1,gravedad,masa2,miu,t1,t2,tmin;
    int posA[4],posB[4]; //PosA:Fijo   PosB:usuario
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
};

#endif // POLEA_H
