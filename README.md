# p04-Capstone
Final Project for CSCI111

## Input/Output
[main.cpp lines 50-51](main.cpp#L50)

This example demonstrates both input and output. Line 45 outputs a request for a bitmap file for the background image.Line 46 receives the bitmap file name and stores it in a string variable fileName1 for future use.

[main.cpp line 103](/main.cpp#L103)

This example demonstrates output because there is a cout statement which updates the user with which of his files are not the correct size, and thus cannot be converted. This information is helpful to the user.

## Control Flow

### If
[main.cpp lines 74-76](/main.cpp#L74)

This was a good use of if because the do.while loop and the if statement have opposite conditions. This means if the proper input for the do.while loop, the if statement will display the error message and let the user know he needs to retry.

### Else if 

[main.cpp lines 112-114](/main.cpp#L112)

This was a practical use of the else if because in this for loop, there are three possibilities for the string holder, and thus an else if is necessary. 

### Else

[main.cpp lines 118-120](/main.cpp#L118)

This was a standard use of an else statement, where the last condition(or unimportant ones) are simply ignored and the program moves on. Since when holder = "" means there is a blank line in the input file, it should be ignored.

## Iteration

### For

[main.cpp lines 135-147](/main.cpp#L135)

I used this for loop, so I could cycle traverse the vector<string> over its length. This is useful so that I can edit each file individually and sequentially. 

### Do.while

[main.cpp lines 48-64](/main.cpp#L48)

I used a do.while loop to repeatedly ask the user for a usable bitmap file to use as the background. This is important because the rest of the program is dependent upon the backgrounds characteristics. 

## Data Structure

### Vector
[main.cpp line 95](/main.cpp#L95)

I used the vector <string> fileVector here in order to take the file names from the input file and using push_back() add them to fileVector. This allows me to edit them individually in a loop.


### Matrix 

[main.cpp lines 174-182](/main.cpp#L174)

I used a matrix here because a two dimensional vector of pixels is the return type of .toPixelMatrix() and it allows me to individually edit the images pixels based on their position and characteristics.

## Function

[main.cpp lines 153-167](/main.cpp#L153)

This function has a boolean return type because it tests whether or not the parameters are the same size which is either true or false. It is pass by value because the parameters of this function will not be edited by the function.

[main.cpp lines 170-190](/main.cpp#L170)

This function has a void return type and is pass by reference because instead of returning anything, it will edit the Bitmap parameter within the function, and thus does not need to return anything. 

[backGround.cpp lines 28-32](/backGround.cpp#L28)

This function has a Pixel return type and is pass by value. It simply returns the pixel at the position described by its parameters. This simplified the converter function significantly. 


## FileIO

[main.cpp lines 71-86](/main.cpp#L71)

I used the istream imageFile to open the inputFile and used getline to retrieve all the filenames from the file. 

[main.cpp lines 129-143](/main.cpp#L129)

I used the ostream saveFile to create a text file and then list the converted bitmaps produced in the program and then save the list to a text file.


## Class

[backGround.h lines 10-22](/backGround.h#L10)

This Background class has its own dedicated files and has both private and public members each of the functions and member variables are used. Using the Background class instead of the Bitmap class expediated the conversion process and the dimension comparison significantly. 


