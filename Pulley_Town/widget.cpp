#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("PULLEY TOWN");
}

Widget::~Widget()
{
    delete ui;
}

//Boton nuevo usario
void Widget::on_Registro_clicked()
{
    registro.Registrar(0,0);

}
//Boton usuario antiguo
void Widget::on_Inicarsesion_clicked()
{
     QMessageBox msgBox;
     msgBox.setText(" ¿ Quieres jugar acompañado ? ");
     msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
     msgBox.setDefaultButton(QMessageBox::No);
     msgBox.setWindowTitle("MODO DE JUEGO");
     int elegido = msgBox.exec();
     switch (elegido) {
        case QMessageBox::Yes:
            registro.Registrar(1,1);   //Multijugador
            break;
        case QMessageBox::No:
            registro.Registrar(0,1);       //Un jugador
            break;
      }

}
//Ver creditos
void Widget::on_Creditos_clicked()
{
    creditos.show();
}

//Practicar
void Widget::on_practicar_clicked()
{
    extra->Mensaje();
    extra->show();
}
