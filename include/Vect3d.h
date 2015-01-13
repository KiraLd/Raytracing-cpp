#ifndef VECT3D_H
#define VECT3D_H
#include "Point.h"
#include <cmath>
#include <iostream>

class Vect3d
{

private:
    double x;
    double y;
    double z;
public:
    Vect3d();
    Vect3d(const Vect3d& v);
    Vect3d(double x, double y, double z);
    Vect3d(Point& a, Point& b);

    inline double getX()
    {
        return x;
    }

    inline double getY()
    {
        return y;
    }

    inline double getZ()
    {
        return z;
    }

    inline void setX(double a)
    {
        x = a;
    }
    inline void setY(double b)
    {
        y = b;
    }

    inline void setZ(double c)
    {
        z = c;
    }

    inline double produit_scalaire(Vect3d& v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline double module()
    {
        return sqrt(x * x + y * y + z * z);
    }

    void normalise();

    inline void afficher()
    {
        std::cout<<x<<" "<<y<<" "<<z<<std::endl;
    }

    friend Vect3d* somme(Vect3d* a, Vect3d* b);
    void verificationCouleur();
};

#endif // VECT3D_H
