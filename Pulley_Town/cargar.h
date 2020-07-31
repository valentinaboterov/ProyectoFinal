/*
Permite ver en pantalla las partidas guardadas con anterioridad, y cargar la
se desee.
*/
#ifndef CARGAR_H
#define CARGAR_H
using namespace std;
#include <QWidget>
#include<iostream>
#include<fstream>
#include"niveles.h"

namespace Ui {
class Cargar;
}

class Cargar : public QWidget
{
    Q_OBJECT

public:
    explicit Cargar(QWidget *parent = nullptr);
    ~Cargar();
    void Partida(string _nombre);   //Inicizliacion.

private slots:
    void on_pushButton_clicked();   //Boton para cargar la partida.

    void on_regresar_clicked();

private:
    Ui::Cargar *ui;
    string nivel,pesos,x,y,t,nombre,bolsas;
    int numero,cargar=1; //Por defecto carga la primera partida.
    string Buscar(string _linea,int romper);
    bool mostrar=false;
    void sobreescribir();
    void llenararchivo();
    Niveles *niveles=new Niveles();
};

#endif // CARGAR_H
