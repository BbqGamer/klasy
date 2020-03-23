#include "Polygon.h"

using namespace std;

int main()
{
    
    Polygon p = {{1,2},{3,4},{5,6}};
    Polygon p1 = std::move(p);
    
    return 0;
}
