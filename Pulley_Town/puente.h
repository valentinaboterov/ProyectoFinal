#ifndef PUENTE_H
#define PUENTE_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include<QPixmap>

class Puente:public QGraphicsItem
{
public:
    Puente(int _x,int _y);
private:
    int x,y;
    float ancho,alto;
    QPixmap *pixmap;
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
};

#endif // PUENTE_H
