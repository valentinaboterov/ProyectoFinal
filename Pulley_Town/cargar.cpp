#include "cargar.h"
#include "ui_cargar.h"

Cargar::Cargar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cargar)
{
    ui->setupUi(this);
}

Cargar::~Cargar()
{
    delete ui;
}

void Cargar::Partida(string _nombre)
{
    numero=0;
    ui->lista->clear();
    QString texto = QString::fromStdString(_nombre);
    ui->nombre->setText(texto);
    nombre=_nombre;
    char linea[200];
    string linea1="";
    bool bandera=false,terminar=true;
    int cont=0;
    numero=0;
    ifstream original("C:/Users/WIN10 PRO/Desktop/ProyectoFinal/Pulley_Town/Partidas.txt");  //Abre archivo para leer
    if(!original){         //Mira si se logró abrir los archivos exitosamente.
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    while(!original.eof()){  //Recorre todo el archivo linea a linea y lo guarda en variable linea.
        original.getline(linea,sizeof (linea));
        linea1=linea;  //Lo convierte a string.
        if(cont>0){
              if(Buscar(linea1,1)=="0"){
                  terminar=true;
              }else if(Buscar(linea1,1)=="1"){
                  terminar=true;
              }else if(Buscar(linea1,1)=="2"){
                  terminar=true;
              }else{
                  terminar=false;
              }
              if(terminar==false){
                  break;
              }else{
                  numero+=1;
                    texto = QString::fromStdString("Partida"+std::to_string(numero)+"--> Nivel: "+Buscar(linea1,1)+",tiempo restante: "+Buscar(linea1,5));
                    ui->lista->addItem(texto);

              }
         }
        if(Buscar(linea1,1)!=_nombre){
            bandera=false;
        }else{
            bandera=true;
        }
        if(bandera==true){ //Usuario que se busca
            cont=1;
        }
    }
    original.close();
    if(numero<0){
        ui->mensaje->setText("NO TIENES PARTIDAS GUARDADAS.");
    }
}

string Cargar::Buscar(string _linea, int romper)
{
        //Inicializacion de variables.
        //cant:Cantidad e elementos para el subplot,cont:acceder a diferentes valores, pos:Saber donde inicia cada valor.
        int lon=_linea.length(),cont=0,cant=0,pos=0;
        string s1="",s2="",s3="",s4="",s5="";
        for(int i=0;i<lon;i++){
            cant+=1;
            if(_linea[i]=='/'){   //Busca la separación de datos en la base.
                cont+=1;
                if(cont==1){ //Hasta este valor de i esta el nivel.
                   s1=_linea.substr(0,cant-1);  //usario.
                    pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                    cant=0;
                }if(cont==2){
                    s2=_linea.substr(0,cant-1);  //pesos
                     pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                     cant=0;
                }if(cont==3){
                    s3=_linea.substr(0,cant-1);  //pesos
                     pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                     cant=0;
                }if(cont==4){
                    s4=_linea.substr(0,cant-1);  //pesos
                     pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                     cant=0;
                }if(cont==5){
                    s5=_linea.substr(0,cant-1);  //pesos
                     pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                     cant=0;
                }
            }
        }
        if(romper==1){return s1;}
        if(romper==2){return s2;}
        if(romper==3){return s3;}
        if(romper==4){return s4;}
        if(romper==5){return s5;}
}


void Cargar::on_pushButton_clicked()
{
    if(numero>0){       //Tiene partidas guardadas
        cargar=(ui->partida->text()).toInt();
        if(cargar>numero){  //Excede la cantida de partidas
            ui->mensaje->setText("No existe esa partida.");
        }else if(cargar<1){
            ui->mensaje->setText("La partida minima es 1");
        }else{
            char linea[200];
            string linea1="",aux="";
            bool bandera=false,encontrar=false,terminar=true;
            int cont=0;
            numero=0;
            ifstream original("C:/Users/WIN10 PRO/Desktop/ProyectoFinal/Pulley_Town/Partidas.txt");  //Abre archivo para leer
            ofstream temp("C:/Users/WIN10 PRO/Desktop/ProyectoFinal/Pulley_Town/temporal.txt"); //Copia para modificar saldo.
            if(!original || !temp){         //Mira si se logró abrir los archivos exitosamente.
                cout<<"Error al abrir el archivo"<<endl;
                exit(2);
            }
            while(!original.eof()){  //Recorre todo el archivo linea a linea y lo guarda en variable linea.
                original.getline(linea,sizeof (linea));
                linea1=linea;  //Lo convierte a string.
                for(int i=0;i<3;i++){
                    if(linea1[i]=='/n'){//Si la linea a leer esta en blanco ya termino el archivo.
                        cont+=1;
                    }if(cont>1){
                        terminar=false;  //Vuelve la bandera falsa para romper el ciclo.
                        break;
                    }
                }
                if(terminar==false){
                    break;
                }
                if(cont>0){
                      if(cont==cargar){ //Linea que se necesita
                          nivel=Buscar(linea1,1);
                          pesos=Buscar(linea1,2);
                          x=Buscar(linea1,3);
                          y=Buscar(linea1,4);
                          t=Buscar(linea1,5);
                          niveles->Cargar(nivel,pesos,x,y,t);
                          encontrar=true;
                      }else{
                          cont+=1;
                      }
                 }if(Buscar(linea1,1)!=nombre){
                    bandera=false;
                }else{
                    bandera=true;
                }
                if(bandera==true){ //Usuario que se busca
                    cont=1;
                }
                if(encontrar==false){    //No es la linea
                    temp<<linea1<<endl;
                }
            }original.close();
            temp.close();
        }
    }
    niveles->llenararchivo();
}

