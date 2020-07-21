#include "niveles.h"
#include "ui_niveles.h"

Niveles::Niveles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Niveles)
{
    ui->setupUi(this);
    paquetes=0;
    ui->paquetes->display(paquetes);
    //Obtiene el tamaño del ordenador donde se ejecuta el código.
    x =0 ;
    y =0;
    ancho = 800;
    alto  = 750;
    perdedor=new Perdedor();
    ganador=new Ganador();
    timer=new QTimer(this);
    timer1=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(actualizar_tiempo()));   
    /*pendulos.clear();
    resortes.clear();
    pesos.clear();
    v_derecha.clear();
    v_izquierda.clear();
    h_arriba.clear();
    h_abajo.clear();*/
}

Niveles::~Niveles()
{
    delete ui;
}

void Niveles::Definicion(int _nivel, int modo)
{
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondonivel1.png"));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
    final=new plataforma(35,700);
    escena->addItem(final);
    dificultad=_nivel;
    modojuego=modo;
    nivel();
    cada_nivel();
    timer->start(10);
}

void Niveles::actualizar(){
    for(int i=0;i<pendulos.length();i++){
        pendulos.at(i)->actualizar();
    }
    for(int i=0;i<resortes.length();i++){
        resortes.at(i)->actualizar();
    }
}

void Niveles::actualizar_tiempo()
{
    tiempo-=100;
    ui->tiempo->display(tiempo/1000);
    if(tiempo<1000){
        perdedor->Causa(2);
        this->close();
        perdedor->show();
    }
}
void Niveles::keyPressEvent(QKeyEvent *evento){
    if(evento->key()==Qt::Key_A && personajea->collidesWithItem(friccion1)){
        personajea->friccion_izquierda();
    } if(evento->key()==Qt::Key_D&&personajea->collidesWithItem(friccion1)){
        personajea->friccion_derecha();
    }
    if(evento->key()==Qt::Key_A && personajea->collidesWithItem(friccion2)){
        personajea->friccion_izquierda();
    } if(evento->key()==Qt::Key_D && personajea->collidesWithItem(friccion2)){
        personajea->friccion_derecha();
    }
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
    for(int i=0;i<v_derecha.size();i++){
        if(personaje1->collidesWithItem(v_derecha.at(i))){
            personaje1->Rigth();
        }
    }for(int i=0;i<v_izquierda.size();i++){
        if(personaje1->collidesWithItem(v_izquierda.at(i))){
            personaje1->Left();

        }
    }for(int i=0;i<h_arriba.size();i++){
        if(personaje1->collidesWithItem(h_arriba.at(i))){
            personaje1->Up();
        }
    }for(int i=0;i<h_abajo.size();i++){
        if(personaje1->collidesWithItem(h_abajo.at(i))){
            personaje1->Down();
        }
    }
    for(int i=0;i<pendulos.size();i++){
        if(personaje1->collidesWithItem(pendulos.at(i))){
            //PIERDE
            perdedor->Causa(0);
            perdedor->show();
        }
    }
    for(int i=0;i<resortes.size();i++){
        if(personaje1->collidesWithItem(resortes.at(i))){
            //PIERDE
            perdedor->Causa(1);
            perdedor->show();
        }
    }
    for(int i=0;i<pesos.size();i++){
        if(personaje1->collidesWithItem(pesos.at(i))){
            escena->removeItem(pesos.at(i));
            pesos=cambiar(pesos,i);
            paquetes+=1;
            ui->paquetes->display(paquetes);
        }
    }
    for(int i=0;i<puentes.size();i++){
        if(personaje1->collidesWithItem(puentes.at(i))){
            personaje1->puente();
        }
    }
    if(personaje1->collidesWithItem(final)){
        this->close();
        polea=new Polea_ventana();
        polea->valores(paquetes*kilos,dificultad);
        polea->show();
        int i=polea->cerrar();
        if(i==0){
            polea->close();
            perdedor->Causa(3);
            perdedor->show();
        }else{      //GANADOR
            ganador->show();
        }
    }
}

QList<Pesos *> Niveles::cambiar(QList<Pesos *> lista, int pos)
{
    QList<Pesos*> aux;
    for(int i=0;i<lista.size();i++){
        if(i!=pos){
            aux.push_back(lista.at(i));
        }
    }
    return aux;
}



void Niveles::cada_nivel()
{
    personajea=new Personaje();
    escena->addItem(personajea);
    personajea->setFlag(QGraphicsItem::ItemIsFocusable);
    personajea->setFocus();
    personajea->setPos(35,75);
    if(dificultad==0){      //Novato un jugador
        tiempo=100000;
        ui->tiempo->display(tiempo/1000);
            pesos.push_back(new Pesos(180,95)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(240,200)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(400,75));escena->addItem(pesos.back());
            pesos.push_back(new Pesos(640,75)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(400,470)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(720,500)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(730,600)); escena->addItem(pesos.back());
            pesos.push_back(new Pesos(200,685)); escena->addItem(pesos.back());
            pendulos.push_back(new Pendulo(70,150,30,80)); escena->addItem(pendulos.back());
            pendulos.push_back(new Pendulo(370,570,50,80)); escena->addItem(pendulos.back());
            pendulos.push_back(new Pendulo(650,590,30,90)); escena->addItem(pendulos.back());
            puentes.push_back(new Puente(185,520)); escena->addItem(puentes.back());
            puentes.push_back(new Puente(415,520)); escena->addItem(puentes.back());
            puentes.push_back(new Puente(547,330)); escena->addItem(puentes.back());
            resortes.push_back(new Resorte(500,170,10,1000,40,0)); escena->addItem(resortes.back());
            resortes.push_back(new Resorte(70,510,10,1000,10,0)); escena->addItem(resortes.back());
            resortes.push_back(new Resorte(350,380,10,1500,30,0)); escena->addItem(resortes.back());
            resortes.push_back(new Resorte(540,420,10,1000,30,0)); escena->addItem(resortes.back());
    }
    if(dificultad==1){  //Aprendiz un jugador
        tiempo=90000;
        ui->tiempo->display(tiempo/1000);
        pesos.push_back(new Pesos(180,95)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(285,200)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(400,75));escena->addItem(pesos.back());
        pesos.push_back(new Pesos(640,75)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(255,510)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(720,500)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(730,600)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(200,685)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(175,510)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(388,160)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(500,685)); escena->addItem(pesos.back());
        pendulos.push_back(new Pendulo(70,150,30,80)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(300,570,50,80)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(630,590,30,60)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(200,150,30,50)); escena->addItem(pendulos.back());
        puentes.push_back(new Puente(415,520)); escena->addItem(puentes.back());
        puentes.push_back(new Puente(258,300)); escena->addItem(puentes.back());
        resortes.push_back(new Resorte(510,170,10,1000,60,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(80,510,10,1000,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(350,380,10,1500,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(570,420,10,1000,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(70,400,10,1000,20,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(720,260,10,1000,20,1)); escena->addItem(resortes.back());
        friccion1=new Friccion(300,490); escena->addItem(friccion1);
        friccion2=new Friccion(300,50); escena->addItem(friccion2);

    }
    if(dificultad==2){    //Experto un jugador
        tiempo=120000;
        ui->tiempo->display(tiempo/1000);
        pesos.push_back(new Pesos(180,95)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(480,230)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(400,75));escena->addItem(pesos.back());
        pesos.push_back(new Pesos(640,75)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(255,510)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(720,500)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(730,600)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(220,685)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(175,510)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(388,160)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(500,685)); escena->addItem(pesos.back());
        pesos.push_back(new Pesos(490,410)); escena->addItem(pesos.back());
        pendulos.push_back(new Pendulo(70,150,30,80)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(300,570,50,80)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(630,590,30,60)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(200,150,30,50)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(200,150,30,50)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(540,65,50,60)); escena->addItem(pendulos.back());
        puentes.push_back(new Puente(415,520)); escena->addItem(puentes.back());
        puentes.push_back(new Puente(295,200)); escena->addItem(puentes.back());
        resortes.push_back(new Resorte(510,170,10,1000,60,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(80,510,10,1000,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(350,380,10,1500,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(570,420,10,1000,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(70,400,10,1000,20,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(720,260,10,1000,20,1)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(190,620,10,1000,50,1)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(720,70,10,1000,30,1)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(500,320,10,1000,30,1)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(200,320,10,1000,20,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(240,90,10,1000,20,0)); escena->addItem(resortes.back());
        friccion1=new Friccion(300,490); escena->addItem(friccion1);
        friccion2=new Friccion(300,50); escena->addItem(friccion2);
        friccion3=new Friccion(160,360); escena->addItem(friccion3);
        friccion4=new Friccion(650,650); escena->addItem(friccion4);
    }
    timer1->start(100);
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


    h_arriba.push_back(new Paredes(40,10,-120,-320));escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(40,10,-120,-330));escena->addItem(h_abajo.back());
    h_arriba.push_back(new Paredes(140,10,-150,-440)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(140,10,-150,-450)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,110,-200,-460)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,110,-210,-460)); escena->addItem(v_derecha.back());
    //PEQUEÑA
    v_izquierda.push_back(new Paredes(10,20,-150,-440));
    //
    v_izquierda.push_back(new Paredes(10,220,-270,-220)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,220,-280,-220)); escena->addItem(v_derecha.back());


    h_arriba.push_back(new Paredes(60,10,-270,-220)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(60,10,-270,-230)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,100,-310,-120)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,100,-320,-120)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(140,10,-310,-120)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(140,10,-310,-130)); escena->addItem(h_abajo.back());
    v_izquierda.push_back(new Paredes(10,80,-600,-40)); escena->addItem(v_izquierda.back());
    v_derecha.push_back(new Paredes(10,80,-610,-40)); escena->addItem(v_derecha.back());
    h_arriba.push_back(new Paredes(60,10,-600,-120)); escena->addItem(h_arriba.back());
    h_abajo.push_back(new Paredes(60,10,-600,-130)); escena->addItem(h_abajo.back());


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
    //PEQUEÑA
    v_derecha.push_back(new Paredes(10,20,-660,-120));escena->addItem(v_derecha.back());
    //
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
