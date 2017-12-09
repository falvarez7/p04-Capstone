//Author:Fred Alvarez
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

//Header files
#include"bitmap.h"
#include"backGround.h"


using namespace std;


//function prototypes
bool sameSize(string,Background);
void converter(Bitmap &,Background);


//variables
char fileName[255];
char textFileName[255];
int counter;
bool test = false;
vector <string> fileVector;
string fileName1,fileName2,holder,numb,saveName;

//Created class variables
Background backDrop;
Bitmap bitmap,testBitmap,convertedBitmap;

//Stream variables
ifstream imageFile;
ofstream saveFile;
stringstream numbHolder;


//main function
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
    cout<<"Checking "<<fileName<<"'s bitmap files for errors."<<endl;
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
                    cout<<"Error: "<<holder<<"'s dimensions do not match"<<endl;
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
    imageFile.close();


//Requesting and recieving file names for .txt file and converted bitmaps;
    cout<<"What would you like your .txt file to be named?(Include .txt)"<<endl;
    cin>>textFileName;
    cout<<"What would you like to name all of your converted images?(will have a number and .bmp appened to name)"<<endl;
    cin>>saveName;

    saveFile.open(textFileName);

//Converting images and saving. 
    for(int i = 0; i<counter;i++)
    {
        cout<<"Working..."<<endl;
        bitmap.open(fileVector[i]);
        //sstream use for variable file names
        numbHolder.str("");
        numbHolder<<i+1;
        numb = numbHolder.str();
        converter(bitmap,backDrop);
        bitmap.save(saveName+numb+".bmp");
        saveFile<<saveName<<numb<<".bmp"<<endl;
        cout<<saveName<<numb<<".bmp has been converted and saved successfully to "<<textFileName<<"."<<endl;
    };

    saveFile.close();

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


void converter(Bitmap & functionBitmap, Background back_Ground)
{
    vector< vector<Pixel> > pixelMatrix;
    Pixel arbiter;
    pixelMatrix = functionBitmap.toPixelMatrix();
    for(int i = 0; i<backDrop.rowSize();i++)
    {
        for(int j=0; j<backDrop.colSize();j++)
        {
            arbiter= pixelMatrix[i][j];
            if(arbiter.red <= 130 && arbiter.blue <= 130 && arbiter.green >= 100)
            {
                pixelMatrix[i][j] = backDrop.getPixel(i,j);

            }
            else
            {
            }
        };
    };
    functionBitmap.fromPixelMatrix(pixelMatrix);
}

