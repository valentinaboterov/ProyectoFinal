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

void Ganador::Nombre(string _nombre)
{
    music->setMedia(QUrl("qrc:/Imagenes/aplausosfinal.mp3"));
    music->play();
    nombre=_nombre;
    QString texto1= QString::fromStdString(nombre);
    ui->nombre->setText(texto1);
}

void Ganador::on_menu_clicked()
{
    this->close();
}
