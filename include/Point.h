#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>


class Point
{

    private:

        double x;
        double y;
        double z;

    public:

        inline Point()
        :
            x(0.0)
        ,   y(0.0)
        ,   z(0.0)
        {}

        inline Point(double a, double b, double c)
        :
            x(a)
        ,   y(b)
        ,   z(c)
        {}

        inline Point(const Point& p)
        :
            x(p.x)
        ,   y(p.y)
        ,   z(p.z)
        {}

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

        inline void afficher()
        {
            std::cout<<x<<" "<<y<<" "<<z<<std::endl;
        }

        inline double distance(Point& p)
        {
            return sqrt( (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z) );
        }

        bool egal(Point& p);

};

#endif // POINT_H
