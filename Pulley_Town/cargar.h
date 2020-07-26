#ifndef CARGAR_H
#define CARGAR_H
using namespace std;
#include <QWidget>

namespace Ui {
class Cargar;
}

class Cargar : public QWidget
{
    Q_OBJECT

public:
    explicit Cargar(QWidget *parent = nullptr);
    ~Cargar();
    void Partida(string _nombre);

private:
    Ui::Cargar *ui;
    string nombre,bolsas;
    int x,y,t;
};

#endif // CARGAR_H
