/* Ventana con las instrucciones del juego*/
#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <QWidget>

namespace Ui {
class instrucciones;
}

class instrucciones : public QWidget
{
    Q_OBJECT

public:
    explicit instrucciones(QWidget *parent = nullptr);
    ~instrucciones();

private slots:
    void on_pushButton_clicked();   //Boton para salir

private:
    Ui::instrucciones *ui;
};

#endif // INSTRUCCIONES_H
