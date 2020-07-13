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
        QRect Desktop = QApplication::desktop()->screenGeometry();
        x = Desktop.x();
        y = Desktop.y();
        ancho = 828;
        alto  = 441;      
        //Se genera la escena
        escena = new QGraphicsScene(x,y,ancho,alto);
        timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
        timer->start(10);
        //Imagen de fondo para la escena
    if(dificultad==0 && modojuego==0){ //Novato,un solo jugador
        //Imagen de fondo para la escena
        escena->setBackgroundBrush(QPixmap(":/Imagenes/nivel2.jpeg"));
        //En la interfaz se agrega graphicsView y se pone la escena creada
        ui->graphicsView->setScene(escena);
        pendulo=new Pendulo(320,130,50,60);
        escena->addItem(pendulo);
        personaje=new Personaje();
        escena->addItem(personaje);
        personaje->setFlag(QGraphicsItem::ItemIsFocusable);
        personaje->setFocus();
        personaje->setPos(345,200);
        pesos=new Pesos(300,200);
        escena->addItem(pesos);

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
    pendulo->actualizar();
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
