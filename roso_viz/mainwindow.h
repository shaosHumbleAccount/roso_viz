#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "controller/fieldmodelcontroller.h"
#include "udpserver.h"
#include "player/modemanager.h"
#include "player/recorder.h"
#include "player/recordplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionClear_triggered();

    void on_actionRotate_Clockwise_triggered();


    void on_actionAbout_Qt_triggered();

    void on_actionAbout_triggered();


    void on_liveMode_radioButton_toggled(bool checked);

    void on_recordsUpdated();
    void on_startRecording_BTN_clicked();

    void on_saveRecord_BTN_clicked();

    void on_playRecord_BTN_clicked();

    void on_player_finished();

    void on_removeRecord_BTN_clicked();

private:
    Ui::MainWindow *ui;

    FieldModelController* modelController;
    ModeManager* modeManager;
    Recorder* recorder;
    UdpServer* udpServer;
    RecordPlayer* player;
    QStandardItemModel recordListModel;
};

#endif // MAINWINDOW_H
