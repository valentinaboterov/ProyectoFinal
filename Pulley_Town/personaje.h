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
    Personaje(int _tipo);
    QTimer *timer;      //Variable para lograr que el pacman se vea comiendo
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    float t,v,a,miu,normal;
    int tipo;
    //Movimiento
    void Up();
    void Down();
    void Left();
    void Rigth();
    void puente();
    void friccion_izquierda();
    void friccion_derecha();
    int getx();
    int gety();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();

};

#endif // PERSONAJE_H
