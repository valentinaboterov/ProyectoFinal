/*
Dibuja los pesos que el usuario debe coger.
*/

#ifndef PESOS_H
#define PESOS_H

#include <QGraphicsItem>
#include <QPainter>
#include<QPixmap>
#include<vector>
#include<QGraphicsView>
class Pesos: public QGraphicsView,public QGraphicsItem
{
public:
    Pesos(int x,int y);   //Recibe la posición en la cual se va a mostrar en la ventana.
    float ancho;
    float alto;
    QPixmap *pixmap;    //Grafica las monedas en pantalla.
    QRectF boundingRect() const;    //Genera cuadrados
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//Pinta las monedas
};

#endif // PESOS_H
