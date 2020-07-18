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
        timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
        timer->start(10);
        ui->graphicsView->setScene(escena);
        ui->graphicsView->resize(ancho,alto);
        pendulo1=new Pendulo(40,150,30,80);
        escena->addItem(pendulo1);
        resorte1=new Resorte(200,200,10,1);
        escena->addItem(resorte1);
        pendulo2=new Pendulo(700,50,40,60);
        escena->addItem(pendulo2);
        pendulo3=new Pendulo(690,270,20,80);
        escena->addItem(pendulo3);
        pendulo4=new Pendulo(600,600,60,40);
        escena->addItem(pendulo4);
        personaje=new Personaje();
        escena->addItem(personaje);
        personaje->setFlag(QGraphicsItem::ItemIsFocusable);
        personaje->setFocus();
        personaje->setPos(35,75);
        pesos=new Pesos(180,80);
        escena->addItem(pesos);
        escena->setBackgroundBrush(QPixmap(":/Imagenes/Fondonivel.jpeg"));
        nivel();

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
    pendulo1->actualizar();
    pendulo2->actualizar();
    pendulo3->actualizar();
    pendulo4->actualizar();
    resorte1->actualizar();
}
void Niveles::keyPressEvent(QKeyEvent *evento){
    if(evento->key()==Qt::Key_A){
                personaje->Left();
    }
    else if(evento->key()==Qt::Key_D){
                personaje->Rigth();
    }
    else if(evento->key()==Qt::Key_W){
                personaje->Up();
    }
    else if(evento->key()==Qt::Key_S){
            personaje->Down();
    }
}
void Niveles::nivel(){
    //Definicion nivel.
    muro1= new Paredes(20,490,-20,-130);  escena->addItem(muro1);
    muro2=new Paredes(20,700,-760,-20);  escena->addItem(muro2);
    muro3=new Paredes(740,20,-20,-20);  escena->addItem(muro3);
    muro4=new Paredes(760,20,-20,-710);  escena->addItem(muro4);
    pared1=new Paredes(10,100,-200,-40); escena->addItem(pared1);
    pared2=new Paredes(10,100,-210,-40); escena->addItem(pared2);
    pared3=new Paredes(60,10,-40,-130); escena->addItem(pared3);
    pared4=new Paredes(60,10,-40,-140); escena->addItem(pared4);
    pared5=new Paredes(60,10,-160,-130); escena->addItem(pared5);
    pared6=new Paredes(60,10,-160,-140); escena->addItem(pared6);
    pared7=new Paredes(10,220,-160,-130); escena->addItem(pared7);
    pared8=new Paredes(10,220,-170,-130); escena->addItem(pared8);
    pared9=new Paredes(60,10,-100,-230); escena->addItem(pared9);
    pared10=new Paredes(60,10,-100,-240); escena->addItem(pared10);
    pared11=new Paredes(60,10,-100,-330); escena->addItem(pared11);
    pared12=new Paredes(60,10,-100,-340); escena->addItem(pared12);
    pared13=new Paredes(200,10,-90,-420); escena->addItem(pared13);
    pared14=new Paredes(200,10,-90,-430); escena->addItem(pared14);
    pared15=new Paredes(10,130,-200,-440); escena->addItem(pared15);
    pared16=new Paredes(10,130,-210,-440); escena->addItem(pared16);
    pared17=new Paredes(80,10,-360,-500); escena->addItem(pared17);
    pared18=new Paredes(80,10,-360,-510); escena->addItem(pared18);
    pared19=new Paredes(10,200,-270,-220); escena->addItem(pared19);
    pared20=new Paredes(10,200,-280,-220); escena->addItem(pared20);
    pared21=new Paredes(60,10,-270,-220); escena->addItem(pared21);
    pared22=new Paredes(60,10,-270,-230); escena->addItem(pared22);
    pared23=new Paredes(10,100,-310,-120); escena->addItem(pared23);
    pared24=new Paredes(10,100,-320,-120); escena->addItem(pared24);
    pared25=new Paredes(180,10,-310,-120); escena->addItem(pared25);
    pared26=new Paredes(180,10,-310,-130); escena->addItem(pared26);
    pared27=new Paredes(10,80,-580,-40); escena->addItem(pared27);
    pared28=new Paredes(10,80,-590,-40); escena->addItem(pared28);
    pared29=new Paredes(70,10,-580,-120); escena->addItem(pared29);
    pared30=new Paredes(70,10,-580,-130); escena->addItem(pared30);
    pared31=new Paredes(10,90,-430,-140); escena->addItem(pared31);
    pared32=new Paredes(10,90,-440,-140); escena->addItem(pared32);
    pared33=new Paredes(120,10,-640,-210); escena->addItem(pared33);
    pared34=new Paredes(120,10,-640,-220); escena->addItem(pared34);
    pared35=new Paredes(130,10,-430,-270); escena->addItem(pared35);
    pared36=new Paredes(130,10,-430,-280); escena->addItem(pared36);
    pared37=new Paredes(10,100,-560,-270); escena->addItem(pared37);
    pared38=new Paredes(10,100,-570,-270); escena->addItem(pared38);
    pared39=new Paredes(80,10,-520,-370); escena->addItem(pared39);
    pared40=new Paredes(80,10,-520,-380); escena->addItem(pared40);
    pared41=new Paredes(10,60,-520,-370); escena->addItem(pared41);
    pared42=new Paredes(10,60,-530,-370); escena->addItem(pared42);
    pared43=new Paredes(100,10,-440,-430); escena->addItem(pared43);
    pared44=new Paredes(100,10,-440,-440); escena->addItem(pared44);
    pared45=new Paredes(10,200,-430,-370); escena->addItem(pared45);
    pared46=new Paredes(10,200,-440,-370); escena->addItem(pared46);
    pared47=new Paredes(10,200,-360,-320); escena->addItem(pared47);
    pared48=new Paredes(10,200,-370,-320); escena->addItem(pared48);
    pared49=new Paredes(70,10,-290,-320); escena->addItem(pared49);
    pared50=new Paredes(70,10,-290,-330); escena->addItem(pared50);
    pared51=new Paredes(140,10,-620,-540); escena->addItem(pared51);
    pared52=new Paredes(140,10,-620,-550); escena->addItem(pared52);
    pared53=new Paredes(10,70,-680,-560); escena->addItem(pared53);
    pared54=new Paredes(10,70,-690,-560); escena->addItem(pared54);
    pared55=new Paredes(10,70,-440,-640); escena->addItem(pared55);
    pared56=new Paredes(10,70,-450,-640); escena->addItem(pared56);
    pared57=new Paredes(10,70,-620,-470); escena->addItem(pared57);
    pared58=new Paredes(10,70,-630,-470); escena->addItem(pared58);
    pared59=new Paredes(10,70,-80,-640); escena->addItem(pared59);
    pared60=new Paredes(10,70,-90,-640); escena->addItem(pared60);
    pared61=new Paredes(410,10,-40,-560); escena->addItem(pared61);
    pared62=new Paredes(410,10,-40,-570); escena->addItem(pared62);
    pared63=new Paredes(10,60,-160,-580); escena->addItem(pared63);
    pared64=new Paredes(10,60,-170,-580); escena->addItem(pared64);
    pared65=new Paredes(50,10,-620,-470); escena->addItem(pared65);
    pared66=new Paredes(50,10,-620,-480); escena->addItem(pared66);
    pared67=new Paredes(10,180,-670,-310); escena->addItem(pared67);
    pared68=new Paredes(10,180,-680,-310); escena->addItem(pared68);
    pared69=new Paredes(10,190,-540,-520); escena->addItem(pared69);
    pared70=new Paredes(10,190,-550,-520); escena->addItem(pared70);
}
