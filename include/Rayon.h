#ifndef RAYON_H
#define RAYON_H
#include "Vect3d.h"
#include "Camera.h"
#include "Objet.h"
#include "Sphere.h"
#define inf 2147483647

class Rayon
{

    private:

        Point o;
        Vect3d d;

    public:

        Rayon();
        Rayon(const Rayon& r);
        Rayon(Point& p, Vect3d& v);
        Rayon(double x, double y, double z, double a, double b, double c);
        Rayon(Point& o, Point& a, Point& b);

        inline Point& getOrigine()
        {
            return o;
        }

        inline Vect3d& getDirection()
        {
            return d;
        }

        void calculerRayon(Camera& c, int i, int j);

        Vect3d* calculerCouleur(Camera& c, Point& l, Objet** scene, int n, int ns, int limite, int o);

};

#endif // RAYON_H
