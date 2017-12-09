//Author:Fred Alvarez


/*Brief Description: This file will accept  two inputs, a bitmap image which will serve as the backdrop, and a text file, which has a list of images to add the backdrop too.
It will eliminate any bitmap files from the text file which do not match the necessary requirements(isImage and same dimensions) before processing.
Once all the images are processed, you will be asked for two file names. One is for a text file which containss the names of all the converted bitmap files made. Two is for the processed bitmap names, which will be appended with a number.
*/

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
bool test = false;
vector <string> fileVector;
string fileName1,holder,numb,saveName;

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
        cout<<"Enter a background bitmap image."<<endl;
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
        cout<<"Enter a text file with a list of greenscreen images."<<endl;
        cin>>fileName;
        imageFile.open(fileName);
        test = imageFile.is_open();
        if (test == false)
        {
            cout<<"Error: You've entered an invalid text file. Try again!"<<endl;
        };
    }   
    while(test == false);
    cout<<fileName<<" has been successfully loaded."<<endl;


//**Creating the string vector to hold file names**
    cout<<"Checking "<<fileName<<"'s bitmap files for errors."<<endl;
    do
    {
        getline(imageFile,holder);
        if(holder!="" && holder!=fileName1)
        {
            testBitmap.open(holder);
            test = testBitmap.isImage();
            if(test == true)
            {
                if(sameSize(holder,backDrop)==true)
                {
                    cout<<holder<<" has passed all tests."<<endl;
                    fileVector.push_back(holder);
                }

                else
                {
                    cout<<holder<<" could be opened, but its dimensions do not match "<<fileName<<endl<<"It will not be converted."<<endl;
                }
            }
            
            else
            {    
                cout<<"It will not be converted."<<endl;
            }
        }
        else if(holder!="" && holder == fileName1) 
        {
            cout<<holder<<" is the same file as the background image."<<endl<<"It will not be converted."<<endl;

        }
        //skipping blank lines
        else
        {
        }
    }
    while(!imageFile.eof());
    imageFile.close();


//Requesting and recieving file names for .txt file and converted bitmaps;
    cout<<"What would you like your list text file to be named?"<<endl;
    cin>>textFileName;
    cout<<"What would you like to name the converted images?(Without.txt)"<<endl;
    cin>>saveName;
    saveFile.open(textFileName);


//Converting images and saving. 
    for(int i = 0; i<fileVector.size();i++)
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
/*sameSize takes a string(bitmap file name), and a Background variable and compares the pixel matrices to see if they're the same size or not and returns a boolean value */
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

/*Converter recieves a Bitmap and a Background and uses the .getPixel Background function to edit the Bitmap image.  */
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

