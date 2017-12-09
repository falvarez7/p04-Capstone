//Author: Frederick Alvarez
#include<string>
#include<iostream>
#include<vector>
#include"backGround.h"
using namespace std;
//Constructor
Background::Background()
{
//The rest of the variables are purposefully left undefined.
dot.red = 0;
dot.blue = 0;
dot.green = 0;
}

//function declarations
void Background::setBitmap(std::string filename)
{
    setting.open(filename);
}


void Background::setMatrix(std::string filename)
{
    setting.open(filename);
    backgroundMatrix = setting.toPixelMatrix();

}


Pixel Background::getPixel(int row, int col)
{
    return backgroundMatrix[row][col];

}


int Background::rowSize()
{
    return backgroundMatrix.size();
}


int Background::colSize()
{
    return backgroundMatrix[0].size();
}
