#ifndef PENDULO_H
#define PENDULO_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<math.h>
#include <stdlib.h>
#include <time.h>

class Pendulo:public QGraphicsItem
{
private:
    float theta;
    float w;
    float ao;
    float X;
    float Y;
    float L;
    float R;
    float escala;//se crea una escala
    int x0,y0;
public:
    Pendulo(int _x,int _y);
    float getx();
    float gety();
    float getR();
    float getL();
    void actualizar();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
};

#endif // PENDULO_H
