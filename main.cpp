#include <iostream>
#include "Point.h"
#include "Objet.h"
#include "Rayon.h"
#include "Sphere.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Camera c = Camera();
    c.setRes(800,600);
    c.setFocale(300);
    Point p1 = Point(0.0,-250,50000);
    Point p2 = Point(0.0,-250,500);
    Point p3 = Point(0.0,550,1000);
    Vect3d bleu = Vect3d(0,0,255);
    Vect3d rouge = Vect3d(255,0,0);
    Vect3d vert = Vect3d(0,255,0);
    Vect3d blanc = Vect3d(255,255,255);
    Sphere* s1 = new Sphere(bleu,0.01,bleu,0.8,blanc,0.19,p1,false,0.0,15000);
    Sphere* s2 = new Sphere(rouge,0.01,rouge,0.8,blanc,0.19,p2,false,0.0,75);
    Sphere* s3 = new Sphere(vert,0.01,vert,0.8,blanc,0.19,p3,true,4,500);
    s3->afficher();
    int taille = 3;
    int n = 13;
    Objet** scene = new Objet*[taille];
    scene[0] = s1;
    scene[1] = s2;
    scene[2] = s3;
    Rayon r = Rayon();
    Point l = Point(0.0,0.0,0.0);
    Vect3d* couleur = NULL;
    std::ofstream ofs("./test.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << c.getResX() << " " << c.getResY() << "\n255\n";
    for(int i = 0; i < c.getResY(); i++)
    {
        for(int j = 0; j < c.getResX() ; j++)
        {
            r.calculerRayon(c, i, j);
            r.getDirection().normalise();
            couleur = r.calculerCouleur(c,l,scene,taille,n,0,-1);
            ofs << (unsigned char)couleur->getX()<<(unsigned char)couleur->getY()<<(unsigned char)couleur->getZ();
        }
    }
    delete s1;
    delete s2;
    delete s3;
    delete scene;
    delete couleur;
}
