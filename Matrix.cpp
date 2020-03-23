//
//  Matrix.cpp
//  Klasy
//
//  Created by Adam Korba on 23/03/2020.
//  Copyright © 2020 Adam Korba. All rights reserved.
//

#include "Matrix.h"

Matrix::Matrix(double ** Tab, int SizeX, int SizeY)
{
    tab = Tab;
    sizeX = SizeX;
    sizeY = SizeY;
}

double * Matrix::operator[](int i)
{
    return tab[i];
}

const double & Matrix::operator()(int i, int j) const
{
    return tab[i][j];
}
