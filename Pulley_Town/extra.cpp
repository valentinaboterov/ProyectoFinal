#include "extra.h"
#include "ui_extra.h"

Extra::Extra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Extra)
{
    ui->setupUi(this);
    setWindowTitle("PRACTICA");
    escena->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(500,500);
    personaje=new Personaje(10,60,0);
    escena->addItem(personaje);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    this->resize(500,500);
    timer=new QTimer(this);    //Timer para objetos.
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(10);
    final=new plataforma(390,380);
    escena->addItem(final);
    resortes.clear();
    v_derecha.clear();
    v_izquierda.clear();
    h_arriba.clear();
    h_abajo.clear();
}

Extra::~Extra()
{
    delete ui;
}

void Extra::Mensaje()
{
    resortes.clear();
    v_derecha.clear();
    v_izquierda.clear();
    h_arriba.clear();
    h_abajo.clear();
    escena->setBackgroundBrush(QBrush(QImage(":/Imagenes/fondonivel1.png")));
    personaje->setPos(10,60);
    personaje->setx(10);
    personaje->sety(60);
    QMessageBox msgBox;
    msgBox.setText("Vuelvete experto en esquivar resortes, salta para subir a la plataforma.  (D: derecha, A: izquierda, S: arriba,S: abajo,J: Saltar)");
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
    for(int i=0;i<resortes.length();i++){
        resortes.at(i)->actualizar();
    }
}
void Extra::Nivel()
{
    personaje->setPos(10,60);
    ui->graphicsView->centerOn(personaje);
    h_arriba.push_back(new Paredes(480,10,-10,-10)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(480,10,-10,-20)); escena->addItem(h_abajo.back());

    h_arriba.push_back(new Paredes(440,10,-30,-470)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(440,10,-30,-480)); escena->addItem(h_abajo.back());

    h_arriba.push_back(new Paredes(80,10,-230,-120)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(80,10,-230,-130)); escena->addItem(h_abajo.back());

    h_arriba.push_back(new Paredes(210,10,-20,-170)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(210,10,-20,-180)); escena->addItem(h_abajo.back());

    h_arriba.push_back(new Paredes(50,10,-420,-120)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(50,10,-420,-130)); escena->addItem(h_abajo.back());

    h_arriba.push_back(new Paredes(110,10,-360,-220)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(110,10,-360,-230)); escena->addItem(h_abajo.back());

    h_arriba.push_back(new Paredes(240,10,-140,-290)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(240,10,-140,-300)); escena->addItem(h_abajo.back());

    h_arriba.push_back(new Paredes(80,10,-390,-420)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(80,10,-390,-430)); escena->addItem(h_abajo.back());

    v_izquierda.push_back(new Paredes(10,380,-10,-110)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,380,-20,-110)); escena->addItem(v_derecha.back());

    v_izquierda.push_back(new Paredes(10,480,-470,-10)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,480,-480,-10)); escena->addItem(v_derecha.back());

    v_izquierda.push_back(new Paredes(10,70,-230,-120)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,70,-240,-120)); escena->addItem(v_derecha.back());

    v_izquierda.push_back(new Paredes(10,80,-140,-290)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,80,-150,-290)); escena->addItem(v_derecha.back());

    v_izquierda.push_back(new Paredes(10,70,-360,-220)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,70,-370,-220)); escena->addItem(v_derecha.back());

    resortes.push_back(new Resorte(150,90,10,1000,60,1)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(390,70,10,1000,40,1)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(80,240,10,1000,50,0)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(280,190,10,1000,40,1)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(90,420,10,1000,50,0)); escena->addItem(resortes.back());
    resortes.push_back(new Resorte(250,390,10,1000,40,1)); escena->addItem(resortes.back());

}

void Extra::colisiones()
{
    QMessageBox msgBox;
    //Colisiona con muro , lo envia en la direccion contraria.
    for(int i=0;i<v_derecha.size();i++){
        if(personaje->collidesWithItem(v_derecha.at(i))){
            personaje->Rigth();
        }
    }for(int i=0;i<v_izquierda.size();i++){
        if(personaje->collidesWithItem(v_izquierda.at(i))){
            personaje->Left();

        }
    }for(int i=0;i<h_arriba.size();i++){
        if(personaje->collidesWithItem(h_arriba.at(i))){
            personaje->Up();
        }
    }for(int i=0;i<h_abajo.size();i++){
        if(personaje->collidesWithItem(h_abajo.at(i))){
            personaje->Down();
        }
    }
    //Pierde si colisiona con resortes.
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
    }
    if(evento->key()==Qt::Key_A){
        personaje->Left();
        colisiones();

    }if(evento->key()==Qt::Key_W){
        personaje->Up();
        colisiones();
    }if(evento->key()==Qt::Key_S){
        personaje->Down();
        colisiones();
    }if(evento->key()==Qt::Key_J){
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
    }
}
