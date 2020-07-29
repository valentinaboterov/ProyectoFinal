/*
Es la ventana que se ve cuando un jugador gana.
*/
#ifndef GANADOR_H
#define GANADOR_H

using namespace std;
#include <QWidget>
#include<QMediaPlayer>

namespace Ui {
class Ganador;
}

class Ganador : public QWidget
{
    Q_OBJECT

public:
    explicit Ganador(QWidget *parent = nullptr);
    ~Ganador();
    void  Nombre(string _nombre);   //Recibe nombre de usuario.
    void Multi(string _nombre1,int modo);

private slots:
    void on_menu_clicked(); //Volver a inicio.

private:
    Ui::Ganador *ui;
    string nombre,nombre1;
    QMediaPlayer * music = new QMediaPlayer;
};

#endif // GANADOR_H
