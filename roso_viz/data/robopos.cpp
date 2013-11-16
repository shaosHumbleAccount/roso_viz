#include "robopos.h"
#include "commonDefs.h"

RoboPos::RoboPos(int _side, int _id, bool _isKnown, double _x, double _y)
{
    x = _x;
    y = _y;
    side = _side;
    id = _id;

    isKnown = _isKnown;
}

RoboPos::RoboPos()
{
    x = -1;
    y = -1;
    side = RED_ROBOT;
    id = -1;

    isKnown = false;
}
