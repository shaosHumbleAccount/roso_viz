#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modelController = new FieldModelController();
    udpServer = new UdpServer();

    connect(udpServer, SIGNAL(messageRecieved(QString)),modelController, SLOT(updateState(QString)));

    connect(modelController, SIGNAL(updateScene(StateForTimestep&)),
            ui->rosoFieldWdgt, SLOT(on_updateScene(StateForTimestep&)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClear_triggered()
{
    modelController->clearScene();
}

void MainWindow::on_actionRotate_Clockwise_triggered()
{
    ui->rosoFieldWdgt->rotateScene(ui->rosoFieldWdgt->getRotate() + 90);
}
