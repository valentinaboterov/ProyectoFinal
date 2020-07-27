/*
Permite ver los creditos del juego.
*/
#ifndef CREDITOS_H
#define CREDITOS_H

#include <QWidget>

namespace Ui {
class Creditos;
}

class Creditos : public QWidget
{
    Q_OBJECT

public:
    explicit Creditos(QWidget *parent = nullptr);
    ~Creditos();

private:
    Ui::Creditos *ui;
};

#endif // CREDITOS_H
