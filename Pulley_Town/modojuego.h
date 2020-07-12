#ifndef MODOJUEGO_H
#define MODOJUEGO_H
using namespace std;
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
    void Nombre(string _usuario1,string _usuario2,int _tipousuario);

private slots:

    void on_Empezar_clicked();

    void on_Cargar_clicked();

private:
    Ui::Modojuego *ui;
    int modo,tipousuario;
    string usuario1,usuario2;
    Niveles *nivel;
    void MensajesInterfaz();
};

#endif // MODOJUEGO_H
