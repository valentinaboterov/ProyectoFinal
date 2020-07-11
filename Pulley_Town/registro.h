#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include<string>
#include"modojuego.h"


namespace Ui {
class Registro;
}
using namespace std;
class Registro : public QWidget
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();
    void tipo(int modo,int usu);
    void validacion();

private slots:
    void on_Entrar_clicked();

private:
    Ui::Registro *ui;
    int modojuego,usuario;
    Modojuego modo;
    string nombre,clave;
};

#endif // REGISTRO_H
