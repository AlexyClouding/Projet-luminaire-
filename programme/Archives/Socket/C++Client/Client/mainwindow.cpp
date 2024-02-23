#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(disconnected()),this, SLOT(deconnecter()));
    connect(ui->drop, SIGNAL(clicked()),this,SLOT(message()));
    connect(ui->co, SIGNAL(clicked()),this,SLOT(connecter()));

    connect(socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));


    if (!socket->error())
        qDebug("erreur");
}


void MainWindow::connecter(){
    socket->connectToHost("127.0.0.1",15555);
    ui->connect->append("Connexion");
}


void MainWindow::message() {
    recup = ui->msg->toPlainText();
    data = recup.toUtf8(); // Convertir QString en QByteArray

    socket->write(data); // Écrire les données sur le socket
    QString o=socket->errorString();
    ui->connect->append(o);
    socket->flush();

    int state = socket->state(); // Récupérer l'état de la socket
    QString stateString;

    // Convertir l'état en chaîne de caractères
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        stateString = "Déconnecté";
        break;
    case QAbstractSocket::HostLookupState:
        stateString = "Recherche d'hôte";
            break;
    case QAbstractSocket::ConnectingState:
        stateString = "Connexion en cours";
        break;
    case QAbstractSocket::ConnectedState:
        stateString = "Connecté";
            break;
    case QAbstractSocket::ClosingState:
        stateString = "Fermeture en cours";
        break;
    default:
        stateString = "État inconnu";
    }

    ui->connect->append(stateString); // Ajouter l'état à l'interface utilisateur

    ui->connect->append(data);

    // Effacer les données après les avoir envoyées
    data.clear();
    recup.clear();
}


void MainWindow::displayError(QAbstractSocket::SocketError socketError) {
    qDebug() << "Error occurred: " << socketError;
}


MainWindow::~MainWindow()
{
    delete ui;
}

