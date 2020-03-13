#include "Polygon.h"

using namespace std;

int main()
{
    std::vector<std::vector<double> > vertices = {{2,0}, {0,2}, {2,2}, {0,0}};
    
    
    Polygon polygon = Polygon(vertices, 4);

    cout << polygon;
    cout << polygon.getConvexArea() << endl; 
    cout << polygon.getArea();
    
    return 0;
}
