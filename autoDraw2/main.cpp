#include <iostream>
//#include <windows.h>
#include <vector>
#include "image.h"

using namespace std;
using std::vector;

#define DELAY_TIME 7
#define BRUSH_STROKE_DELAY 4
#define START_POS_X 527
#define START_POS_Y 182

int main()
{

    try
    {
        unsigned int choice=-1;
        vector<string*> container;

        container.push_back(new string("space-invader-b-w"));
        container.push_back(new string("smallPika"));
        container.push_back(new string("cutePika"));
        container.push_back(new string("pikaGhost"));
        container.push_back(new string("crossedGuns"));
        container.push_back(new string("kyle"));
        container.push_back(new string("tigers"));
        container.push_back(new string("SaffronCity"));
        container.push_back(new string("illusion"));
        container.push_back(new string("illusion2"));
        container.push_back(new string("illusion3"));
        container.push_back(new string("illusion4"));

        for (unsigned int i=0;i<container.size();++i)
            cout<<i<<":"<<*container[i]<<endl;

        cout<<endl;



        while(choice<0||choice>container.size())
        {
            cout<<"Pick one: ";
            cin>>choice;
        }

        cout<<"You picked "<<*container[choice]<<". "<<endl<<endl;

        string base="C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/";
        base+=*container[choice];
        base+=".bmp";


        image myImage(base,BRUSH_STROKE_DELAY,START_POS_X,START_POS_Y);

        myImage.saveToFile();

//        for (unsigned int i=DELAY_TIME;i>0;--i)
//        {
//            cout<<"Starting in "<<i<<"..."<<endl;
//            Sleep(1000);
//        }

//        myImage.drawImage();


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

