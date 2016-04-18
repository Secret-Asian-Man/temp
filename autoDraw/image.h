#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include "EasyBMP.h"

enum ERRORS{FILE_NOT_FOUND};


using std::string;

class image
{
public:

    //Constructors
    image();
    image(string newImageName);


    //Destructor
    ~image();


    //Accessors
    string getImageName();
    unsigned int getImageWidth();
    unsigned int getImageHeight();
    string getBitmap();
    string getImageName()const;
    unsigned int getImageWidth()const;
    unsigned int getImageHeight()const;
    string getBitmap()const;

    //Mutators
    void setImageName(string newImageName);
    void setImageWidth(unsigned int newImageWidth);
    void setImageHeight(unsigned int newImageHeight);
    void setBitmap(string newBitmap);

    //Operators

    //Functions
    void print();
    void saveToFile();
    void drawImage();

    //Public Member Variables
    string bitmap;

private:

    //Private Member Variables
    // std::vector<std::pair<unsigned int, unsigned int>> coords;
    string imageName;
    int imageWidth;
    int imageHeight;
    BMP bmpImage;

    //Private Functions

};

#endif // IMAGE_H
