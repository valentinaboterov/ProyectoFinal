#include "polea_ventana.h"
#include "ui_polea_ventana.h"

Polea_ventana::Polea_ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Polea_ventana)
{
    ui->setupUi(this);
    x =0 ;
    y =0;
    ancho = 600;
    alto  = 386;
    escena=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(escena);
    polea=new Polea(200,-30,masa2,nivel);
    escena->addItem(polea);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondopolea.jpg"));
}

Polea_ventana::~Polea_ventana()
{
    delete ui;
}

void Polea_ventana::valores(int _masa2, int _nivel)
{
    masa2=_masa2;
    nivel=_nivel;
    ui->masa1->display(masa2);
    paquetes=masa2/10;
    QString texto = QString::fromStdString(std::to_string(paquetes));
    ui->paquetes->setText(texto);
}

void Polea_ventana::actualizar()
{
    polea->Comparacion();
}

void Polea_ventana::on_Comparar_clicked()
{
    actualizar();
}
