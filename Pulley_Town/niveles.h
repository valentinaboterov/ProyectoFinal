/*
Ventana con el nivel según el caso.
*/
#ifndef NIVELES_H
#define NIVELES_H

#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include<QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QPixmap>
#include<QTimer>
#include<QMessageBox>
#include<iostream>
#include<fstream>
#include"pendulo.h"
#include"personaje.h"
#include"pesos.h"
#include"paredes.h"
#include"resorte.h"
#include"polea_ventana.h"
#include"puente.h"
#include"plataforma.h"
#include"perdedor.h"
#include"ganador.h"

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
    void Definicion(int _nivel,int modo);   //Variables iniciales.
    void Nombres(string _nombre1,string _nombre2);
    QGraphicsScene *escena;
    void Cargar(string _nivel,string _bolsas,string _posx,string _posy,string _tiempo);
    void llenararchivo();
private:
    Ui::Niveles *ui;
    int tiempo,paquetes,paquetes1,kilos=10;
    string nombre1,nombre2,bolsas="";
    float x,y,ancho,alto;
    Perdedor *perdedor;
    Ganador *ganador;
    Personaje *personajea;
    Personaje *personajeb;
    Polea_ventana *polea;
    //Listas para objetos.
    QList<Pendulo *> pendulos;
    plataforma *final;
    QList<Polea *> poleas;
    QList<Pesos *> pesos;
    QList<Resorte *> resortes;
    QList<Paredes *> h_arriba;
    QList<Paredes *> h_abajo;
    QList<Paredes *> v_izquierda;
    QList<Paredes *> v_derecha;
    QList<Puente *> puentes;
    //Timers.
    QTimer *timer;
    QTimer *timer1;
    int modojuego,dificultad,pausa;
    QList<Pesos *> cambiar(QList<Pesos*> lista,int pos);
    //Funciones.
    void nivel();
    void cada_nivel();
    void keyPressEvent(QKeyEvent * evento);
    void Colisiones(Personaje *personajea);
    string Buscar(string linea,int romper);
    void sobreescribir(string usuario);


private slots:
    void actualizar();  //Objetos
    void actualizar_tiempo();       //Tiempo de juego
    //Botones.
    void on_pausa_clicked();
    void on_Guardar_clicked();
    void on_Salir_clicked();
};

#endif // NIVELES_H
