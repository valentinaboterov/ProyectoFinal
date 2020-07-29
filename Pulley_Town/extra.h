#ifndef EXTRA_H
#define EXTRA_H

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
#include"resorte.h"
#include"personaje.h"
#include"plataforma.h"
#include"paredes.h"

namespace Ui {
class Extra;
}

class Extra : public QWidget
{
    Q_OBJECT

public:
    explicit Extra(QWidget *parent = nullptr);
    ~Extra();
    void Mensaje();

private:
    Ui::Extra *ui;
    QGraphicsScene *escena=new QGraphicsScene(this);
    Personaje *personaje;
    Resorte *resorte;
    plataforma *final;
    QList<Paredes *> v_izquierda;
    QList<Paredes *> v_derecha;
    QList<Paredes *> h_arriba;
    QList<Paredes *> h_abajo;
    QList<Resorte *> resortes;
    QTimer *timer;
    void Nivel();
    void colisiones();
    void keyPressEvent(QKeyEvent * evento);
private slots:
    void actualizar();  //Objetos
};

#endif // EXTRA_H
