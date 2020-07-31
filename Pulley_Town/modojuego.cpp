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
    modo=0;
    music->setMedia(QUrl("qrc:/Imagenes/musica_fondo.mp3"));
    music->play();
}

Modojuego::~Modojuego()
{
    delete ui;
}

//Guarda el o los nombres segun el modo de juego
void Modojuego::Nombre(string _usuario1,int _tipousuario,int _veces)
{
    if(_veces==0){  //Primer usuario
        usuario1=_usuario1;
        tipousuario=_tipousuario;
        MensajesInterfaz();
    }else{      //Segundo usuario
        usuario2=_usuario1;
        tipousuario=_tipousuario;
        MensajesInterfaz();
    }
}

void Modojuego::Modo(int _modo)
{
    modo=_modo;
}

//Envía datos a niveles para configurar la escena
void Modojuego::on_Empezar_clicked()
{
    ui->partida->setText("");
    if(ui->novato->isChecked()){        //Nivel 0
        if(modo==0){            //un jugador
            nivel->Nombres(usuario1,"");
        }else{
            nivel->Nombres(usuario1,usuario2);
        }
        nivel->Definicion(0,modo);
    }
    if(ui->Aprendiz->isChecked()){  //Nivel1
        if(modo==0){
            nivel->Nombres(usuario1,"");
        }else{
            nivel->Nombres(usuario1,usuario2);
        }
        nivel->Definicion(1,modo);
    }
    if(ui->Experto->isChecked()){   //Nivel 2
        if(modo==0){
            nivel->Nombres(usuario1,"");
        }else{
            nivel->Nombres(usuario1,usuario2);
        }
        nivel->Definicion(2,modo);
    }
    nivel->show();  //Muestra el nivel
    music->stop();
}

//Abre la ventana de carga de partdas
void Modojuego::on_Cargar_clicked()
{
    if(modo==1){        //Multijugador
        ui->partida->setText("NO ES PERMITIDO EN MULTIJUGADOR!");
    }if(modo==0){
           carga->Partida(usuario1);
           carga->show();
    }
}

//Llena la interfaz segun el caso
void Modojuego::MensajesInterfaz()
{
    int l=usuario1.length();
    for(int i=0;i<((33/2)-(l/2));i++){      //Define cuantos espacios lleva segun la longitud por estetica
        espacios+=" ";
    };
    QString texto = QString::fromStdString(espacios+usuario1);
    ui->Mensaje->setText(texto);    //Actualiza interfaz
    espacios="";
    if(usuario2!=""){   //Si son dos jugadores
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
        if(modo==0){    //Un jugador
            ui->Mensaje1->setText("PUEDES ELEGIR SI DESEAS RECUPERAR UNA");
            ui->Mensaje2->setText(" PARTIDA ANTERIOR O EMPEZAR UNA NUEVA.");
        }else{
            ui->Mensaje1->setText("   ELIJAN LA DIFICULTAD QUE DESEAN");
            ui->Mensaje2->setText("         Y OPRIME EMPEZAR");
        }

    }
}

//Ver instrucciones
void Modojuego::on_instruccione_clicked()
{
    instruccion->show();
}

//Boton para salir
void Modojuego::on_cerrar_clicked()
{
    this->close();
}
