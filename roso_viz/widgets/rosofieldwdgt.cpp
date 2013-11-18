#include "rosofieldwdgt.h"
#include "ui_rosofieldwdgt.h"
#include <QGraphicsEllipseItem>
#include "util/logger.h"

RosoFieldWdgt::RosoFieldWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RosoFieldWdgt)
{
    rotateDeg = 0;
    ui->setupUi(this);
    scene.setSceneRect(QRectF(-450,-450,900,900));
    ui->graphicsView->setSceneRect(QRectF(-450,-450,900,900));
    //QGraphicsLineItem* line1 = scene.addLine(1,1,100,100,pen);

    fieldItem = new FieldGraphicItem();
    fieldItem->setZValue(0);
    scene.addItem(fieldItem);

    ball = new BallGraphicItem();
    scene.addItem(ball);

    for(int i = 0;i < 3;i++)
    {
        red_robots[i] = new RobotGraphicItem(RED_ROBOT,i);
        scene.addItem(red_robots[i]);

        blue_robots[i] = new RobotGraphicItem(BLUE_ROBOT,i);
        scene.addItem(blue_robots[i]);

        red_targets[i] = new robotTargetGraphicItem(RED_ROBOT,i);
        scene.addItem(red_targets[i]);

        blue_targets[i] = new robotTargetGraphicItem(BLUE_ROBOT,i);
        scene.addItem(blue_targets[i]);

    }
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
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
            QPointF posOnScene = mapPosFromRosoToScene(
                        currentState.blue_RobotPoses[i].x,
                        currentState.blue_RobotPoses[i].y);

            blue_robots[i]->setX(posOnScene.x());
            blue_robots[i]->setY(posOnScene.y());
            blue_robots[i]->setRotation(mapRotFromRosoToScene(currentState.blue_RobotPoses[i].rad));
        }
        else
        {
            blue_robots[i]->setVisible(false);
        }

        if(currentState.red_RobotPoses[i].isKnown)
        {
            red_robots[i]->setVisible(true);
            QPointF posOnScene = mapPosFromRosoToScene(
                        currentState.red_RobotPoses[i].x,
                        currentState.red_RobotPoses[i].y);
            red_robots[i]->setX(posOnScene.x());
            red_robots[i]->setY(posOnScene.y());
            red_robots[i]->setRotation(mapRotFromRosoToScene(currentState.red_RobotPoses[i].rad));
        }
        else
        {
            red_robots[i]->setVisible(false);
        }

        if(currentState.red_robotTargets[i].isKnown)
        {
            red_targets[i]->setVisible(true);
            QPointF posOnScene = mapPosFromRosoToScene(
                        currentState.red_robotTargets[i].x,
                        currentState.red_robotTargets[i].y);
            red_targets[i]->setX(posOnScene.x());
            red_targets[i]->setY(posOnScene.y());
        }
        else
        {
            red_targets[i]->setVisible(false);
        }

        if(currentState.blue_robotTargets[i].isKnown)
        {
            blue_targets[i]->setVisible(true);
            QPointF posOnScene = mapPosFromRosoToScene(
                        currentState.blue_robotTargets[i].x,
                        currentState.blue_robotTargets[i].y);
            blue_targets[i]->setX(posOnScene.x());
            blue_targets[i]->setY(posOnScene.y());
        }
        else
        {
            blue_targets[i]->setVisible(false);
        }
    }


    ball->setPos(mapPosFromRosoToScene(currentState.ballPos));
    Logger::singleton()->printLog(QString("draw BallPos: x = %1, y = %2")
                                  .arg(ball->x())
                                  .arg(ball->y()));

    Logger::singleton()->printLog("on_updateScene finished");
    scene.update();
    ui->graphicsView->update();
}

QPointF RosoFieldWdgt::mapPosFromRosoToScene(double x, double y) const
{
    return mapPosFromRosoToScene(QPointF(x,y));
}

QPointF RosoFieldWdgt::mapPosFromRosoToScene(const QPointF& pos) const
{
    QPointF result;
    result.setX( - pos.y()*1000.0/SCENE_SCALE);
    result.setY( pos.x()*1000.0/SCENE_SCALE);

    return result;
}

double RosoFieldWdgt::mapRotFromRosoToScene(double rad) const
{
    return (rad/3.1416*180) + 180;
}

void RosoFieldWdgt::rotateScene(double deg)
{
    ui->graphicsView->rotate(deg);
}
