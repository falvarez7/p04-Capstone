//Author:Fred Alvarez
#include<vector>
#include<iostream>
#include<fstream>
#include"bitmap.h"
#include"backGround.h"

using namespace std;

string fileName1,fileName2;
Pixel rgb, arbiter;
Background backDrop;
Bitmap bitmap;
vector< vector<Pixel> > pixelMatrix;
int r,c;
int main()
{
    cout<<"Enter a background file and then a greenscreen file."<<endl;
    cin>>fileName1;
    cin>>fileName2;
    backDrop.setBitmap(fileName1);
    bitmap.open(fileName2);
    cout<<fileName1<<" has been loaded"<<endl;
    backDrop.setMatrix(fileName1);
    //needs a check to see if they are the same size.
    cout<<fileName1<< " is "<<backDrop.colSize()<<" by "<<backDrop.rowSize()<<endl;
    pixelMatrix = bitmap.toPixelMatrix();
    for(int i = 0; i<backDrop.rowSize();i++)
    {
        for(int j=0; j<backDrop.colSize();j++)
        {
            arbiter= pixelMatrix[i][j];
            if(arbiter.red <= 20 && arbiter.blue <= 20 && arbiter.green >= 80)
            {
                pixelMatrix[i][j] = backDrop.getPixel(i,j);

            }
            else
            {
            }
        };
    };
    bitmap.fromPixelMatrix(pixelMatrix);
    bitmap.save("TestOutput.bmp");
    return 0;
};


//Simple Decomp
//Class::
/*-Background:
    -for background image access and characteristics 
    */

//Initialization
/*
1.)Ask for background image. Check that it is and image. Then use background image for setting dimensions of following images.
    -use do while, since isImage returns booleon
2.)Ask for .txt file with list of bitmap files you wish to be greenscreened. Using a vector, record the file names for use in a later for loop.
    -decide whether or not to check the dimensions and Image types before or during conversion
*/
//Conversion
/*
1.)Use string vector of filenames in a for loop to access each one individually
2.While cycling, use two more for loops to traverse the pixel matrix of the current vector.
    -for each pixel with characteristics (EX:blue<20,red<20,green>100)(if else statements) use .getPixel(position,position) to replace that green pixel with the background pixel.
*/

//Saving

/*
need to decide whether or not to ask for names sequentially or give them a generic name. Create a new file??  
*/
