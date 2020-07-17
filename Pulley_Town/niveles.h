#ifndef NIVELES_H
#define NIVELES_H

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
#include"paredes.h"


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
private:
    Ui::Niveles *ui;    QTimer *timer;
    Pendulo *pendulo1;Pendulo *pendulo2;Pendulo *pendulo3;Pendulo *pendulo4;
    Personaje *personaje;
    Pesos *pesos;
    float x,y,ancho,alto;
    int modojuego,dificultad;
    void keyPressEvent(QKeyEvent * evento);
    //PAREDES
    //Esquinas:
    Paredes *muro1;Paredes *muro2;Paredes *muro3;Paredes *muro4;
    //Laberinto:
    Paredes *pared1;Paredes *pared2;Paredes *pared3;Paredes *pared4;Paredes *pared5;Paredes *pared6;
    Paredes *pared7;Paredes *pared8;Paredes *pared9;Paredes *pared10;Paredes *pared11;Paredes *pared12;
    Paredes *pared13;Paredes *pared14;Paredes *pared15;Paredes *pared16;Paredes *pared17;Paredes *pared18;
    Paredes *pared19;Paredes *pared20;Paredes *pared21;Paredes *pared22;Paredes *pared23;Paredes *pared24;
    Paredes *pared25;Paredes *pared26;Paredes *pared27;Paredes *pared28;Paredes *pared29;Paredes *pared30;
    Paredes *pared31;Paredes *pared32;Paredes *pared33;Paredes *pared34;Paredes *pared35;Paredes *pared36;
    Paredes *pared37;Paredes *pared38;Paredes *pared39;Paredes *pared40;Paredes *pared41;Paredes *pared42;
    Paredes *pared43;Paredes *pared44;Paredes *pared45;Paredes *pared46;Paredes *pared47;Paredes *pared48;
    Paredes *pared49;Paredes *pared50;Paredes *pared51;Paredes *pared52;Paredes *pared53;Paredes *pared54;
    Paredes *pared55;Paredes *pared56;Paredes *pared57;Paredes *pared58;Paredes *pared59;Paredes *pared60;
    Paredes *pared61;Paredes *pared62;Paredes *pared63;Paredes *pared64;Paredes *pared65;Paredes *pared66;
    Paredes *pared67;Paredes *pared68;Paredes *pared69;Paredes *pared70;Paredes *pared71;Paredes *pared72;
    Paredes *pared73;Paredes *pared74;Paredes *pared75;Paredes *pared76;Paredes *pared77;Paredes *pared78;
    Paredes *pared79;Paredes *pared80;Paredes *pared81;Paredes *pared82;Paredes *pared83;Paredes *pared84;
    Paredes *pared85;Paredes *pared86;Paredes *pared87;Paredes *pared88;Paredes *pared89;Paredes *pared90;
    Paredes *pared91;Paredes *pared92;Paredes *pared93;Paredes *pared94;Paredes *pared95;Paredes *pared96;
    Paredes *pared97;Paredes *pared98;Paredes *pared99;Paredes *pared100;Paredes *pared101;Paredes *pared102;
    Paredes *pared103;Paredes *pared104;Paredes *pared105;Paredes *pared106;Paredes *pared107;
private slots:
    void actualizar();
};

#endif // NIVELES_H
