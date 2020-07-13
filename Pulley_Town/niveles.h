#ifndef NIVELES_H
#define NIVELES_H

using namespace std;
#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include <QDebug>
#include<QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QTimer>
#include <QKeyEvent>
#include"pendulo.h"
#include"personaje.h"
#include"pesos.h"


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
    QTimer *timer;
    Pendulo *pendulo;
    Personaje *personaje;
    Pesos *pesos;
    float x,y,ancho,alto;
    int modojuego,dificultad;
    void keyPressEvent(QKeyEvent * evento);
private slots:
    void actualizar();
};

#endif // NIVELES_H
