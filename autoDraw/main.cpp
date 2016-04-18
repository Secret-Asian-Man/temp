//got switch windows
//got click, move, and hold
//got arrays
//need to process an image 1bit bmp (monochrome bitmap)
//need to convert image to 2D binary array
//need to detect if pixel is black or not

//have 1D array of coords of only the interesting pixels
//sort the array according the the X coordinate ie (1,0),(1,2),(1,3),(1,4),(2,5),(2,6),(2,7)
//if the the next pixel to the right exists, don't lift up the pencil.


#include <windows.h>
#include <iostream>
#include "image.h"
#include <vector>


using std::vector;
using namespace std;

int main()
{
    unsigned int choice;
    vector<string*> container;

    try
    {
        container.push_back(new string("em"));
        container.push_back(new string("space-invader-b-w"));
        container.push_back(new string("BWPika"));
        container.push_back(new string("smallPika"));
        container.push_back(new string("DrZ"));
        container.push_back(new string("cutePika"));
        container.push_back(new string("aDick"));
        container.push_back(new string("pikaGhost"));
        container.push_back(new string("crossedGuns"));

        for (unsigned int i=0;i<container.size();++i)
            cout<<i<<":"<<*container[i]<<endl;

        cout<<endl;

        while(choice<0||choice>container.size())
        {
            cout<<"Pick one: ";
            cin>>choice;
        }

        string base="C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/";
        base+=*container[choice];
        base+=".bmp";

        image myImage(base.c_str());

//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/em.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/space-invader-b-w.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/BWPika.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/smallPika.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/DrZ.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/cutePika.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/aDick.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/pikaGhost.bmp");
//        image myImage("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/crossedGuns.bmp");

        myImage.saveToFile();
        myImage.drawImage();












    }
    catch(ERRORS error)
    {
        switch (error)
        {

        case FILE_NOT_FOUND:
            std::cout<<"ERROR FILE_NOT_FOUND "<<std::endl;
            break;

        default:
            std::cout<<"Unknown Error... "<<std::endl;
            break;
        }
    }

    return 0;
}

