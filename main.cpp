//Author:Fred Alvarez
#include<vector>
#include<iostream>
#include<fstream>
#include"bitmap.h"
#include"backGround.h"
#include<sstream>
using namespace std;

stringstream numbHolder;
char fileName[255];
string fileName1,fileName2,holder;
Pixel rgb, arbiter;
Background backDrop;
Bitmap bitmap,testBitmap;
vector< vector<Pixel> > pixelMatrix;

int r,c,counter;
bool test = false;
ifstream imageFile;
vector <string> fileVector;
string numb;

int main()
{
//**User input of file names**
do
{
    cout<<"Enter a background image file"<<endl;
    //check if fileName1 is a working bitmap file;
    cin>>fileName1;
    testBitmap.open(fileName1);
    test = testBitmap.isImage();
    if(test == true)
    {
        backDrop.setBitmap(fileName1);
        backDrop.setMatrix(fileName1);
        cout<<fileName1<<" is "<<backDrop.colSize()<<" by "<<backDrop.rowSize()<<endl;
    }
    else
    {
        cout<<"Error: You've entered an invalid file name...Try Again!"<<endl;
    }
}
while(test == false);
do
{
    cout<<"Enter a .txt file of chroma key bitmap images you wish to convert"<<endl;
    cin>>fileName;
    imageFile.open(fileName);
    test = imageFile.is_open();
    if (test == false)
    {
        cout<<"Error: You've entered an invalid .txt file. Try again!"<<endl;
    };
}
while(test == false);
    cout<<"The file "<<fileName<<" has been successfully loaded."<<endl;
do
{
    getline(imageFile,holder);
    if(holder!="")
        {
            fileVector.push_back(holder);
            counter++;
        }
    else
    {
        cout<<"A blank line which could have compromised this whole program has been avoided. Good job me!"<<endl;
    }
}
    while(!imageFile.eof());
    for(int i = 0; i<counter;i++)
    {
        cout<<i<<" file "<<fileVector[i]<<endl;
    };

/*  
    bitmap.open(fileName2);
    //needs a check to see if they are the same size.
    cout<<fileName1<< " is "<<backDrop.colSize()<<" by "<<backDrop.rowSize()<<endl;
    pixelMatrix = bitmap.toPixelMatrix();
    for(int i = 0; i<backDrop.rowSize();i++)
    {
        for(int j=0; j<backDrop.colSize();j++)
        {
            arbiter= pixelMatrix[i][j];
            if(arbiter.red <= 100 && arbiter.blue <= 100 && arbiter.green >= 80)
            {
                pixelMatrix[i][j] = backDrop.getPixel(i,j);

            }
            else
            {
            }
        };
    };
    bitmap.fromPixelMatrix(pixelMatrix);


    bitmap.save("TestOutput.bmp");*/


    return 0;
};
/*
for (int n=1;n<10;n++)
    {
    numbHolder.str("");
    numbHolder << n;
    numb = numbHolder.str();
    fileVector.push_back( "outputfile"+numb+".bmp");
    cout<<fileVector[n-1]<<endl;
    numbHolder.flush();
    };
*/


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
