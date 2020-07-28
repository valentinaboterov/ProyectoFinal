/*
Genera los personajes y sus movimientos.
*/

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include<math.h>


class Personaje:public QObject,public QGraphicsItem
{
    Q_OBJECT
    int posx, posy;
public:
    Personaje(int _tipo,int _posx,int _posy);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    float t,t1,v,a,miu,normal,alfa,vx,vy;
    int tipo;
    //Movimiento
    void Up();
    void Down();
    void Left();
    void Rigth();
    void puente();
    void friccion();
    void Saltar();
    int getx();
    int gety();
    //Dibujar.
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();
};

#endif // PERSONAJE_H
