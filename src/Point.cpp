#include "Point.h"

bool Point::egal(Point& p)
{
    double e = 0.00001;
    return fabs(p.x - x) < e && fabs(p.y - y) < e && fabs(p.z - z) < e;
}



