#include "rosofieldwdgt.h"
#include "ui_rosofieldwdgt.h"
#include <QGraphicsEllipseItem>
#include "util/logger.h"

RosoFieldWdgt::RosoFieldWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RosoFieldWdgt)
{
    ui->setupUi(this);

    ui->graphicsView->setSceneRect(QRectF(-300,-200,600,400));
    scene.setBackgroundBrush(Qt::gray);
    QGraphicsRectItem* borderRect =  scene.addRect(-300,-200,600,400);
    borderRect->setZValue(0);
    //QGraphicsLineItem* line1 = scene.addLine(1,1,100,100,pen);


    for(int i = 0;i < 3;i++)
    {
        red_robots[i] = new RobotGraphicItem(RED_ROBOT,i);
        scene.addItem(red_robots[i]);

        blue_robots[i] = new RobotGraphicItem(BLUE_ROBOT,i);
        scene.addItem(blue_robots[i]);

    }
    ui->graphicsView->setScene(&scene);
}

RosoFieldWdgt::~RosoFieldWdgt()
{
    delete ui;
}

void RosoFieldWdgt::on_updateScene(StateForTimestep& currentState)
{
    Logger::singleton()->printLog("on_updateScene");

    for(int i = 0;i < 3;i++)
    {
        if(currentState.blue_RobotPoses[i].isKnown)
        {
            blue_robots[i]->setVisible(true);
            blue_robots[i]->setX(currentState.blue_RobotPoses[i].x);
            blue_robots[i]->setY(currentState.blue_RobotPoses[i].y);
        }
        else
        {
            blue_robots[i]->setVisible(false);
        }

        if(currentState.red_RobotPoses[i].isKnown)
        {
            red_robots[i]->setVisible(true);
            red_robots[i]->setX(currentState.red_RobotPoses[i].x);
            red_robots[i]->setY(currentState.red_RobotPoses[i].y);
        }
        else
        {
            red_robots[i]->setVisible(false);
        }
    }
    Logger::singleton()->printLog("on_updateScene finished");
    scene.update();
    ui->graphicsView->update();
}
