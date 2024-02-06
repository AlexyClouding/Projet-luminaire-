#ifndef INTERFACE_PRINCIPALE_H
#define INTERFACE_PRINCIPALE_H

#include <QMainWindow>
#include "interface_information.h"
#include "interface_parametre.h"
QT_BEGIN_NAMESPACE
namespace Ui { class interface_principale; }
QT_END_NAMESPACE

class interface_principale : public QMainWindow
{
    Q_OBJECT

public:
    interface_principale(QWidget *parent = nullptr);
    ~interface_principale();
    void fenetre_information();
    void fenetre_parametre();
private:
    Ui::interface_principale *ui;
    interface_information information;
    interface_parametre parametre;


};
#endif // INTERFACE_PRINCIPALE_H
