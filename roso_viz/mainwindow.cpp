#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qRegisterMetaType<StateForTimestep>("StateForTimestep&");

    ui->setupUi(this);
    modelController = new FieldModelController();
    udpServer = new UdpServer();
    modeManager = new ModeManager();
    recorder = new Recorder();
    player = new RecordPlayer();

    connect(udpServer, SIGNAL(messageRecieved(QString)),modelController, SLOT(updateState(QString)));

    connect(modelController, SIGNAL(updateScene(StateForTimestep&)),
            modeManager, SLOT(on_updateScene_live(StateForTimestep&)));

    connect(modeManager, SIGNAL(updateScene(StateForTimestep&)),
            ui->rosoFieldWdgt, SLOT(on_updateScene(StateForTimestep&)));

    connect(modelController,SIGNAL(updateScene(StateForTimestep&)),
            recorder, SLOT(on_updateScene(StateForTimestep&)));

    connect(recorder, SIGNAL(recordsUpdated()), this, SLOT(on_recordsUpdated()));

    connect(player,SIGNAL(updateScene(StateForTimestep&)),
            modeManager, SLOT(on_updateScene_replay(StateForTimestep&)));

    connect(player, SIGNAL(recordPlayingFinished()),this,SLOT(on_player_finished()));

    ui->record_ListView->setModel(&recordListModel);
    on_liveMode_radioButton_toggled(true);

    ui->record_ListView->setSelectionMode(QListView::SingleSelection);
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

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Roso_Viz", "<b>Author</b>: Tianlan Shao<br><b>Contact</b>: shaotianlan.de@gmail.com<br><br><b>Github</b>: https://github.com/shaosHumbleAccount/roso_viz<br><br>Published under MIT licence.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.");
}


void MainWindow::on_liveMode_radioButton_toggled(bool checked)
{
    if(checked)
    {
        modeManager->setMode(ModeManager::LIVE);
        ui->startRecording_BTN->setEnabled(true);
        ui->playRecord_BTN->setEnabled(false);
        ui->saveRecord_BTN->setEnabled(false);
    }
    else
    {
        if(recorder->getIsRecording())
        {
            on_startRecording_BTN_clicked();
        }
        modeManager->setMode(ModeManager::REPLAY);
        ui->startRecording_BTN->setEnabled(false);
        ui->playRecord_BTN->setEnabled(true);
        ui->saveRecord_BTN->setEnabled(true);
    }
}

void MainWindow::on_recordsUpdated()
{
    QStringList recordNames = recorder->getRecordNames();

    recordListModel.clear();
    foreach(QString name, recordNames)
    {
        QStandardItem* item = new QStandardItem(name);
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        QList<QStandardItem *> row;
        row.append(item);
        recordListModel.invisibleRootItem()->appendRow(row);
    }
}

void MainWindow::on_startRecording_BTN_clicked()
{
    if(recorder->getIsRecording())
    {
        recorder->on_stopRecording();
        ui->startRecording_BTN->setText("Start\n Recording");
    }
    else
    {
        modelController->clearScene();
        recorder->on_startRecording();
        ui->startRecording_BTN->setText("Stop");
    }
}

void MainWindow::on_saveRecord_BTN_clicked()
{
    QMessageBox::information(this,"Not Implemented yet", "This function will be available soon.");
}

void MainWindow::on_playRecord_BTN_clicked()
{
    if(player->getIsPlaying())
    {
        player->stopPlaying();
        return;
    }
    QModelIndexList indeces = ui->record_ListView->selectionModel()->selectedIndexes();
    if(indeces.length() <= 0)
    {
        QMessageBox::information(this, "No Record is Selected","Please select a record first.");
        return;
    }
    player->setRecord(recorder->getRecordByName(recordListModel.itemFromIndex(indeces[0])->text()));
    player->startPlaying();
    ui->playRecord_BTN->setText("Stop");
}

void MainWindow::on_player_finished()
{
    ui->playRecord_BTN->setText("Play Record");
}


void MainWindow::on_removeRecord_BTN_clicked()
{
    QModelIndexList indeces = ui->record_ListView->selectionModel()->selectedIndexes();
    if(indeces.length() <= 0)
    {
        QMessageBox::information(this, "No Record is Selected","Please select a record first.");
        return;
    }
    QString name = recordListModel.itemFromIndex(indeces[0])->text();
    QMessageBox::StandardButton re = QMessageBox::information( this, "Confirm",
                                                               "Are you sure to remove Record: <b>" + name + "</b>",
                                                               QMessageBox::Ok, QMessageBox::Cancel);
    if(re == QMessageBox::Ok)
    {
        recorder->removeRecord(name);
    }
}
