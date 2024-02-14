#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMqttClient>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots :
    void messageRecu(const QByteArray &message);
    void brokerConnected();
    void stateChange();

private:
    Ui::Widget *ui;
    QMqttClient *m_client;
};
#endif // WIDGET_H
