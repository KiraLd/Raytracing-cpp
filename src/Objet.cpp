#include "Objet.h"
#include <stddef.h>
#include <iostream>

Objet::Objet()
    :
        ca(Vect3d())
    ,   cca(0.0)
    ,   cd(Vect3d())
    ,   ccd(0.0)
    ,   cs(Vect3d())
    ,   ccs(0.0)
    ,   p(Point())
    , opacite(false)
    , co(0.0)
    {}


Objet::~Objet()
{

}

Objet::Objet(Vect3d& c, double coef, Vect3d& d, double c_d, Vect3d& s, double c_s, Point& p_, bool o, double coefo)
    :
        ca(Vect3d(c))
    ,   cca(coef)
    ,   cd(Vect3d(d))
    ,   ccd(c_d)
    ,   cs(Vect3d(s))
    ,   ccs(c_s)
    ,   p(Point(p_))
    ,   opacite(o)
    ,   co(coefo)
    {}

void Objet::afficher()
{
    std::cout<<"Objet"<<std::endl;
}


