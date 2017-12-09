//Author: Frederick Alvarez
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include<string>
#include"bitmap.h"

using namespace std;

class Background
{
    private:
    Bitmap setting;
    vector< vector<Pixel> > backgroundMatrix;
    Pixel dot;
    public:
    //constructor
    Background();
    //Retrieves Pixel at position of parameters(row,col)
    Pixel getPixel(int,int);
    //returns the amount of columns in a Background variable
    int colSize();
    //returns the amount of rows in a Background variable
    int rowSize();
    //sets the vector< vector<Pixel> > member variable
    void setMatrix(std::string);
    //sets the Bitmap member variable 
    void setBitmap(std::string);
};

#endif
