#include "interface_principale.h"
#include "ui_interface_principale.h"
#include "interface_information.h"
#include "interface_parametre.h"
interface_principale::interface_principale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interface_principale),
    information(this),
    parametre(this)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("border: 1px solid black;");

    ui->frame->setStyleSheet("background-color:lightgreen");

    ui->frame_2->setStyleSheet("border: 1px solid black;");

    ui->frame_2->setStyleSheet("background-color:lightgreen");

    QObject::connect(ui->button_information,&QPushButton::clicked, this, &interface_principale::fenetre_information);
    QObject::connect(ui->button_parametre,&QPushButton::clicked, this, &interface_principale::fenetre_parametre);
    QObject::connect(ui->quitter, SIGNAL(clicked()), qApp , SLOT(quit()));


}


void interface_principale::fenetre_information()
{

    information.show();
}
void interface_principale::fenetre_parametre()
{

    parametre.show();
}



interface_principale::~interface_principale()
{
    delete ui;
}
