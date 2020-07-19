#include "niveles.h"
#include "ui_niveles.h"

Niveles::Niveles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Niveles)
{
    ui->setupUi(this);
    dificultad=0;
    modojuego=0;
    //Obtiene el tamaño del ordenador donde se ejecuta el código.
    x =0 ;
    y =0;
    ancho = 800;
    alto  = 750;
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/Fondonivel.jpeg"));
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(10);
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
    nivel();
    cada_nivel();
    if(dificultad==0 && modojuego==0){ //Novato,un solo jugador

    }
    if(dificultad==0 && modojuego==1){ //Novato,multijugador

    }
    if(dificultad==1 && modojuego==0){ //Aprendiz,un solo jugador

    }
    if(dificultad==1 && modojuego==1){ //Aprendiz,multijugador jugador

    }
    if(dificultad==2 && modojuego==0){ //Experto ,un solo jugador

    }
    if(dificultad==2 && modojuego==1){ //Experto,multijugador

    }
}

Niveles::~Niveles()
{
    delete ui;
}
void Niveles::Definicion(int nivel, int modo)
{
    dificultad=nivel;
    modojuego=modo;
}
void Niveles::actualizar(){
    for(int i=0;i<pendulos.length();i++){
        pendulos.at(i)->actualizar();
    }
    for(int i=0;i<resortes.length();i++){
        resortes.at(i)->actualizar();
    }
}
void Niveles::keyPressEvent(QKeyEvent *evento){
    if(evento->key()==Qt::Key_A){
                personajea->Left();
                Colisiones(personajea);

    }
    else if(evento->key()==Qt::Key_D){
                personajea->Rigth();
                Colisiones(personajea);
    }
    else if(evento->key()==Qt::Key_W){
                personajea->Up();
                Colisiones(personajea);
    }
    else if(evento->key()==Qt::Key_S){
                personajea->Down();
                Colisiones(personajea);
    }
}

void Niveles::Colisiones(Personaje *personaje1)
{
    for(int i=0;i<v_derecha.length();i++){
        if(personaje1->collidesWithItem(v_derecha.at(i))){
            personaje1->Rigth();
        }
    }for(int i=0;i<v_izquierda.length();i++){
        if(personaje1->collidesWithItem(v_izquierda.at(i))){
            personaje1->Left();

        }
    }for(int i=0;i<h_arriba.length();i++){
        if(personaje1->collidesWithItem(h_arriba.at(i))){
            personaje1->Up();
        }
    }for(int i=0;i<h_abajo.length();i++){
        if(personaje1->collidesWithItem(h_abajo.at(i))){
            personaje1->Down();
        }
    }
}
void Niveles::nivel(){
    //Definicion nivel.
    //Esquinas:
    v_derecha.push_back(new Paredes(20,490,-20,-130)); escena->addItem(v_derecha.back());
    v_izquierda.push_back(new Paredes(20,700,-760,-20));  escena->addItem(v_izquierda.back());
    h_abajo.push_back(new Paredes(740,20,-20,-20));  escena->addItem(h_abajo.back());
    h_arriba.push_back(new Paredes(760,20,-20,-710));  escena->addItem(h_arriba.back());
    //Laberinto
    v_izquierda.push_back(new Paredes(10,100,-200,-40));escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,100,-210,-40)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(40,10,-40,-130));escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(40,10,-40,-140));escena->addItem(h_abajo.back());
    h_arriba.push_back(new Paredes(60,10,-160,-130));escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(60,10,-160,-140));escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,210,-160,-130)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,210,-170,-130)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(40,10,-120,-230));escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(40,10,-120,-240)); escena->addItem(h_abajo.back());


    h_arriba.push_back(new Paredes(40,10,-120,-320));escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(40,10,-120,-330));escena->addItem(h_abajo.back());
    h_arriba.push_back(new Paredes(160,10,-130,-440)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(160,10,-130,-450)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,110,-200,-460)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,110,-210,-460)); escena->addItem(v_derecha.back());
    v_izquierda.push_back(new Paredes(10,220,-270,-220)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,220,-280,-220)); escena->addItem(v_derecha.back());


    h_arriba.push_back(new Paredes(60,10,-270,-220)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(60,10,-270,-230)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,100,-310,-120)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,100,-320,-120)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(180,10,-310,-120)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(180,10,-310,-130)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,80,-580,-40)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,80,-590,-40)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(60,10,-580,-120)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(60,10,-580,-130)); escena->addItem(h_abajo.back());


    v_izquierda.push_back(new Paredes(10,150,-430,-140)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,150,-440,-140)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(100,10,-660,-210)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(100,10,-660,-220)); escena->addItem(h_abajo.back());
    h_arriba.push_back(new Paredes(130,10,-430,-270)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(130,10,-430,-280)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,100,-560,-270)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,100,-570,-270)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(60,10,-520,-370)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(60,10,-520,-380)); escena->addItem(h_abajo.back());


    v_izquierda.push_back(new Paredes(10,60,-520,-370)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,60,-530,-370)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(100,10,-440,-430)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(100,10,-440,-440)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,200,-430,-370)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,200,-440,-370)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(60,10,-290,-320)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(60,10,-290,-330)); escena->addItem(h_abajo.back());


    h_arriba.push_back(new Paredes(120,10,-640,-540)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(120,10,-640,-550)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,60,-670,-560)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,60,-680,-560)); escena->addItem(v_derecha.back());
    v_izquierda.push_back(new Paredes(10,50,-440,-660)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,50,-450,-660)); escena->addItem(v_derecha.back());
    v_izquierda.push_back(new Paredes(10,90,-620,-470)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,90,-630,-470)); escena->addItem(v_derecha.back());
    v_izquierda.push_back(new Paredes(10,50,-100,-660)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,50,-110,-660)); escena->addItem(v_derecha.back());


    h_arriba.push_back(new Paredes(410,10,-40,-560)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(410,10,-40,-570)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,40,-200,-580)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,40,-210,-580)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(40,10,-620,-470)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(40,10,-620,-480)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,180,-660,-310)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,180,-670,-310)); escena->addItem(v_derecha.back());
    v_izquierda.push_back(new Paredes(10,160,-540,-550)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,160,-550,-550)); escena->addItem(v_derecha.back());
}

void Niveles::cada_nivel()
{
    if(dificultad==0){      //Aprendiz
        personajea=new Personaje();
        escena->addItem(personajea);
        personajea->setFlag(QGraphicsItem::ItemIsFocusable);
        personajea->setFocus();
        personajea->setPos(35,75);
            pesos.push_back(new Pesos(180,95)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(240,200)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(400,75));escena->addItem(pesos.back());
            pesos.push_back(new Pesos(630,75)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(400,470)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(720,500)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(730,600)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(200,685)); escena->addItem(pesos.back());
            pendulos.push_back(new Pendulo(90,150,30,80)); escena->addItem(pendulos.back());
            pendulos.push_back(new Pendulo(150,350,30,90)); escena->addItem(pendulos.back());
            pendulos.push_back(new Pendulo(690,70,50,80)); escena->addItem(pendulos.back());
            pendulos.push_back(new Pendulo(650,250,30,90)); escena->addItem(pendulos.back());
            puentes.push_back(new Puente(195,500)); escena->addItem(puentes.back());
            puentes.push_back(new Puente(428,500)); escena->addItem(puentes.back());
            puentes.push_back(new Puente(555,330)); escena->addItem(puentes.back());
            resortes.push_back(new Resorte(220,170,10,1000)); escena->addItem(resortes.back());
            resortes.push_back(new Resorte(350,380,10,1500)); escena->addItem(resortes.back());
            resortes.push_back(new Resorte(585,420,10,1000)); escena->addItem(resortes.back());
    }
}
