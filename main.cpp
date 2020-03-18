#include "Polygon.h"

using namespace std;

int main()
{
    
    Polygon polygon = {{2,0},{0,2},{2,2},{0,0}};
    
    Polygon polygon2;
    polygon2 = polygon;
    polygon.changeVertex(1, 2, 34);
    
    cout << polygon;
    cout << polygon2;
    polygon2[2] = Punkt2{4,5};
    cout << polygon2;
    
    return 0;
}
