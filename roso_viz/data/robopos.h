#ifndef ROBOPOS_H
#define ROBOPOS_H

class RoboPos
{
public:
    RoboPos();

    RoboPos(int side, int id, bool isKnown = false, double x = -1, double y = -1, double rad = 0);

    double x;
    double y;
    double rad;
    int side;//RED_ROBOT or BLUE_ROBOT
    int id;
    bool isKnown;
};

#endif // ROBOPOS_H
