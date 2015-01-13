#ifndef CAMERA_H
#define CAMERA_H
#include "Point.h"

class Camera
{
    private:

        Point o;
        int f;
        int res_x;
        int res_y;
        double pitch_x;
        double pitch_y;

    public:

        Camera();
        void setOrigine(int x, int y, int z);
        void setFocale(int g);
        void setRes(int x, int y);
        void setPitch(double x, double y);
        double getX();
        double getY();
        double getZ();

        inline int getF()
        {
            return f;
        }

        inline double getPitchX()
        {
            return pitch_x;
        }

        inline double getPitchY()
        {
            return pitch_y;
        }

        inline int getResX()
        {
            return res_x;
        }

        inline int getResY()
        {
            return res_y;
        }

        inline Point* getOrigine()
        {
            return &o;
        }
};

#endif // CAMERA_H
