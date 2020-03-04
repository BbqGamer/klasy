#include "Punkt2.h"
#include <math.h>

int Punkt2::number_of_instances = 0;

//Constructors

Punkt2::Punkt2()
{
    x = NULL;
    y = NULL;
    number_of_instances++;
}

Punkt2::Punkt2(double X, double Y, bool kartez)
{
    
    number_of_instances++;
    
    if (kartez)
    {
        x = X;
        y = Y;
    }
    else {
        x = X/cos(y);
        y = X/sin(y);
    }
}

Punkt2::~Punkt2()
{
    number_of_instances--;
}

//Seters

void Punkt2::setX(double X)
{
    x = X;
}

void Punkt2::setY(double Y)
{
    y = Y;
}


//Geters

double Punkt2::getX()
{
    return x;
}

double Punkt2::getY()
{
    return y;
}


//Polar coordinates

double Punkt2::getRadius()
{
    return sqrt(pow(x,2)+pow(y,2));
}

double Punkt2::getAngle()
{
    return atan2(y,x);
}


//Distance

double Punkt2::getDistance( Punkt2 _p)
{
    double x2 = _p.getX();
    double y2 = _p.getY();
    return sqrt(pow(x2-x,2)+pow(y2-y,2));
}
