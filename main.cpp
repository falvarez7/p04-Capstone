//Author:Fred Alvarez
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
