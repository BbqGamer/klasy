#include "Polygon.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<std::vector<double> > vertices = {{2,0}, {1,1}, {0,1}, {0,0}};
    
    Polygon polygon = Polygon(vertices, 4);
        
    cout << "Number of Punkt2 instances: " << polygon.getVertices()[0].number_of_instances << endl;
    
    Polygon polygon1;
    Polygon polygon2;
    
    cout << "Number of polygon instances: " << polygon.number_of_instances << endl;
    
    Punkt2 a{1,2};
    Punkt2 b{2,3};
    Punkt2 c;
    c = a+b;
    cout << c.getX() << " " << c.getY() << endl;
    
    Punkt2 d{2,2};
    Punkt2 e{3,3};
    double f = d*e;
    cout << f << endl;
    
    
    return 0;
}
