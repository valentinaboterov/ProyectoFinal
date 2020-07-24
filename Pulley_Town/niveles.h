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
#include<QMessageBox>
#include<QPixmap>
#include<QTimer>
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
#include"friccion.h"

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
    void Definicion(int _nivel,int modo);
    QGraphicsScene *escena;
    void Reanudar();
    void Guardar();
    void Salir();
private:
    Ui::Niveles *ui;
    void nivel();
    int tiempo,paquetes,kilos=10;
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
    QList<Pesos *> cambiar(QList<Pesos*> lista,int pos);
    Friccion *friccion1;
    Friccion *friccion2;
    Friccion *friccion3;
    Friccion *friccion4;
    QTimer *timer;
    QTimer *timer1;
    int modojuego,dificultad,pausa;
    QList<Pesos *> Eliminados;
    void cada_nivel();
    Perdedor *perdedor;
    Ganador *ganador;
    Personaje *personajea;
    Polea_ventana *polea;
    float x,y,ancho,alto;
    void keyPressEvent(QKeyEvent * evento);
    void Colisiones(Personaje *personajea);

private slots:
    void actualizar();
    void actualizar_tiempo();
    void on_pausa_clicked();
    void on_Guardar_clicked();
    void on_Salir_clicked();
};

#endif // NIVELES_H
