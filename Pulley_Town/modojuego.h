#ifndef MODOJUEGO_H
#define MODOJUEGO_H

#include <QWidget>
#include "registro.h"

namespace Ui {
class Modojuego;
}

class Modojuego : public QWidget
{
    Q_OBJECT

public:
    explicit Modojuego(QWidget *parent = nullptr);
    ~Modojuego();

private slots:


    void on_Jugador_clicked();

    void on_Multijugador_clicked();

    void on_Novato_clicked();

    void on_Aprendiz_clicked();

    void on_Experto_clicked();

    void on_Empezar_clicked();

private:
    Ui::Modojuego *ui;
    Registro registro;
};

#endif // MODOJUEGO_H
