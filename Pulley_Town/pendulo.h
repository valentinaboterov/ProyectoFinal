#ifndef PENDULO_H
#define PENDULO_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<math.h>
#include<QTimer>

class Pendulo:public QGraphicsItem
{
private:
    int posA[2],posB[2],R;
    float longitud,theta,a,w,rad=M_PI/180,t,theta0;
public:
    Pendulo(int _x,int _y,float _longitud,float _theta);
    float getx();
    float gety();
    float getR();
    float getL();
    void actualizar();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto


};

#endif // PENDULO_H
