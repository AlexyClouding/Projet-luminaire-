#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QByteArray>
#include <QtWidgets/QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_client = new QMqttClient(this);
    m_client->setHostname("eu1.cloud.thethings.network");
    m_client->setUsername("lorawan-e51-test@ttn");
    m_client->setPassword("NNSXS.EOGBAUGP5D57BT325SYUJNQDYSC4PMEEIBT7CTQ.ADSYG73SL52TJYLVHIEDCU55MMRKSPBXJT67ZG46GQNUIHJIH3QA");
    m_client->setPort(1883);
    if (m_client->state() == QMqttClient::Disconnected) {
        m_client->connectToHost();
    }
    connect(m_client, &QMqttClient::stateChanged, this, &Widget::stateChange);
    connect(m_client,&QMqttClient::connected,this,&Widget::brokerConnected);
    connect(m_client, &QMqttClient::messageReceived, this,&Widget::messageRecu);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::stateChange(){
    qDebug()<<m_client->state();
}

void Widget::brokerConnected(){
    QString topic = "#";
    auto subscription = m_client->subscribe(topic);
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
}

void Widget::messageRecu(const QByteArray &message){
    QJsonDocument jsonreponse = QJsonDocument::fromJson(message);
    QJsonObject jsonobject= jsonreponse.object();
    QJsonObject mess = jsonobject["uplink_message"].toObject();
    QString toto = mess["frm_payload"].toString();
    qDebug()<< "Reçu à : "<<jsonobject["received_at"];
    qDebug()<< "Message : "<<QByteArray::fromBase64(mess["frm_payload"].toString().toUtf8());
    ui->label_info->setText(QByteArray::fromBase64(mess["frm_payload"].toString().toUtf8()));
}