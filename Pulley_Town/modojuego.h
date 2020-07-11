#ifndef MODOJUEGO_H
#define MODOJUEGO_H

#include <QWidget>
#include"niveles.h"

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

private slots:
    void on_Jugador_clicked();

    void on_Multijugador_clicked();

    void on_Novato_clicked();

    void on_Aprendiz_clicked();

    void on_Experto_clicked();

    void on_Empezar_clicked();

private:
    Ui::Modojuego *ui;
    int modo;
    Niveles *nivel;
};

#endif // MODOJUEGO_H
