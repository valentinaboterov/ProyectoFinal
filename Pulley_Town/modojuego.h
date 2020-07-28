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
private slots:

    void on_Empezar_clicked();  //Empezar juego nuevo

    void on_Cargar_clicked();   //Cargar juego antiguo

private:
    Ui::Modojuego *ui;
    int modo,tipousuario,cont;
    string espacios="";
    string usuario1,usuario2;
    void MensajesInterfaz();        //Segun el modo muestra mensajes en pantalla.
    Niveles *nivel=new Niveles();
    Cargar *carga=new Cargar;
    QMediaPlayer * music = new QMediaPlayer;
};

#endif // MODOJUEGO_H
