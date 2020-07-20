#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include<QPixmap>

class plataforma:public QGraphicsItem
{
public:
    plataforma(int _x,int _y);
private:
    int x,y;
    float ancho,alto;
    QPixmap *pixmap;
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
};

#endif // PLATAFORMA_H
