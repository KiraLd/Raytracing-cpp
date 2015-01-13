#ifndef OBJET_H
#define OBJET_H
#include "Vect3d.h"

class Objet
{

    private:

        Vect3d ca;
        double cca;
        Vect3d cd;
        double ccd;
        Vect3d cs;
        double ccs;
        Point p;
        bool opacite;
        double co;

    public:

        Objet();
        Objet(Vect3d& c, double coef, Vect3d& d, double cd, Vect3d& s, double cs, Point& p, bool o, double coefo);
        virtual ~Objet();

        inline Vect3d& getAmbiante()
        {
            return ca;
        }

        inline Vect3d& getDiffuse()
        {
            return cd;
        }

        inline Vect3d& getSpeculaire()
        {
            return cs;
        }

        inline double getCoefAmbiante()
        {
            return cca;
        }

        inline double getCoefDiffuse()
        {
            return ccd;
        }

        inline double getCoefSpeculaire()
        {
            return ccs;
        }

        inline Point* getOrigine()
        {
            return &p;
        }

        inline bool getOpacite()
        {
            return opacite;
        }

        inline double getCoefOpacite()
        {
            return co;
        }

        virtual Point* intersection(Point& o, Vect3d& d, bool b) = 0;
        virtual Vect3d* normale(Point& p) = 0;
        virtual void afficher();

};


#endif // OBJET_H
