#ifndef MODOJUEGO_H
#define MODOJUEGO_H
using namespace std;
#include <QWidget>
#include"niveles.h"
#include"cargar.h"


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
    void Nombre(string _usuario1,int _tipousuario,int _veces);
    void Modo(int _modo);
private slots:

    void on_Empezar_clicked();

    void on_Cargar_clicked();

private:
    Ui::Modojuego *ui;
    int modo,tipousuario,cont;
    string espacios="";
    string usuario1,usuario2;
    void MensajesInterfaz();
    Niveles *nivel=new Niveles();
    Cargar *carga=new Cargar;
};

#endif // MODOJUEGO_H
