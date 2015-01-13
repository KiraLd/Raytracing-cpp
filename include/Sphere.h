#ifndef SPHERE_H
#define SPHERE_H
#include "Objet.h"
#define inf 2147483647

class Sphere: public Objet
{
    private:

        double r;

    public:
        Sphere();
        Sphere(Vect3d& c, double coef, Vect3d& d, double cd, Vect3d& s, double cs, Point& p, bool op, double co, double r);

        inline double getRayon()
        {
            return r;
        }

        Point* intersection(Point& o, Vect3d& d, bool b);
        Vect3d* normale(Point& p);
        void afficher();


};

#endif // SPHERE_H
