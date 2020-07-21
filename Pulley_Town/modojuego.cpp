#include "modojuego.h"
#include "ui_modojuego.h"

Modojuego::Modojuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modojuego)
{
    ui->setupUi(this);
    setWindowTitle("Modo de juego");
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

void Modojuego::Modo(int _modo)
{
    modo=_modo;
}


void Modojuego::on_Empezar_clicked()
{
    if(ui->novato->isChecked()){
        nivel->Definicion(0,modo);
    }
    if(ui->Aprendiz->isChecked()){
        nivel->Definicion(1,modo);
    }
    if(ui->Experto->isChecked()){
        nivel->Definicion(2,modo);
    }
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
        ui->Mensaje1->setText("   ELIGE LA DIFICULTAD QUE DESEAS");
        ui->Mensaje2->setText("         Y OPRIME EMPEZAR");
    }else{  //Usuario atiguo
        ui->Mensaje1->setText("PUEDES ELEGIR SI DESEAS RECUPERAR UNA");
        ui->Mensaje2->setText(" PARTIDA ANTERIOR O EMPEZAR UNA NUEVA.");
    }
}


