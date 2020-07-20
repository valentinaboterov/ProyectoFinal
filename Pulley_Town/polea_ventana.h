#ifndef POLEA_VENTANA_H
#define POLEA_VENTANA_H

#include <QWidget>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include<QObject>
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
     void valores(int _masa2,int _nivel);
     int cerrar();

private:
    Ui::Polea_ventana *ui;
    Polea *polea;
    int masa2,nivel,paquetes;
    float x,y,ancho,alto;
private slots:
    void actualizar();
    void on_Comparar_clicked();
};

#endif // POLEA_VENTANA_H
