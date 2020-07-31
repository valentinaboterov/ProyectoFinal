#include "ganador.h"
#include "ui_ganador.h"

Ganador::Ganador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ganador)
{
    ui->setupUi(this);
    setWindowTitle("Ganador");
}

Ganador::~Ganador()
{
    delete ui;
}

//Guarda el nombre del usuario
void Ganador::Nombre(string _nombre)
{
    music->setMedia(QUrl("qrc:/Imagenes/aplausosfinal.mp3"));
    music->play();
    nombre=_nombre;
    QString texto1= QString::fromStdString(nombre);
    ui->nombre->setText(texto1);
}

//Mensajes si es multijugador
void Ganador::Multi(string _nombre1,int modo)
{
    if(modo==0){    //Pendulo
        QString texto1= QString::fromStdString(_nombre1+" choco contra un pendulo.");
        ui->multijugador->setText(texto1);
    }else{
        QString texto1= QString::fromStdString(_nombre1+" choco contra un resorte.");
        ui->multijugador->setText(texto1);
    }

}

//Boton para salir

void Ganador::on_menu_clicked()
{
    this->close();
    music->stop();
}
