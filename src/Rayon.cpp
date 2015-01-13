#include "Rayon.h"
#include <stddef.h>
#include <cmath>
#include <stdio.h>


Rayon::Rayon()
    :
        o(Point())
    ,   d(Vect3d())

    {}

Rayon::Rayon(const Rayon& r)
    :
        o(Point(r.o))
    ,   d(Vect3d(r.d))
    {}

Rayon::Rayon(Point& p, Vect3d& v)
    :
        o(Point(p))
    ,   d(Vect3d(v))
    {}
Rayon::Rayon(double x, double y, double z, double a, double b, double c)
    :
        o(Point(x, y, z))
    ,   d(Vect3d(a, b, c))
    {}

Rayon::Rayon(Point& p, Point& a, Point& b)
    :
        o(Point(p))
    ,   d(Vect3d(b, a))
    {}

void Rayon::calculerRayon(Camera& c, int i, int j)
{
    d.setX( (i - c.getResX() / 2) * c.getPitchX());
    d.setY( (j - c.getResY() / 2) * c.getPitchY());
    d.setZ(c.getF());
}

Vect3d* Rayon::calculerCouleur(Camera& c, Point& l, Objet** scene, int taille, int lim_p, int lim_r, int ind)
{
	lim_r++;
	double distance;
	double min_distance = inf;
	Objet* courant = NULL;
	Point* inter = NULL;
	Point* temp = NULL;
	Vect3d* couleur = NULL;
	int indice = 0;

	for(int k = 0; k < taille ; k++)
	{
		if( k != ind)
		{
			temp = scene[k]->intersection(o, d, true);
			if(temp->getX() < inf)
			{
				distance = temp->distance(*(c.getOrigine()));
				if( distance < min_distance)
				{
					inter = new Point(*temp);
					courant = scene[k];
					min_distance = distance;
					indice = k;
				}
			}
			delete temp;
		}
	}

	if( min_distance < inf && courant != NULL && temp != NULL)
	{
		Rayon lumiere = Rayon(*inter, l, *inter);
		Vect3d* normal = courant->normale(*inter);
		normal->normalise();
		lumiere.getDirection().normalise();
		Vect3d vr = Vect3d(o, *(courant->getOrigine()));
		Rayon obj = Rayon(o, vr);
		obj.d.normalise();

		if(obj.getDirection().produit_scalaire(*normal) < 0)
		{
			double att_diff = normal->produit_scalaire(lumiere.getDirection());
			if(att_diff < 0)
			{
				att_diff = 0;
			}
			double ca = courant->getCoefAmbiante();
			double cs = courant->getCoefSpeculaire();
			double cd = courant->getCoefDiffuse();
			double scalaire_ds = 2 * normal->produit_scalaire(lumiere.getDirection());
			double x_r = -l.getX() + normal->getX() * scalaire_ds;
			double y_r = -l.getY() + normal->getY() * scalaire_ds;
			double z_r = -l.getZ() + normal->getZ() * scalaire_ds;

			Vect3d r_temp = Vect3d(x_r, y_r, z_r);
			Rayon reflechi(*inter, r_temp);
			reflechi.getDirection().normalise();
			scalaire_ds = pow(reflechi.getDirection().produit_scalaire(d), lim_p);
			if(scalaire_ds < 0)
			{
				scalaire_ds = std::abs(scalaire_ds);
			}
			int r = courant->getAmbiante().getX() * ca + courant->getDiffuse().getX() * cd * att_diff + scalaire_ds * cs * courant->getSpeculaire().getX();
			int v = courant->getAmbiante().getY() * ca + courant->getDiffuse().getY() * cd * att_diff + scalaire_ds * cs * courant->getSpeculaire().getY();
			int b = courant->getAmbiante().getZ() * ca + courant->getDiffuse().getZ() * cd * att_diff + scalaire_ds * cs * courant->getSpeculaire().getZ();
			couleur = new Vect3d((double) r, (double)v, (double)b);
			couleur->verificationCouleur();
			if(lim_r <= 5)
			{
				if(courant->getOpacite())
				{
					double n_objet = 1 /courant->getCoefOpacite();
					double coso = d.produit_scalaire(*normal);
					double sin2o = n_objet * n_objet * (1 - coso);
					double x_t = n_objet * d.getX();
					double y_t = n_objet * d.getY();
					double z_t = n_objet * d.getZ();
					double coef_ = n_objet * coso + sqrt(1 - sin2o);
					x_t -= coef_ * normal->getX();
					y_t -= coef_ * normal->getY();
					z_t -= coef_ * normal->getZ();
					delete normal;
					Vect3d dir = Vect3d(x_t, y_t, z_t);
					Point* inter_t = courant->intersection(*inter, dir, false);
					delete inter;
					Rayon refract = Rayon(*inter_t, d);
					refract.d.normalise();
					if( ind == -1)
					{
						couleur = somme(couleur, refract.calculerCouleur(c,l,scene,taille,lim_p,lim_r,indice));
					}
					else
					{
						couleur = somme(couleur, refract.calculerCouleur(c,l,scene,taille,lim_p,lim_r,ind));
					}
				}
				else
				{
				    delete normal;
				    delete inter;
					if( ind == -1)
					{
						couleur = somme(couleur, reflechi.calculerCouleur(c,l,scene,taille,lim_p,lim_r,indice));
					}
					else
					{
						couleur = somme(couleur, reflechi.calculerCouleur(c,l,scene,taille,lim_p,lim_r,ind));
					}
				}
			}
		}
		else
		{
		    delete normal;
		    delete inter;
			couleur = new Vect3d(0,0,0);
		}
	}
	else
	{
		couleur = new Vect3d(0,0,0);
	}
	return couleur;
}

