#include "image.h"
#include <ostream>
#include <fstream>

image::image()
{
    imageName="";
    bmpImage.ReadFromFile(imageName.c_str());
    imageHeight = bmpImage.TellHeight();
    imageWidth = bmpImage.TellWidth();
    delay=0;
    startPosX=0;
    startPosY=0;
}

image::image(std::string newImageName,unsigned int newDelay,int newStartPosX, int newStartPosY)
{
    imageName=newImageName;
    bmpImage.ReadFromFile(imageName.c_str());
    imageHeight = bmpImage.TellHeight();
    imageWidth = bmpImage.TellWidth();
    delay=newDelay;
    startPosX=newStartPosX;
    startPosY=newStartPosY;
}

image::~image()
{
    bitmap=imageName="";
    imageWidth=imageHeight=delay=startPosX=startPosY=0;
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

unsigned int image::getDelay()
{
    return delay;
}

int image::getStartPosX()
{
    return startPosX;
}

int image::getStartPosY()
{
    return startPosY;
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

unsigned int image::getDelay() const
{
    return delay;

}

int image::getStartPosX() const
{
    return startPosX;

}

int image::getStartPosY() const
{
    return startPosY;

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

void image::setDelay(unsigned int newDelay)
{
    delay=newDelay;
}

void image::setStartPosX(int newStartPosX)
{
    startPosX=newStartPosX;
}

void image::setStartPosY(int newStartPosY)
{
    startPosY=newStartPosY;
}

void image::setBothStartPosXY(int newStartPosX, int newStartPosY)
{
    startPosX=newStartPosX;
    startPosY=newStartPosY;
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

//void image::drawImage()
//{
//    std::ifstream in("C:/Users/David Wu/Desktop/Programming/Personal Projects/autoDraw/resources/binaryPicture.txt");

//    if (!in.is_open())
//        throw FILE_NOT_FOUND;

//    long mousePositionX=startPosX;
//    long mousePositionY=startPosY;

//    while(!in.eof())
//    {

//        std::getline(in,bitmap);

//        SetCursorPos(mousePositionX,mousePositionY);

//        for (unsigned int i=0;i<bitmap.size();++i)
//        {
//            //use firstOf and firstNotOf on string of binary to jump coordinates while keeping track of position

//            if (bitmap[i]=='1') //is 1
//            {
//                Sleep(delay/4);
//                SetCursorPos(mousePositionX+i,mousePositionY);
//                Sleep(delay/4);

//                mouse_event(MOUSEEVENTF_LEFTDOWN,(mousePositionX+i),mousePositionY,0,0);
//                Sleep(delay/4);

//                i = bitmap.find_first_not_of('1',i)-1;
//                SetCursorPos(mousePositionX+i,mousePositionY);
//                Sleep(delay/4);

//            }
//            else //is 0
//            {
//                Sleep(delay/4);
//                mouse_event(MOUSEEVENTF_LEFTUP,(mousePositionX+i),mousePositionY,0,0);
//                i = bitmap.find_first_not_of('0',i)-1;
//            }

//        }

//        ++mousePositionY; //go down 1

//        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
//        Sleep(delay);

////                std::getline(in,bitmap); //throws away half the data, making picture look more pixelated
////                ++mousePositionY; //go down 1
////                std::getline(in,bitmap); //throws away half the data, making picture look more pixelated
////                ++mousePositionY; //go down 1



//    }

//    in.close();
//}



