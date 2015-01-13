#include "Camera.h"

Camera::Camera()
:
        o(Point())
    ,   f(200)
    ,   res_x(400)
    ,   res_y(400)
    ,   pitch_x(1.0)
    ,   pitch_y(1.0)
    {}

void Camera::setOrigine(int x, int y, int z)
{
    o.setX(x);
    o.setY(y);
    o.setZ(z);
}

void Camera::setFocale(int g)
{
    f = g;
}

void Camera::setRes(int x, int y)
{
    res_x = x;
    res_y = y;
}

void Camera::setPitch(double x, double y)
{
    pitch_x = x;
    pitch_y = y;
}

double Camera::getX()
{
    return o.getX();
}

double Camera::getY()
{
    return o.getY();
}

double Camera::getZ()
{
    return o.getZ();
}

