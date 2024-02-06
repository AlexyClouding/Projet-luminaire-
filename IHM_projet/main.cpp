#include "interface_principale.h"
#include "interface_information.h"
#include "interface_parametre.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface_principale w;
    w.show();
    return a.exec();
}
