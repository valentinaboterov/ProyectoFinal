/*
Ventana de inicio, donde se selecciona el nivel, o cargar partidas.
*/
#ifndef MODOJUEGO_H
#define MODOJUEGO_H
using namespace std;
#include <QWidget>
#include<QMediaPlayer>
#include"niveles.h"
#include"cargar.h"
#include"instrucciones.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Modojuego;
}
QT_END_NAMESPACE
class Modojuego : public QWidget
{
    Q_OBJECT

public:
    explicit Modojuego(QWidget *parent = nullptr);
    ~Modojuego();
    void Nombre(string _usuario1,int _tipousuario,int _veces);
    void Modo(int _modo);
    QMediaPlayer * music = new QMediaPlayer;
private slots:

    void on_Empezar_clicked();  //Empezar juego nuevo

    void on_Cargar_clicked();   //Cargar juego antiguo

    void on_instruccione_clicked();

    void on_cerrar_clicked();

private:
    Ui::Modojuego *ui;
    int modo,tipousuario,cont;
    string espacios="";
    string usuario1,usuario2;
    void MensajesInterfaz();        //Segun el modo muestra mensajes en pantalla.
    Niveles *nivel=new Niveles();
    instrucciones *instruccion=new instrucciones();
    Cargar *carga=new Cargar;

};

#endif // MODOJUEGO_H
