/* \file Polygon.cpp
 *
 * \brief Zawiera definicję klasy Polygon
 *
 * Plik zawiera implementację metod klasy Punkt2
 *
 * \autor Adam Korba
 * \date 2020.02.26
 *
 */
#include "Polygon.h"

int Polygon::number_of_instances = 0;

double absolute(double x)
{
    if (x < 0) {
        return -x;
    }
    return x;
}

Polygon::Polygon(): vertices{nullptr}, count{0}
{
    number_of_instances++;
}

Polygon::Polygon(std::vector<std::vector<double> >VerticeVector, unsigned int Count): count{Count}
{
    number_of_instances++;
    vertices = new Punkt2[count];
    
    for(int i = 0; i < count; i++)
    {
        Punkt2 punkt;
        punkt.setX(VerticeVector[i][0]);
        punkt.setY(VerticeVector[i][1]);
        vertices[i] = punkt;
    }
}

Polygon::Polygon(const Polygon &polygon)
{
    vertices = new Punkt2[polygon.count];
    count = polygon.count;
    for(int i = 0; i < polygon.count; i++)
    {
        vertices[i] = polygon.vertices[i];
    }
    number_of_instances++;
}

Polygon::Polygon(std::initializer_list<Punkt2> punkty)
{
    count = (int)punkty.size();
    vertices = new Punkt2[count];
    int i = 0;
    for(auto p : punkty) {vertices[i++] = p;}
}

Polygon::~Polygon()
{
    number_of_instances--;
    if(vertices!=nullptr) {
        delete[] vertices;
    }
}

void Polygon::setVertices (Punkt2 * _vertices, int _count)
{
    vertices = _vertices;
    count = _count;
}

 void Polygon::changeVertex (int i, double x, double y)
{
    vertices[i].setX(x);
    vertices[i].setY(y);
}

void Polygon::setCount(int n)
{
    count = n;
}

double Polygon::getPerimeter()
{
    double ob = 0;
    
    for(int i = 0; i < count - 1; i++)
    {
        ob += vertices[i].getDistance(vertices[i+1]);
    }
    ob += vertices[count-1].getDistance(vertices[0]);
    
    return ob;
}

Punkt2 * Polygon::getVertices()
{
    return vertices;
}

double Polygon::getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3)
{

    return 0.5 * absolute(
                          (p2.getX() - p1.getX())*
                          (p3.getY() - p1.getY())-
                          (p2.getY() - p1.getY())*
                          (p3.getX() - p1.getX())
                          );
}

double Polygon::getConvexArea()
{
    double area = 0;
    
    for (int i = 0; i < count-2; i++)
    {
        area += getTriangleArea(vertices[0], vertices[i+1], vertices[i+2]);
    }
    
    return area;
}

double Polygon::getArea()
{
    double area = 0;
    
    for(int i = 0; i < count-1; i++)
    {
        area += vertices[i].getX() * vertices[i+1].getY();
        area -= vertices[i].getY() * vertices[i+1].getX();
    }
    area += vertices[count-1].getX() * vertices[0].getY();
    area -= vertices[count-1].getY() * vertices[0].getX();
    
    return 0.5 * absolute(area);
}


Polygon & Polygon::operator=(const Polygon &polygon)
{
    if(&polygon != this)
    {
        delete[] vertices;
        vertices = new Punkt2[polygon.count];
        count = polygon.count;
        for(int i = 0; i < count; i++)
        {
            vertices[i] = polygon.vertices[i];
        }
    }
    return *this;
}

Punkt2 & Polygon::operator[](int i)
{
    return vertices[i];
}


std::ostream& operator<<(std::ostream& os, const Polygon& obj)
{
    for(int i = 0; i < obj.count; i++)
    {
        os << i << ": " << obj.vertices[i];
    }
    return os;
}
