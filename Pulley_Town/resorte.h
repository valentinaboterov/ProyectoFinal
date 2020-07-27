/*
Genera el resorte de los niveles.
*/

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
    int pos[2],posA[2],modo,x0,y0;
    float k,w,t,m,amplitud;
public:
    Resorte(int _x,int _y,float _m,float _k,float _amplitud,int _modo); //Inicializacion
    float getx();
    float gety();
    void actualizar();  //Movimiento.
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto


};

#endif // RESORTE_H
