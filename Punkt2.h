#include <iostream>

class Punkt2
{

        double x;
        double y;
    
    public:
        
        friend std::ostream& operator<< (std::ostream& os, const Punkt2& obj);
    
        static int number_of_instances;
    
        Punkt2();
        Punkt2(double X, double Y, bool kartez = 1);
        ~Punkt2();

        //settery
        void setX(double _x);
        void setY(double _y);
        
        //gettery
        double getX() const;
        double getY() const;

        //współrzędne biegunowe
        double getRadius();
        double getAngle();
        
        //odległość punktu od punktu _p
        double getDistance( Punkt2 _p);
    
        //operators
        Punkt2 operator+ (const Punkt2 &p) const;
        Punkt2 operator- (const Punkt2 &p) const;
        double operator* (const Punkt2 &p) const;
    
};

std::ostream& operator<< (std::ostream& os, const Punkt2& obj);
