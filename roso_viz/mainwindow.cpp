#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Roso_Viz", "<b>Author</b>: Tianlan Shao<br><b>Contact</b>: shaotianlan.de@gmail.com<br><br><b>Github</b>: https://github.com/shaosHumbleAccount/roso_viz<br><br>Published under MIT licence.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.");
}
