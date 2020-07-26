#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    setWindowTitle("Registro");
    cont=0;
}

Registro::~Registro()
{
    delete ui;
}


bool Registro::validacion(string _usuario,string _clave)
{
    char linea[400];
    bool ban1=true,ban2=true,acceso=false;
    string usuario,clave;
    ui->label->setText("");
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    if(tipojugador==0){ //Usuario nuevo, se agrega al final del documento
        ifstream base("C:/Users/WIN10 PRO/Desktop/ProyectoFinal/Pulley_Town/Usuarios.txt");  //Abre el archivo
        int lonu=_usuario.length();
        while(!base.eof()){
            base.getline(linea,sizeof (linea)); //Accede a cada linea del archivo.
            usuario=Buscar(linea,1);  //Usuario de la linea
            for(int i=0;i<lonu;i++){        //Compara el usuario de la linea con el ingresado
               if(usuario[i]!=_usuario[i]){  //Si son diferentes la bandera 1 es falsa.
                   ban1=false;
                   break;
               }
            }if(ban1==true){ //Si encuentra el usario debe registrar otro.
               acceso= true;
               ui->lineEdit->setText("");
               ui->lineEdit_2->setText("");
            }if(acceso==true){
               ui->label->setText("Usuario ya registrado.");
               ui->lineEdit->setText("");
               ui->lineEdit_2->setText("");
               return false;
            }
            if(usuario==""){
                break;
            }
            ban1=true;
        }
        base.close();
        if(acceso==false){      //No existe el usuario
            ofstream outfile;      //Abre archivo de salida.
            ofstream partida;
            int lon=_clave.length();
            if(lon!=4){   //Clave ingresada mas de 4 numeros.
                 ui->label->setText("La clave debe ser de 4 digitos");
                 ui->lineEdit_2->setText("");
                 return false;
            }else{
                outfile.open("C:/Users/WIN10 PRO/Desktop/ProyectoFinal/Pulley_Town/Usuarios.txt",std::fstream::app);  //Lo abre como archivo de salida y escribe al final(app).
                partida.open("C:/Users/WIN10 PRO/Desktop/ProyectoFinal/Pulley_Town/Partidas.txt",std::fstream::app);
                if(!outfile.is_open()){          //Si no abrio exitosamente se acaba el programa.
                       exit(1);
                 }
                 outfile<<_usuario<<"/"<<_clave<<"/"<<endl;
                 partida<<_usuario<<"/"<<endl;
                 outfile.close();
                 partida.close();
                 ui->lineEdit->setText("");
                 ui->lineEdit_2->setText("");
                 return true;
            }
         }
    }else{      //Usuario antiguo,Se valida la cuenta
        ifstream base("C:/Users/WIN10 PRO/Desktop/ProyectoFinal/Pulley_Town/Usuarios.txt");  //Abre el archivo
        int lonu=_usuario.length(),lonc=_clave.length();
        while(!base.eof()){
            base.getline(linea,sizeof (linea)); //Accede a cada linea del archivo.
                usuario=Buscar(linea,1);  //Usuario de la linea
                clave=Buscar(linea,2);    //Clave de la linea
                for(int i=0;i<lonu;i++){        //Compara el usuario de la linea con el ingresado
                    if(usuario[i]!=_usuario[i]){  //Si son diferentes la bandera 1 es falsa.
                        ban1=false;
                        break;
                    }
                }for(int i=0;i<lonc;i++){  //Compara la clave de la linea con la ingresada.
                    if(clave[i]!=_clave[i]){  //Si son diferentes bandera 2 falsa.
                        ban2=false;
                        break;
                    }
                }if(ban1==true&&ban2==true){ //Si el usuario y clave ingresados son iguales a la linea
                    acceso=true;
                }if(acceso==true){      //El acceso es correcto.
                    return true;
                    ui->lineEdit->setText("");
                    ui->lineEdit_2->setText("");
                }
                if(usuario==""){
                    break;
                }
            ban1=true;ban2=true;
       }if(acceso==false){
            ui->label->setText("Clave o usuario incorrecto.");
            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            return false;
        }
        base.close();
    }acceso=false;
}

void Registro::Registrar(int _modojuego, int _tipojugador)
{
    ui->jugador->setText("JUGADOR 1");
    modojuego=_modojuego;
    tipojugador=_tipojugador;
    this->show();
}

//Busca los valores de CC,Clave y saldo en una linea codificada y retorna un string dependiendo de romper.
string Registro::Buscar(string _linea,int romper){
    //Inicializacion de variables.
    //cant:Cantidad e elementos para el subplot,cont:acceder a diferentes valores, pos:Saber donde inicia cada valor.
    int longitud=_linea.length(),cont=0,cant=0,pos=0;
    string s1="",s2="";
    for(int i=0;i<longitud;i++){
        cant+=1;
        if(_linea[i]=='/'){   //Busca la separación de datos en la base.
            cont+=1;
            if(cont==1){ //Hasta este valor de i esta el usuario.
                s1=_linea.substr(0,cant-1);  //usario.
                pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                cant=0;
            }if(cont==2){
                s2=_linea.substr(pos,cant-1);    //clave
            }
        }
    }
    if(romper==1){return s1;}
    if(romper>=2){return s2;}
};

void Registro::on_Entrar_clicked()
{
        nombre1=ui->lineEdit->text().toStdString();
        clave1=ui->lineEdit_2->text().toStdString();
        ui->label->setText("");
        if(validacion(nombre1,clave1)==true){
            if(modojuego!=0 && cont>0){   //MULTIJUGADOR Y SEGUNDO REGISTRO
                modo.Nombre(nombre1,tipojugador,1);
                modo.show();
                modo.Modo(modojuego);
                this->close();
            }else if(modojuego==0){ //UN SOLO JUGADOR
                modo.Nombre(nombre1,tipojugador,0);
                modo.show();
                modo.Modo(modojuego);
                this->close();
            }else{      //CONT==0, primer registro multijugador
                modo.Nombre(nombre1,tipojugador,0);
                this->close();
                ui->jugador->setText("JUGADOR 2");
                ui->lineEdit->setText("");
                ui->lineEdit_2->setText("");
                cont+=1;
                this->show();
            }
        }
}
