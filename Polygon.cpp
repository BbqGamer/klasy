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
#include<iostream>
#include "Polygon.h"
#include <vector>

int Polygon::number_of_instances = 0;

double absolute(double x)
{
    if (x < 0) {
        return -x;
    }
    return x;
}

Polygon::Polygon()
{
    vertices = nullptr;
    count = 0;
    number_of_instances++;
}

Polygon::Polygon(std::vector<std::vector<double> >VerticeVector, int Count)
{
    number_of_instances++;
    count = Count;
    vertices = new Punkt2[count];
    
    for(int i = 0; i < count; i++)
    {
        Punkt2 punkt;
        punkt.setX(VerticeVector[i][0]);
        punkt.setY(VerticeVector[i][1]);
        vertices[i] = punkt;
     
    }
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
    
    for(int i = 1; i < count-1; i++)
    {
        area += vertices[i].getX() * (vertices[i+1].getY()-vertices[i-1].getY());
    }
    area += vertices[0].getX() * (vertices[1].getY()-vertices[count-1].getY());
    area += vertices[count-1].getX() * (vertices[0].getY()-vertices[count-2].getY());
    
    return 0.5 * absolute(area);
}
