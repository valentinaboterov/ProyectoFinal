#include "modojuego.h"
#include "ui_modojuego.h"

Modojuego::Modojuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modojuego)
{
    ui->setupUi(this);
    setWindowTitle("Modo de juego");
    cont=0;
    espacios="";
}

Modojuego::~Modojuego()
{
    delete ui;
}

void Modojuego::Nombre(string _usuario1,int _tipousuario,int _veces)
{
    if(_veces==0){
        usuario1=_usuario1;
        tipousuario=_tipousuario;
        MensajesInterfaz();
    }else{
        usuario2=_usuario1;
        tipousuario=_tipousuario;
        MensajesInterfaz();
    }
}

void Modojuego::Modo(int _modo)
{
    modo=_modo;
}


void Modojuego::on_Empezar_clicked()
{
    ui->partida->setText("");
    if(ui->novato->isChecked()){
        nivel->Definicion(0,modo);
        if(modo==0){
            nivel->Nombres(usuario1,"");
        }else{
            nivel->Nombres(usuario1,usuario2);
        }

    }
    if(ui->Aprendiz->isChecked()){
        nivel->Definicion(1,modo);
        if(modo==0){
            nivel->Nombres(usuario1,"");
        }else{
            nivel->Nombres(usuario1,usuario2);
        }
    }
    if(ui->Experto->isChecked()){
        nivel->Definicion(2,modo);
        if(modo==0){
            nivel->Nombres(usuario1,"");
        }else{
            nivel->Nombres(usuario1,usuario2);
        }
    }
    nivel->show();
}

void Modojuego::on_Cargar_clicked()
{
    if(tipousuario==0){
        ui->partida->setText("  NO TIENES PARTIDAS GUARDADAS!");
    }if(modo==1){
        ui->partida->setText("NO ES PERMITIDO EN MULTIJUGADOR!");
    }if(modo==0 && tipousuario==1){
           carga->Partida(usuario1);
           carga->show();
    }
}

void Modojuego::MensajesInterfaz()
{
    int l=usuario1.length();
    for(int i=0;i<((33/2)-(l/2));i++){
        espacios+=" ";
    };
    QString texto = QString::fromStdString(espacios+usuario1);
    ui->Mensaje->setText(texto);
    espacios="";
    if(usuario2!=""){
        int l1=usuario2.length();
        for(int i=0;i<((33/2)-((l+3+l1)/2));i++){
            espacios+=" ";
        }
        texto=QString::fromStdString(espacios+usuario1+" y "+usuario2);
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


