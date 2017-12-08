//Author:Fred Alvarez
#include<vector>
#include<iostream>
#include<fstream>
#include"bitmap.h"
#include"backGround.h"
#include<sstream>
using namespace std;
//function prototypes
bool sameSize(string,Background);
Bitmap converter(string,Background);
//global variables
stringstream numbHolder;
char fileName[255];
string fileName1,fileName2,holder,numb,saveName;
Pixel rgb;
Background backDrop;
Bitmap bitmap,testBitmap,convertedBitmap;
int counter;
bool test = false;
bool same = false;
ifstream imageFile;
vector <string> fileVector;

int main()
{

//**User input of background image**
    do
    {
        cout<<"Enter a background image file"<<endl;
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
        }
    }
    while(test == false);


//**User input of .txt file of image names**
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
//**Creating the string vector to hold file names**
    do
    {
        getline(imageFile,holder);
        if(holder!="")
        {
            testBitmap.open(holder);
            test = testBitmap.isImage();
            if(test == true)
            {
                if(sameSize(holder,backDrop)==true)
                {
                    //cout<<"Same size"<<endl;
                    fileVector.push_back(holder);
                    counter++;
                }
                else
                {
                    cout<<holder<<" cannot be greenscreened. Image dimensions must match"<<endl;
                }
            }
            else
            {    
            }
        }
        else
        {
        }
    }
    while(!imageFile.eof());
    cout<<"What would you like to name all of your converted images?(will have a number and .bmp appened to name)"<<endl;
    cin>>saveName;
    for(int i = 0; i<counter;i++)
    {
        numbHolder.str("");
        numbHolder<<i+1;
        numb = numbHolder.str();
        convertedBitmap = converter(fileVector[i],backDrop);
        convertedBitmap.save(saveName+numb+".bmp");

    };

 
    
    return 0;
};

//function definitions
bool sameSize(string file_Name,Background back_Ground)
{
    Bitmap functionBitmap;
    functionBitmap.open(file_Name);
    vector< vector<Pixel> > fileMatrix = functionBitmap.toPixelMatrix();
    if(fileMatrix.size()==back_Ground.rowSize()&&fileMatrix[0].size()==back_Ground.colSize())
    {
        return true;
    }
    else
    {
        return false;
    }

}


Bitmap converter(string file_Name, Background back_Ground)
{
    Bitmap functionBitmap;
    vector< vector<Pixel> > pixelMatrix;
    functionBitmap.open(file_Name);
    Pixel arbiter;
    pixelMatrix = functionBitmap.toPixelMatrix();
    for(int i = 0; i<backDrop.rowSize();i++)
    {
        for(int j=0; j<backDrop.colSize();j++)
        {
            arbiter= pixelMatrix[i][j];
            if(arbiter.red <= 50 && arbiter.blue <= 50 && arbiter.green >= 100)
            {
                pixelMatrix[i][j] = backDrop.getPixel(i,j);

            }
            else
            {
            }
        };
    };
    functionBitmap.fromPixelMatrix(pixelMatrix);
    return functionBitmap;
}

