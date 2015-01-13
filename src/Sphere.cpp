#include "Sphere.h"
#include <cmath>
#include <iostream>

Sphere::Sphere()
    :
        Objet()
    ,   r(1.0)
    {}

Sphere::Sphere(Vect3d& c, double coef, Vect3d& d, double cd_, Vect3d& s, double cs_, Point& p_, bool op, double co_, double r_)
    :
        Objet(c,coef,d,cd_,s,cs_,p_,op,co_)
    ,   r(r_)
    {}

Point* Sphere::intersection(Point& o, Vect3d& d, bool b)
{
    double dx = d.getX();
    double dy = d.getY();
    double dz = d.getZ();
    double ox = o.getX();
    double oy = o.getY();
    double oz = o.getZ();
    Vect3d oc = Vect3d(o,*(getOrigine()));
    double scalaire = oc.produit_scalaire(d);
    double rx, ry, rz;
    if(scalaire < 0)
    {
        rx = ry = rz = inf;
    }
    else
    {
        double ch = oc.module() * oc.module() - scalaire * scalaire;
        if( ch > r * r)
        {
            rx = ry = rz = inf;
        }
        else
        {
            double d2 = r * r - ch;
            double t1 = scalaire + sqrt(d2);
            double t2 = scalaire - sqrt(d2);
            if(!b)
            {
                rx = t1 * dx + ox;
                ry = t1 * dy + oy;
                rz = t1 * dz + oz;
            }
            else
            {
                rx = t2 * dx + ox;
                ry = t2 * dy + oy;
                rz = t2 * dz + oz;
            }
        }
    }
    return new Point(rx, ry, rz);
}

Vect3d* Sphere::normale(Point& p_)
{
    return new Vect3d(*getOrigine(),p_);
}

void Sphere::afficher()
{
    std::cout<<"Sphere:"<<std::endl;
    getOrigine()->afficher();
    std::cout<<"ca "<<getCoefAmbiante()<<" cd "<<getCoefDiffuse()<<" cs "<<getCoefSpeculaire()<<std::endl;
}

