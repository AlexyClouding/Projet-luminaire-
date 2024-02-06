#ifndef INTERFACE_INFORMATION_H
#define INTERFACE_INFORMATION_H
#include <QMainWindow>
#include <QObject>
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class interface_information; }
QT_END_NAMESPACE
class interface_information : public QDialog
{
    Q_OBJECT
public:
     interface_information(QWidget *parent = nullptr);
    ~interface_information();
private:
    Ui::interface_information *ui_information;



};

#endif // INTERFACE_INFORMATION_H
