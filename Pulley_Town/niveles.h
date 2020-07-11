#ifndef NIVELES_H
#define NIVELES_H

#include <QWidget>

namespace Ui {
class Niveles;
}

class Niveles : public QWidget
{
    Q_OBJECT

public:
    explicit Niveles(QWidget *parent = nullptr);
    ~Niveles();
    void Definicion(int nivel,int modo);

private:
    Ui::Niveles *ui;
    int modojuego,dificultad;
};

#endif // NIVELES_H
