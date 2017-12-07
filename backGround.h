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
    Background();//constructor
    Pixel getPixel(int,int);
    int colSize();
    int rowSize();
    void setMatrix(std::string);
    void setBitmap(std::string);
};

#endif
