#include "Punkt2.h"
#include <math.h>

int Punkt2::number_of_instances = 0;

//Constructors

Punkt2::Punkt2(): Punkt2(0,0)
{
    number_of_instances++;
    std::cout << "Uruchomiono konstruktor ()" << std::endl;
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
    std::cout << "Uruchomiono konstruktor: (" << x << ", " << y << ")" << std::endl;
}


Punkt2::Punkt2(const Punkt2 & p)
{
    number_of_instances++;
    
    x = p.getX();
    y = p.getY();
    
    std::cout << "Uruchomiono konstruktor kopiujący!" << std::endl;
}
    

Punkt2::Punkt2(Punkt2 && p)
{
    number_of_instances++;
    
    x = p.getX();
    y = p.getY();
    
    std::cout << "Uruchomiono konstruktor przenoszący!" << std::endl;
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

double Punkt2::getX() const
{
    return x;
}

double Punkt2::getY() const
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

//operators

Punkt2 Punkt2::operator+ (const Punkt2 &p) const
{
    return Punkt2(x + p.getX(), y + p.getY());
}

Punkt2 Punkt2::operator- (const Punkt2 &p) const
{
    return Punkt2(x - p.getX(), y - p.getY());
}

double Punkt2::operator* (const Punkt2 &p) const
{
    return x * p.getX() + y * p.getY();
}

Punkt2 & Punkt2::operator=(const Punkt2 &p)
{
    std::cout << "Uruchomiono kopiujący operator przypisania! (Punkt2)" << std::endl;
    
    x = p.getX();
    y = p.getX();
        
    return *this;
}

Punkt2 & Punkt2::operator= (const Punkt2 &&p)
{
    std::cout << "Uruchomiono przenoszący operator przypisania! (Punkt2)" << std::endl;

    x = p.getX();
    y = p.getY();

    return *this;
}


std::ostream& operator<< (std::ostream& os, const Punkt2& obj)
{
    os << "(" << obj.getX() << ", " << obj.getY() << ")" << std::endl;
    return os;
}
