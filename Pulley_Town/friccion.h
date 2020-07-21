#ifndef FRICCION_H
#define FRICCION_H

#include"personaje.h"
#include <QGraphicsItem>
#include <QPainter>
#include<QPixmap>
#include<vector>
#include<QGraphicsView>

class Friccion:public QGraphicsItem
{
public:
    Friccion(int _x,int _y);
private:
    int x,y;
    float ancho,alto;
    QPixmap *pixmap;
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto

};

#endif // FRICCION_H
