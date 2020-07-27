/*
Ventana perdedor de juego.
*/
#ifndef PERDEDOR_H
#define PERDEDOR_H
using namespace std;
#include <QWidget>

namespace Ui {
class Perdedor;
}

class Perdedor : public QWidget
{
    Q_OBJECT

public:
    explicit Perdedor(QWidget *parent = nullptr);
    ~Perdedor();
    void Causa(int _mensaje);   //Porque pierde.
    void Nombre(string _nombre);    //Nombre usuario.

private slots:

    void on_cerrar_clicked();   //Cierra ventana.

private:
    Ui::Perdedor *ui;
    QString texto;
};

#endif // PERDEDOR_H
