#include "niveles.h"
#include "ui_niveles.h"

//Inicializacion
Niveles::Niveles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Niveles)
{
    ui->setupUi(this);
    setWindowTitle("PULLEY TOWM");
    //Inicializacion de variables.
    paquetes=0;     //Paquetes jugador 1
    paquetes1=0;        //Paquetes jugador 2
    ui->paquetes->display(paquetes);
    //Pantalla
    x =0 ;
    y =0;
    ancho = 800;
    alto  = 750;
    pausa=0;
    musica=0;
    dificultad=0; //Nivel 1 por defecto.
    perdedor=new Perdedor();
    ganador=new Ganador();
    timer=new QTimer(this);     //Timer para objetos.
    timer1=new QTimer(this);    //Timer para el tiempo de juego.
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondonivel1.png"));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(actualizar_tiempo()));
    //Limpieza de listas por reinicio de juego.
    pendulos.clear();
    resortes.clear();
    pesos.clear();
    v_derecha.clear();
    v_izquierda.clear();
    h_arriba.clear();
    h_abajo.clear();
    music->setMedia(QUrl("qrc:/Imagenes/musica_nivel.mp3"));
}

Niveles::~Niveles()
{
    delete ui;
}

//Variables iniciales para el nivel,creacion de la escena.
void Niveles::Definicion(int _nivel, int modo)
{
    //Inicializacion
    cargar=0;
    ui->pausa->setIcon(QPixmap(":/Imagenes/boton_pausa.png"));
    ui->pausa->setIconSize(QSize(50,40));
    ui->Guardar->setIcon(QPixmap(":Imagenes/boton_guardar.png"));
    ui->Guardar->setIconSize(QSize(50,40));
    ui->Salir->setIcon(QPixmap(":/Imagenes/boton_salir.png"));
    ui->Salir->setIconSize(QSize(50,40));
    ui->musica->setIcon(QPixmap(":/Imagenes/boton_sonidoa.png"));
    ui->musica->setIconSize(QSize(50,40));
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondonivel1.png"));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
    final=new plataforma(35,680);   //Plataforma.
    escena->addItem(final);
    music->play();
    dificultad=_nivel;  //Determine que nivel se va a jugar
    modojuego=modo; //Un jugador o 2 jugadores
    nivel();    //Construye los muros del laberinto.
    cada_nivel();   //Pone los objetos segun el nivel
    timer->start(10);   //Empieza a actualizar los objetos
}

//Obtiene los nombre de los jugadores.
void Niveles::Nombres(string _nombre1, string _nombre2)
{
    nombre1=_nombre1;
    nombre2=_nombre2;
}

//Cuando se carga una partida anterior.
void Niveles::Cargar(string _nivel, string _bolsas, string _posx, string _posy, string _tiempo)
{
    cargar=1;
    int cant=0,pos=0,paque;
    pendulos.clear();
    resortes.clear();
    pesos.clear();
    v_derecha.clear();
    v_izquierda.clear();
    h_arriba.clear();
    h_abajo.clear();
    ui->pausa->setIcon(QPixmap(":/Imagenes/boton_pausa.png"));
    ui->pausa->setIconSize(QSize(50,40));
    ui->Guardar->setIcon(QPixmap(":Imagenes/boton_guardar.png"));
    ui->Guardar->setIconSize(QSize(50,40));
    ui->Salir->setIcon(QPixmap(":/Imagenes/boton_salir.png"));
    ui->Salir->setIconSize(QSize(50,40));
    ui->musica->setIcon(QPixmap(":/Imagenes/boton_sonidoa.png"));
    ui->musica->setIconSize(QSize(50,40));
    //Inicia las variables y genera el nivel segun dificultad.
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondonivel1.png"));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
    final=new plataforma(35,680);   //Plataforma.
    escena->addItem(final);
    dificultad=stoi(_nivel);
    modojuego=0;
    nivel();
    cada_nivel();
    //Le da la nueva posicion al personaje y actualiza el tiempo
    personajea->setPos(stoi(_posx),stoi(_posy));
    personajea->setx(stoi(_posx));
    personajea->sety(stoi(_posy));
    tiempo=stoi(_tiempo);
    //Elimina los pesos que ya fueron tomados
    if(_bolsas.length()>=1){
        for(int i=0;i<_bolsas.length();i++){
            cant+=1;
            if(_bolsas[i]==','){
                paque=stoi(_bolsas.substr(pos,cant-1));   //Toma el peso del string
                escena->removeItem(pesos.at(paque));   //Remueve el item de la escena
                pesos=cambiar(pesos,paque);   //Lo elimina de la lista
                paquetes+=1;    //Suma que se relecto un paquete.
                pos=i+1;    //Reinicia variables para siguiente.
                cant=0;
            }
        }
    }
    ui->paquetes->display(paquetes);    //Actualiza valor en el display.
    timer->start(10);   //Empieza a actualizar los objetos
    music->play();
}

//Actualiza los objetos en la escena.
void Niveles::actualizar(){
    for(int i=0;i<pendulos.length();i++){
        pendulos.at(i)->actualizar();
    }
    for(int i=0;i<resortes.length();i++){
        resortes.at(i)->actualizar();
    }
}

//Actualiza el tiempo de juego.
void Niveles::actualizar_tiempo()
{
    tiempo-=100;
    ui->tiempo->display(tiempo/1000);
    //Se acabo el tiempo y pierde.
    if(tiempo<1000){
        perdedor->Causa(2);
        perdedor->show();
        this->close();
        Reiniciar();
        music->stop();   
    }
}

//Pausa o reanuda el juego.
void Niveles::on_pausa_clicked()
{
    //Si se oprime un avez pausa el juego.
    if(pausa==0){
        timer1->stop();
        timer->stop();
        //Cambia el icono.
        ui->pausa->setIcon(QPixmap(":/Imagenes/boton_play.png"));
        //Actualiza la variable.
        pausa=1;
    }else{  //Reanudar.
        timer->start();
        timer1->start();
        ui->pausa->setIcon(QPixmap(":/Imagenes/boton_pausa.png"));
        pausa=0;
    }
}

void Niveles::on_musica_clicked()
{
    //Si se oprime un avez pausa el juego.
    if(musica==0){
        music->stop();
        //Cambia el icono.
        ui->musica->setIcon(QPixmap(":/Imagenes/boton_sonidop.png"));
        //Actualiza la variable.
        musica=1;
    }else{  //Reanudar.
        music->play();
        ui->musica->setIcon(QPixmap(":/Imagenes/boton_sonidoa.png"));
        musica=0;
    }
}
//Guardar partida.
void Niveles::on_Guardar_clicked()
{   //Para los timers.
    timer->stop();
    timer1->stop();
    //Solo se permite guardar partida con un solo jugador.
    if(modojuego==1){   //Multijugador sale QMessageBox.
        timer1->stop();
        QMessageBox msgBox;
        msgBox.setText("No se permite guardar partidas en modo multijugador. ");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setWindowTitle("GUARDAR");
        msgBox.setIconPixmap(QPixmap(":/Imagenes/boton_guardar.png"));
        int elegido = msgBox.exec();
        switch (elegido) {
           case QMessageBox::Ok:
            timer1->start();
            break;
         }
    }else{  //Guarda la partida en un archivo de texto.
        if(cargar==0){  //No es una partida cargada
            sobreescribir(nombre1);     //Cambia el archivo de texto.
            QMessageBox msgBox;
            msgBox.setText("     Partida guardada. ");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setWindowTitle("GUARDAR");
            msgBox.setIconPixmap(QPixmap(":/Imagenes/boton_guardar.png"));
            int elegido = msgBox.exec();
            switch (elegido) {
               case QMessageBox::Ok:
                   this->close();
                   break;
             }
            Reiniciar();        //Como se cierra la pventana se debe reiniciar
            music->stop();
        }else{
            QMessageBox msgBox;
            msgBox.setText(" No puedes guardar una partida cargada. ");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setWindowTitle("GUARDAR");
            msgBox.setIconPixmap(QPixmap(":/Imagenes/boton_guardar.png"));
            int elegido = msgBox.exec();
            switch (elegido) {
               case QMessageBox::Ok:
                   break;
             }
        }

    }
}

//Cierra la ventana y vuelve al inicio.
void Niveles::on_Salir_clicked()
{
    this->close();
    Reiniciar();
}

//Sirve para manejar los archivos de texto, los cuales están organizados al
//separarlos con "/" . Por tanto se busca la cantidad de separardores segun
//el dato que se busca.
string Niveles::Buscar(string linea, int romper){
    //Inicializacion de variables.
    //cant:Cantidad e elementos para el subplot,cont:acceder a diferentes valores, pos:Saber donde inicia cada valor.
    int lon=linea.length(),cont=0,cant=0,pos=0;
    string s1="",s2="";
    for(int i=0;i<lon;i++){
        cant+=1;
        if(linea[i]=='/'){   //Busca la separación de datos en la base.
            cont+=1;
            if(cont==1){ //Hasta este valor de i esta el usuario.
               s1=linea.substr(0,cant-1);  //usario.
            }
        }
    }

    if(romper==1){return s1;}
}

//Actualiza el archivo con la nueva partida guardada.
void Niveles::sobreescribir(string usuario){
    //Inicializacion de variables.
    string nombre="",nivel="",pesos="",posx="",posy="";
    char linea[200];
    string linea1="",aux="",usuario1;
    bool terminar=true,ban1=true;
    ifstream original("../Pulley_Town/Partidas.txt");  //Abre archivo para leer
    ofstream temp("../Pulley_Town/temporal.txt"); //Copia para modificar
    while(!original.eof()){
        original.getline(linea,sizeof (linea)); //Accede a cada linea del archivo.
        usuario1=Buscar(linea,1);  //Usuario de la linea
        if(usuario!=usuario1){  //Si son diferentes la bandera 1 es falsa.
               ban1=false;
        }else{
               ban1=true;
        }
        if(ban1==true){ //Si encuentra el usario guarda la partida.
            aux=std::to_string(dificultad)+'/'+bolsas+'/'+std::to_string(personajea->getx())+'/'+std::to_string(personajea->gety())+"/"+std::to_string(tiempo)+"/";
            temp<<nombre1<<"/"<<endl;
            temp<<aux<<endl;    //Cambia la linea deseada en el archivo temporal.
            terminar=false;
        }else{
            if(usuario1==""){
                break;
            }else{
                temp<<linea<<endl;
            }
        }

    }
    if(terminar==true){     //Nunca encontro el usuario.
        aux=std::to_string(dificultad)+'/'+bolsas+'/'+std::to_string(personajea->getx())+'/'+std::to_string(personajea->gety())+"/"+std::to_string(tiempo)+"/";
        temp<<nombre1<<"/";
        temp<<endl<<aux;
    }
    original.close();temp.close();  //Cierra archivos
    llenararchivo();  
}

//Reinicia valores al cerrar la ventana
void Niveles::Reiniciar()
{
    timer->stop();
    timer1->stop();
    music->stop();
    bolsas="";
    pendulos.clear();
    resortes.clear();
    pesos.clear();
    v_derecha.clear();
    v_izquierda.clear();
    h_arriba.clear();
    h_abajo.clear();
    if(modojuego==0){
         escena->removeItem(personajea);
    }else{
       escena->removeItem(personajea);
       escena->removeItem(personajeb);
    }
}

//Intercambia archivo temporal por el original.
void Niveles::llenararchivo(){
    char linea[200];
    string linea1="";
    ifstream temp("../Pulley_Town/temporal.txt");  //Abre archivo para leer
    ofstream sudo("../Pulley_Town/Partidas.txt");  //Archivo final con informacion actualizada.
    while(!temp.eof()){  //Hasta que llegue al final del archivo
        temp.getline(linea,sizeof (linea));     //Toma linea a linea
        linea1=linea;
        sudo<<linea1<<endl;     //Lo lleva a al archivo final.
    }
    temp.close();sudo.close();//Cierra archivos.

}

//Movimiento de los personajes.
void Niveles::keyPressEvent(QKeyEvent *evento){
    //Un jugador.
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
    if(modojuego==1){   //Multijugador
    if(evento->key()==Qt::Key_J){
                personajeb->Left();
                Colisiones(personajeb);

    }
    else if(evento->key()==Qt::Key_L){
                personajeb->Rigth();
                Colisiones(personajeb);
    }
    else if(evento->key()==Qt::Key_I){
                personajeb->Up();
                Colisiones(personajeb);
    }
    else if(evento->key()==Qt::Key_K){
                personajeb->Down();
                Colisiones(personajeb);
    }
    }
}

//Colisiones del personaje
void Niveles::Colisiones(Personaje *personaje1)
{
    //Colisiona con muro , lo envia en la direccion contraria.
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
    //Colisiona con pendulo pierde
    for(int i=0;i<pendulos.size();i++){
        if(personaje1->collidesWithItem(pendulos.at(i))){
            //PIERDE
            this->close();
            if(modojuego==0){
                perdedor->Nombre(nombre1);
                perdedor->Causa(0);
                perdedor->show();
            }else{
                if(personaje1==personajea){
                    ganador->Nombre(nombre2);
                    ganador->Multi(nombre1,0);
                    ganador->show();
                }else{
                    ganador->Nombre(nombre1);
                    ganador->Multi(nombre2,0);
                    ganador->show();
                }
            }Reiniciar();
            music->stop();
        }
    }
    //Colisiona con resorte pierde
    for(int i=0;i<resortes.size();i++){
        if(personaje1->collidesWithItem(resortes.at(i))){
            //PIERDE
            this->close();
            if(modojuego==0){
                perdedor->Nombre(nombre1);
                perdedor->Causa(1);
                perdedor->show();
            }else{
                if(personaje1==personajea){
                    ganador->Nombre(nombre2);
                    ganador->Multi(nombre1,1);
                    ganador->show();
                }else{
                    ganador->Nombre(nombre1);
                    ganador->Multi(nombre2,1);
                    ganador->show();
                }
            }
            Reiniciar();
            music->stop();
        }
    }
    //Colisiona con pesos, elimina el peso de la escena y aumenta paquetes.
    if(personaje1==personajea){
        for(int i=0;i<pesos.size();i++){
            if(personaje1->collidesWithItem(pesos.at(i))){
                escena->removeItem(pesos.at(i));
                bolsas+=std::to_string(i)+",";
                pesos=cambiar(pesos,i);
                paquetes+=1;
                ui->paquetes->display(paquetes);
            }
         }
    }if(personaje1==personajeb){
            for(int i=0;i<pesos.size();i++){
                if(personaje1->collidesWithItem(pesos.at(i))){
                    escena->removeItem(pesos.at(i));
                    pesos=cambiar(pesos,i);
                    paquetes1+=1;
                    ui->paquetes1->display(paquetes);
                }
            }
    }
    //Si colisiona con puente lo mueve posiciones a la derecha.
    for(int i=0;i<puentes.size();i++){
        if(personaje1->collidesWithItem(puentes.at(i))){
            personaje1->puente();
        }
    }
    //Si colisiona con plataforma cierra la pantalla y abre la polea.
    if(personaje1->collidesWithItem(final)){
        this->close();
        polea=new Polea_ventana();
        if(personaje1==personajea){
            polea->valores(paquetes*kilos,dificultad);
            polea->Nombre(nombre1);
            this->close();
        }if(personaje1==personajeb){
            polea->valores(paquetes1*kilos,dificultad);
            polea->Nombre(nombre2);
            polea->show();
        }
        Reiniciar();
    }
}

//Elimina los pesos de la lista.
QList<Pesos *> Niveles::cambiar(QList<Pesos *> lista, int pos)
{
    QList<Pesos*> aux;      //Lista auxiliar a retornar
    for(int i=0;i<lista.size();i++){
        if(i!=pos){ //Lo agrega a la lista auxiliar si no es el que se desea eliminar.
            aux.push_back(lista.at(i));
        }
    }
    return aux; //Retorna la lista.
}

//Genera cada nivel segun dificultad.
void Niveles::cada_nivel()
{
    paquetes=0;
    paquetes1=0;
    bolsas="";
    ui->paquetes->display(paquetes);
    ui->paquetes1->display(paquetes1);
    //Se agrega a la escena el primer personaje.
    personajea=new Personaje(0,35,75);
    escena->addItem(personajea);
    personajea->setFlag(QGraphicsItem::ItemIsFocusable);
    personajea->setFocus();
    personajea->setPos(35,75);
    //Se agrega el nombre del jugador
    QString texto = QString::fromStdString(nombre1);
    ui->jugador1->setText(texto);
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
            resortes.push_back(new Resorte(60,510,10,1000,10,0)); escena->addItem(resortes.back());
            resortes.push_back(new Resorte(350,380,10,1500,30,0)); escena->addItem(resortes.back());
            resortes.push_back(new Resorte(540,420,10,1000,30,0)); escena->addItem(resortes.back());
        if(modojuego==1){   //Multijugador.
            personajeb=new Personaje(1,35,75);
            escena->addItem(personajeb);
            personajeb->setFlag(QGraphicsItem::ItemIsFocusable);
            personajeb->setFocus();
            personajeb->setPos(35,80);
            texto = QString::fromStdString(nombre2);
            ui->jugador2->setText(texto);
        }
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
        pendulos.push_back(new Pendulo(730,240,30,80)); escena->addItem(pendulos.back());
        if(modojuego==1){   //Multijugador
            personajeb=new Personaje(1,35,75);
            escena->addItem(personajeb);
            personajeb->setFlag(QGraphicsItem::ItemIsFocusable);
            personajeb->setFocus();
            personajeb->setPos(35,80);
            texto = QString::fromStdString(nombre2);
            ui->jugador2->setText(texto);
        }
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
        pendulos.push_back(new Pendulo(730,260,30,80)); escena->addItem(pendulos.back());
        pendulos.push_back(new Pendulo(500,290,30,80)); escena->addItem(pendulos.back());
        puentes.push_back(new Puente(415,520)); escena->addItem(puentes.back());
        puentes.push_back(new Puente(295,200)); escena->addItem(puentes.back());
        resortes.push_back(new Resorte(510,200,10,1000,60,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(80,510,10,1000,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(350,380,10,1500,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(570,420,10,1000,30,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(70,400,10,1000,20,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(190,620,10,1000,50,1)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(720,70,10,1000,30,1)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(200,320,10,1000,20,0)); escena->addItem(resortes.back());
        resortes.push_back(new Resorte(240,90,10,1000,20,0)); escena->addItem(resortes.back());
        if(modojuego==1){   //Multijugador.
            personajeb=new Personaje(1,35,75);
            escena->addItem(personajeb);
            personajeb->setFlag(QGraphicsItem::ItemIsFocusable);
            personajeb->setFocus();
            personajeb->setPos(70,75);
            texto = QString::fromStdString(nombre2);
            ui->jugador2->setText(texto);
        }
    }
    timer1->start(100);
}

//Genra paredes del laberinto
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





