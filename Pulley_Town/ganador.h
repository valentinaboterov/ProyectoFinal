#ifndef GANADOR_H
#define GANADOR_H

#include <QWidget>

namespace Ui {
class Ganador;
}

class Ganador : public QWidget
{
    Q_OBJECT

public:
    explicit Ganador(QWidget *parent = nullptr);
    ~Ganador();

private:
    Ui::Ganador *ui;
};

#endif // GANADOR_H
