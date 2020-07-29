/*
Validacion de ingreso de usuarios.(Registro e iniciar sesion)
*/
#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include<string>
#include<fstream>
#include<iostream>
#include"modojuego.h"

using namespace std;

namespace Ui {class Registro;}
class Registro : public QWidget
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();
    bool validacion(string _usuario,string _clave);
    void Registrar(int _modojuego,int _tipojugador);
private slots:
    void on_Entrar_clicked();

private:
    Ui::Registro *ui;
    int modojuego,tipojugador;
    int cont=0,cantidad;
    string linea="",nombre="";
    string Buscar(string _linea,int romper);
    Modojuego modo;
    string nombre1,clave1,nombre2,clave2;
};

#endif // REGISTRO_H
