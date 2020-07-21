#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    setWindowTitle("Registro");

}

Registro::~Registro()
{
    delete ui;
}


void Registro::validacion(int _modojuego,int _tipojugador)
{
        tipojugador=_tipojugador;
        modojuego=_modojuego;
        for(int i=0;i<=modojuego;i++){
            this->show();
            if(tipojugador==0){ //Usuario nuevo
                //Solo se agrega al final del documento.
                modo.Nombre(nombre1,"",tipojugador);    //CUANDO SE VALIDE EL USUARIO
                this->close();
                modo.show();
            }else{  //Usuario antiguo
                //Se valida la cuenta
                modo.Nombre(nombre1,nombre2,tipojugador);
                this->close();
                modo.show();
            }
        }
}

void Registro::on_Entrar_clicked()
{
    if(cont==0){
        nombre1=ui->Nombre->text().toStdString();
        clave1=ui->Clave->text().toStdString();
        this->close();
        cont+=1;
    }else{
        nombre2=ui->Nombre->text().toStdString();
        clave2=ui->Clave->text().toStdString();
        this->close();
        cont=0;
    }
}
