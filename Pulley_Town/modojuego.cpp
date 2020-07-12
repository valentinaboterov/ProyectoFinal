#include "modojuego.h"
#include "ui_modojuego.h"

Modojuego::Modojuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modojuego)
{
    ui->setupUi(this);
    setWindowTitle("Modo de juego");
    modo=0; //Un jugador por defecto
    nivel=new Niveles;
}

Modojuego::~Modojuego()
{
    delete ui;
}

void Modojuego::Nombre(string _usuario1,string _usuario2,int _tipousuario)
{
    usuario1=_usuario1;
    usuario2=_usuario2;
    tipousuario=_tipousuario;
    MensajesInterfaz();
}


void Modojuego::on_Empezar_clicked()
{
    nivel->show();
    this->close();
}

void Modojuego::on_Cargar_clicked()
{

}

void Modojuego::MensajesInterfaz()
{
    QString texto = QString::fromStdString(usuario1);
    ui->Mensaje->setText(texto);
    if(usuario2!=""){
        texto=QString::fromStdString(" y "+usuario2);
        ui->Mensaje->setText(texto);
    }
    if(tipousuario==0){  //Usuario nuevo
        ui->Mensaje1->setText("Elige la dificultad que deseas");
        ui->Mensaje2->setText("      y luego empezar");
    }else{  //Usuario atiguo
        ui->Mensaje1->setText("Puedes elegir si deseas recuperar una");
        ui->Mensaje2->setText("partida anterior o empezar una nueva:");
    }
}
