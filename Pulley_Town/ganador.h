#ifndef GANADOR_H
#define GANADOR_H

using namespace std;
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
    void  Nombre(string _nombre);

private slots:
    void on_menu_clicked();

private:
    Ui::Ganador *ui;
    string nombre;
};

#endif // GANADOR_H
