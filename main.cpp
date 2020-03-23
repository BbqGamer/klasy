#include "Polygon.h"
#include "Matrix.h"

using namespace std;

int main()
{
    
    
    int sizeX = 4;
    int sizeY = 7;
    double ** tab = new double*[sizeX];
    for(int i = 0; i < sizeX; i++)
    {
        tab[i] = new double[sizeY];
        for(int j = 0; j < sizeY; j++)
        {
            tab[i][j] = rand()%20;
        }
    }
    
    Matrix m(tab,sizeX,sizeY);
    double * tablica;
    tablica = m[0];
    for(int i = 0; i < sizeY; i++)
    {
        cout << tablica[i] << " ";
    }
    cout << endl;
    
    cout << m[0][0] << endl;
    cout << m[0][1] << endl;
    
    return 0;
}
