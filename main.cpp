#include "Polygon.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<std::vector<double> > vertices = {{2,0}, {1,1}, {0,1}, {0,0}};
    
    Polygon polygon = Polygon(vertices, 4);
        
    cout << polygon;
    
    return 0;
}
