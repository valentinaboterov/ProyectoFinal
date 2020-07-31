#include "polea_ventana.h"
#include "ui_polea_ventana.h"

//Inicializacion
Polea_ventana::Polea_ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Polea_ventana)
{
    ui->setupUi(this);
    setWindowTitle("Polea");
    x =0 ;
    y =0;
    ancho = 600;
    alto  = 386;
    pierde=new Perdedor();
    gana=new Ganador;
    escena=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(escena);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondopolea.jpg"));
    music->setMedia(QUrl("qrc:/Imagenes/musica_polea.mp3"));
}

Polea_ventana::~Polea_ventana()
{
    delete ui;
}

//Valores a comprar(los que obtuvo el usuario)
void Polea_ventana::valores(int _masa2, int _nivel)
{
    music->play();
    masa2=_masa2;
    nivel=_nivel;
    ui->masa1->display(masa2);
    paquetes=masa2/10;
    QString texto = QString::fromStdString(std::to_string(paquetes));
    ui->paquetes->setText(texto);
    polea=new Polea(200,-30,masa2,nivel);
    escena->addItem(polea);
    this->show();
    polea->Comparacion();
}

int Polea_ventana::cerrar()
{
    if(polea->gety1()<polea->gety2()){  //Suficiente peso.
        QThread::sleep(4);
        this->close();
        pierde->Causa(3);
        pierde->Nombre(nombre);
        pierde->show();
        music->stop();
    }
    else{
        QThread::sleep(4);
        this->close();
        gana->Nombre(nombre);
        gana->show();
        music->stop();
    }
}

void  Polea_ventana::Nombre(string _nombre){
    nombre=_nombre;
}
void Polea_ventana::on_Comparar_clicked()
{
    cerrar();
}
