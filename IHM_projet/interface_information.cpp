#include "interface_information.h"
#include "ui_interface_information.h"
interface_information::interface_information(QWidget *parent)
    : QDialog{parent}
    , ui_information(new Ui::interface_information)

{
    ui_information->setupUi(this);


}

interface_information::~interface_information()
{

    delete ui_information;

}
