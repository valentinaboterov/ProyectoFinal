#include "extra.h"
#include "ui_extra.h"

Extra::Extra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Extra)
{
    ui->setupUi(this);
    setWindowTitle("PRACTICA");
    escena->setSceneRect(0,0,1400,220);
    escena->setBackgroundBrush(QBrush(QImage(":/Imagenes/fondo_extra.png")));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(450,220);
    personaje=new Personaje(0,40,160);
    escena->addItem(personaje);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->setPos(40,160);
    this->resize(450,220);
    timer=new QTimer(this);    //Timer para objetos.
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(100);
    final=new plataforma(1320,170);
    escena->addItem(final);
    resortes.clear();
}

Extra::~Extra()
{
    delete ui;
}

void Extra::Mensaje()
{
    QMessageBox msgBox;
    msgBox.setText("Vuelvete experto en esquivar obstáculos, salta para subir a la plataforma.(D:Avanzar,W:Saltar)");
    msgBox.setIconPixmap(QPixmap(":/Imagenes/logo_practica.png"));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setWindowTitle("PRACTICA");
    int elegido = msgBox.exec();
    switch (elegido) {
       case QMessageBox::Ok:
            Nivel();
            this->show();
    }
}

//Actualiza los objetos en la escena.
void Extra::actualizar(){
    pendulo->actualizar();
    for(int i=0;i<resortes.length();i++){
        resortes.at(i)->actualizar();
    }
}
void Extra::Nivel()
{
    personaje->setPos(40,160);
    ui->graphicsView->centerOn(personaje);
    escena->addItem(pendulo);
    resortes.push_back(new Resorte(400,0,10,1000,230,1)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(700,0,10,1000,210,1)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(1100,0,10,1000,230,1)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(1500,0,10,1000,240,1)); escena->addItem(resortes.back());
}

void Extra::colisiones()
{
    QMessageBox msgBox;
   if(personaje->collidesWithItem(pendulo)){
       msgBox.setText("Chocaste contra un pendulo.Perdiste.");
       msgBox.setStandardButtons(QMessageBox::Ok);
       msgBox.setDefaultButton(QMessageBox::Ok);
       msgBox.setWindowTitle("PRACTICA");
       int elegido = msgBox.exec();
       switch (elegido){
          case QMessageBox::Ok:
               this->close();
       }
   }
   for(int i=0;i<resortes.length();i++){
       if(personaje->collidesWithItem(resortes.at(i))){
           msgBox.setText("Chocaste contra un resorte.Perdiste.");
           msgBox.setStandardButtons(QMessageBox::Ok);
           msgBox.setDefaultButton(QMessageBox::Ok);
           msgBox.setWindowTitle("PRACTICA");
           int elegido = msgBox.exec();
           switch (elegido){
              case QMessageBox::Ok:
                   this->close();
           }
       }
   }
}

void Extra::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D){
        personaje->friccion();
        colisiones();
        ui->graphicsView->centerOn(personaje->getx(),personaje->gety());
    }if(evento->key()==Qt::Key_W){
        personaje->Saltar();
        if(personaje->collidesWithItem(final)){
            QMessageBox msgBox;
            msgBox.setText("Felicitaciones superaste todos los obstáculos.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setWindowTitle("PRACTICA");
            int elegido = msgBox.exec();
            switch (elegido){
               case QMessageBox::Ok:
                    this->close();
            }
        }
        colisiones();
        ui->graphicsView->centerOn(personaje->getx(),personaje->gety());
    }
}
