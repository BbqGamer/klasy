#include "Punkt2.h"
#include <iostream>

class Polygon
{
        unsigned int count; /* Ilość wierzchołków */
    
        Punkt2 * vertices; /* Tablica wierzchołków */
    
    public:
    
        static int number_of_instances;

        Polygon();
        Polygon(std::vector< std::vector<double> >, int Count);
        ~Polygon();
    
        void setVertices (Punkt2 * _vertices, int _count);
        
        void changeVertex (int i, double x, double y);
    
        void setCount(int n);
    
        double getPerimeter(); /* oblicza obwód */
    
        double getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3); /* oblicza pole trójkąta */
    
        double getConvexArea(); /* oblicza pole powierzchni każdego wielokąta wypukłego */
    
        double getArea(); /* oblicza pole powierzchni dowolnego wielokąta */
    
        Punkt2 * getVertices(); /* pobiera tablicę wierzchołków */
    
};
