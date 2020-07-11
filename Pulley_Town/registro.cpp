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

void Registro::tipo(int modo,int usu)
{
    modojuego=modo;
    usuario=usu;
}

void Registro::validacion()
{
        for(int i=0;i<=modojuego;i++){
            this->show();
            if(usuario==0){ //Usuario nuevo
                //Solo se agrega al final del documento.
                //this->close();
                modo.show();
            }else{  //Usuario antiguo
                //Se valida la cuenta
                //this->close();
            }
        }
}

void Registro::on_Entrar_clicked()
{
    nombre=ui->Nombre->text().toStdString();
    clave=ui->Clave->text().toStdString();
}
