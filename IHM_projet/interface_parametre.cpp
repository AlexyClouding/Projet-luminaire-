#include "interface_parametre.h"
#include "ui_interface_parametre.h"
interface_parametre::interface_parametre(QWidget *parent)
    : QDialog{parent}
    , ui_parametre(new Ui::interface_parametre)

{
    ui_parametre->setupUi(this);


}

interface_parametre::~interface_parametre()
{

    delete ui_parametre;
}
