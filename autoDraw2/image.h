#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
//#include <windows.h>
#include <cstdlib>
#include "EasyBMP.h"

enum ERRORS{FILE_NOT_FOUND};


using std::string;

class image
{
public:

    //Constructors
    image();
    image(string newImageName, unsigned int newDelay, int newStartPosX, int newStartPosY);

    //Destructor
    ~image();

    //Accessors
    string getImageName();
    unsigned int getImageWidth();
    unsigned int getImageHeight();
    string getBitmap();
    unsigned int getDelay();
    int getStartPosX();
    int getStartPosY();

    string getImageName()const;
    unsigned int getImageWidth()const;
    unsigned int getImageHeight()const;
    string getBitmap()const;
    unsigned int getDelay()const;
    int getStartPosX()const;
    int getStartPosY()const;

    //Mutators
    void setImageName(string newImageName);
    void setImageWidth(unsigned int newImageWidth);
    void setImageHeight(unsigned int newImageHeight);
    void setBitmap(string newBitmap);
    void setDelay(unsigned int newDelay);
    void setStartPosX(int newStartPosX);
    void setStartPosY(int newStartPosY);
    void setBothStartPosXY(int newStartPosX,int newStartPosY);

    //Operators

    //Functions
    void print();
    void saveToFile();
    void drawImage();

    //Public Member Variables
    string bitmap;

private:

    //Private Member Variables
    string imageName;
    int imageWidth;
    int imageHeight;
    BMP bmpImage;
    unsigned int delay;
    int startPosX;
    int startPosY;

    //Private Functions

};

#endif // IMAGE_H
