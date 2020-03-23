#ifndef Matrix_h
#define Matrix_h

class Matrix
{
    
    double ** tab;
    int sizeX;
    int sizeY;
    
    public:
        
        Matrix(double ** Tab, int SizeX, int SizeY);
        
        double * operator[](int i);
        const double & operator()(int i, int j) const;
    
};

#endif
