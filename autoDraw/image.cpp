#include "image.h"
#include <ostream>
#include <fstream>

#define startingMouseX 528
#define startingMouseY 108


image::image()
{
    imageName="C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/BWPika.bmp";
    bmpImage.ReadFromFile(imageName.c_str());
    imageHeight = bmpImage.TellHeight();
    imageWidth = bmpImage.TellWidth();



}

image::image(std::string newImageName)
{
    imageName=newImageName;
    bmpImage.ReadFromFile(imageName.c_str());
    imageHeight = bmpImage.TellHeight();
    imageWidth = bmpImage.TellWidth();

}

image::~image()
{

}

std::string image::getImageName()
{
    return imageName;
}

unsigned int image::getImageWidth()
{
    return imageWidth;
}

unsigned int image::getImageHeight()
{
    return imageHeight;
}

string image::getBitmap()
{
    return bitmap;
}

std::string image::getImageName() const
{
    return imageName;
}

unsigned int image::getImageWidth() const
{
    return imageWidth;
}

unsigned int image::getImageHeight() const
{
    return imageHeight;
}

std::string image::getBitmap() const
{
    return bitmap;
}

void image::setImageName(std::string newImageName)
{
    imageName=newImageName;
}

void image::setImageWidth(unsigned int newImageWidth)
{
    imageWidth=newImageWidth;
}

void image::setImageHeight(unsigned int newImageHeight)
{
    imageHeight=newImageHeight;
}

void image::setBitmap(std::string newBitmap)
{
    bitmap=newBitmap;
}

void image::print()
{

    for (int i=0;i<imageWidth;++i)
    {
        for (int j=0;j<imageHeight;++j)
        {
            if (bmpImage(i,j)->Green==255 && bmpImage(i,j)->Red==255 && bmpImage(i,j)->Blue==255)
                std::cout<<"0";
            else
                std::cout<<"1";
        }
        std::cout<<"\n";
    }

}

void image::saveToFile()
{
    std::ofstream out("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/binaryPicture.txt");

    for (int i=0;i<imageWidth;++i)
    {
        for (int j=0;j<imageHeight;++j)
        {
            if (bmpImage(i,j)->Green==255 && bmpImage(i,j)->Red==255 && bmpImage(i,j)->Blue==255)
                out<<"0";
            else
                out<<"1";

        }
        out<<"\n";
    }

    out.close();
}

void image::drawImage()
{
    std::ifstream in("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/binaryPicture.txt");

    if (!in.is_open())
        throw FILE_NOT_FOUND;

    long mousePositionX=startingMouseX;
    long mousePositionY=startingMouseY;

    Sleep(1000);
    HWND hWnd = ::FindWindow(NULL, L"Tabletop Simulator"); //brings window up to front
    if (hWnd)
        // move to foreground
        ::SetForegroundWindow(hWnd);
    Sleep(5000);

    while(!in.eof())
    {
        std::getline(in,bitmap);

        SetCursorPos(mousePositionX,mousePositionY);

        for (unsigned int i=0;i<bitmap.size();++i)
        {
            //use firstOf and firstNotOf on string of binary to jump coordinates while keeping track of position

            if (bitmap[i]=='1') //is 1
            {
                Sleep(30);
                SetCursorPos(mousePositionX+i,mousePositionY);
                Sleep(30);
                mouse_event(MOUSEEVENTF_LEFTDOWN,(mousePositionX+i),mousePositionY,0,0);
                i = bitmap.find_first_not_of('1',i)-1;
                Sleep(30);
                SetCursorPos(mousePositionX+i,mousePositionY);
                Sleep(30);
            }
            else //is 0
            {
                Sleep(10);
                mouse_event(MOUSEEVENTF_LEFTUP,(mousePositionX+i),mousePositionY,0,0);
                Sleep(10);
                i = bitmap.find_first_not_of('0',i)-1;
            }

        }

        ++mousePositionY; //go down 1

        std::getline(in,bitmap); //throws away half the data, making picture look more pixelated
        ++mousePositionY; //go down 1
        std::getline(in,bitmap); //throws away half the data, making picture look more pixelated
        ++mousePositionY; //go down 1



        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
    }

    in.close();
}



