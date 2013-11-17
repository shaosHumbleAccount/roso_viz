#include "robopos.h"
#include "commonDefs.h"

RoboPos::RoboPos(int _side, int _id, bool _isKnown, double _x, double _y, double _rad)
{
    x = _x;
    y = _y;
    rad = _rad;

    side = _side;
    id = _id;

    isKnown = _isKnown;
}

RoboPos::RoboPos()
{
    x = -1;
    y = -1;
    rad = 0;
    side = RED_ROBOT;
    id = -1;

    isKnown = false;
}
