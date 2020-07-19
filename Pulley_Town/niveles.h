#ifndef NIVELES_H
#define NIVELES_H

#include <QWidget>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include<QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QTimer>
#include <QKeyEvent>
#include"pendulo.h"
#include"personaje.h"
#include"pesos.h"
#include"paredes.h"
#include"resorte.h"
#include"polea_ventana.h"
#include"puente.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Niveles;
}
QT_END_NAMESPACE

class Niveles : public QWidget
{
    Q_OBJECT

public:
    explicit Niveles(QWidget *parent = nullptr);
    ~Niveles();
    void Definicion(int nivel,int modo);
    QGraphicsScene *escena;
    void nivel();
    QList<Pendulo *> pendulos;
    QList<Polea *> poleas;
    QList<Pesos *> pesos;
    QList<Resorte *> resortes;
    QList<Paredes *> h_arriba;
    QList<Paredes *> h_abajo;
    QList<Paredes *> v_izquierda;
    QList<Paredes *> v_derecha;
    QList<Puente *> puentes;
private:
    Ui::Niveles *ui;    QTimer *timer;
    void cada_nivel();
    Personaje *personajea;
    Polea_ventana *polea;
    float x,y,ancho,alto;
    int modojuego,dificultad;
    void keyPressEvent(QKeyEvent * evento);
    void Colisiones(Personaje *personajea);
private slots:
    void actualizar();
};

#endif // NIVELES_H
