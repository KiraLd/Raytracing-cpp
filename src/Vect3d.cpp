#include "Vect3d.h"
#include <stddef.h>



Vect3d::Vect3d()
    :
        x(0.0)
    ,   y(0.0)
    ,   z(0.0)
    {}

Vect3d::Vect3d(const Vect3d& v)
    :
        x(v.x)
    ,   y(v.y)
    ,   z(v.z)
    {}

Vect3d::Vect3d(double a, double b, double c)
    :
        x(a)
    ,   y(b)
    ,   z(c)
    {}

Vect3d::Vect3d(Point& a, Point& b)
    :
        x(b.getX() - a.getX())
    ,   y(b.getY() - a.getY())
    ,   z(b.getZ() - a.getZ())
    {}


void Vect3d::normalise()
{
    double m = module();
    if(m != 0.0)
    {
        x = x / m;
        y = y / m;
        z = z / m;
    }

}

void Vect3d::verificationCouleur()
{
    if(x>255)
    {
        x = 255;
    }
    if(x < 0)
    {
        x = (int)-x %255;
    }
    if(y>255)
    {
        y = 255;
    }
    if(y < 0)
    {
        y = (int)-y %255;
    }
    if(z>255)
    {
        z = 255;
    }
    if(z < 0)
    {
        z = (int)-z %255;
    }
}

Vect3d* somme(Vect3d* a, Vect3d* b)
{
    if(a != NULL)
    {
        if(b != NULL)
        {
            Vect3d* c = new Vect3d(a->x + b->x, a->y + b->y, a->z + b->z);
            return c;
        }
        return a;
    }
    return NULL;

}
