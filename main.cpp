#include "Polygon.h"

using namespace std;

int main()
{
    
    Punkt2 p1 = Punkt2(1.0, 2.0);
    
    Punkt2 p2 = p1;
    
    Punkt2 p3 = p1 + p2;

    Punkt2 p4 = Punkt2(1000, 2000) + Punkt2(3000, 4000);

    Punkt2 p5 = std::move(Punkt2(10, 20));

    Punkt2 p6 = std::move(Punkt2(100, 200) + Punkt2(100, 200));
    
    return 0;
}
