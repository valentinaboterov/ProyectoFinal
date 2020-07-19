#ifndef RESORTE_H
#define RESORTE_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<math.h>
#include<QTimer>


class Resorte:public QGraphicsItem
{
private:
    int pos[2],posA[2],posB[2],posC[2],posD[2],posE[2],R,x0,y0;
    float longitud,k,w,t,m;
public:
    Resorte(int _x,int _y,float _w,float _amplitud);
    float getx();
    float gety();
    float getR();
    float getL();
    void actualizar();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto


};

#endif // RESORTE_H
