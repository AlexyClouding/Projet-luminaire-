#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serveur = new QTcpServer(this);

    connect(serveur, SIGNAL(newConnection()), this, SLOT(on_connect()));

    if (!serveur->listen(QHostAddress("127.0.0.1"), 151)) {
        qDebug() << "Erreur lors de l'écoute sur le port 151 : " << serveur->errorString();
    }
    else {
        ui->test->append("OPEN");
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

    ui->test->append("DeVid_recv : " + QString(data));

        if(data=="A7s5D9b_"){
        ui->test->append("DeV_Id_is_valid");

        QStringList msg = {"0x01", "0x03", "0xAB", "0xCC"}; // faire un tableau de chaine de charactère

        QByteArray drop;   // Crée un tableau de byte

        for (const QString &recup : msg) { //const QString &s fait référence à : msg fait appel a un string nommé msg

            drop.append(recup.toInt(nullptr, 16));  // appel le tableau de byte pour ajouté à l'intérieur(append) un élément du tableau string(recup) et la boucle se répète tant que msg!=NULL
        }


        socket->write(drop);
        ui->test->append("------------");
    }
}
