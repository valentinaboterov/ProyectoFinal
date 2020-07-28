/*
Genera la ventana para comparacion de la polea.
*/
#ifndef POLEA_VENTANA_H
#define POLEA_VENTANA_H

#include <QWidget>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include<QObject>
#include<QMediaPlayer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include"polea.h"


namespace Ui {
class Polea_ventana;
}

class Polea_ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Polea_ventana(QWidget *parent = nullptr);
    ~Polea_ventana();
     QGraphicsScene *escena;
     void valores(int _masa2,int _nivel);   //Recibe valores obtenidos en el nivel
     int cerrar();  //Cierra la ventana.

private:
    Ui::Polea_ventana *ui;
    Polea *polea;
    QMediaPlayer *music=new QMediaPlayer();
    int masa2,nivel,paquetes;
    float x,y,ancho,alto;
private slots:
    void actualizar();  //Llama funcion para comparar pesos.
    void on_Comparar_clicked(); //Boton para comparar
};

#endif // POLEA_VENTANA_H
