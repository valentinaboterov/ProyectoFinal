#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class Personaje:public QObject,public QGraphicsItem
{
    Q_OBJECT
    int posx, posy;
public:
    explicit Personaje(QObject *parent = nullptr);
    QTimer *timer;      //Variable para lograr que el pacman se vea comiendo
    QPixmap *pixmap;
    float filas,columnas;
    float ancho;
    float alto;
    //Movimiento
    void Up();
    void Down();
    void Left();
    void Rigth();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();

};

#endif // PERSONAJE_H
