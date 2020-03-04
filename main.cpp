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
    
    return 0;
}
