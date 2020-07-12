#ifndef NIVELES_H
#define NIVELES_H

using namespace std;
#include <QWidget>
#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include <QDebug>
#include<QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include"pendulo.h"
#include <QKeyEvent>



namespace Ui {
class Niveles;
}

class Niveles : public QWidget
{
    Q_OBJECT

public:
    explicit Niveles(QWidget *parent = nullptr);
    ~Niveles();
    void Definicion(int nivel,int modo);
    QGraphicsScene *escena;

private:
    Ui::Niveles *ui;
    Pendulo *pendulo;
    float x,y,ancho,alto;
    int modojuego,dificultad;
};

#endif // NIVELES_H
