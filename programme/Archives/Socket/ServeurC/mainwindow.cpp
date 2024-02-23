#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serveur = new QTcpServer(this);

    connect(serveur, SIGNAL(newConnection()), this, SLOT(on_connect()));

    if (!serveur->listen(QHostAddress("172.20.251.9"), 151)) {
        qDebug() << "Erreur lors de l'écoute sur le port 151 : " << serveur->errorString();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connect()
{
    ui->test->append("Nouvelle connexion..");
    QTcpSocket *nouvelleConnexion = serveur->nextPendingConnection();

    // Lire les données de la nouvelle connexion
    connect(nouvelleConnexion, SIGNAL(readyRead()), this, SLOT(on_message()));
}

void MainWindow::on_message()
{
    // Lire les données de la socket
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();

    ui->test->append("Message reçu : " + QString(data));

    if(data=="0x01"){
        QString msg= { "01003ABCC" };
        QByteArray drop = msg.toUtf8();
        socket->write(drop);
    }
}
