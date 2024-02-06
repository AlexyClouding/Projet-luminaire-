#ifndef INTERFACE_PARAMETRE_H
#define INTERFACE_PARAMETRE_H
#include <QMainWindow>
#include <QObject>
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class interface_parametre; }
QT_END_NAMESPACE
class interface_parametre : public QDialog
{
    Q_OBJECT
public:
    interface_parametre(QWidget *parent = nullptr);
    ~interface_parametre();
private:
    Ui::interface_parametre *ui_parametre;



};

#endif // INTERFACE_PARAMETRE_H
