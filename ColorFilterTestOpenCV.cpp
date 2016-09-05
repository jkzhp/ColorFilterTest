// ColorFilterTestOpenCV.cpp

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>           // may have to modify this line if not using Windows

///////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

    cv::Mat imgOriginal;   
    cv::Mat imgBlueChannel;
    cv::Mat imgGreenChannel;
    cv::Mat imgRedChannel;

    cv::Mat imgHSV;
    cv::Mat imgHue;
    cv::Mat imgSaturation;
    cv::Mat imgValue;

    cv::Mat imgLAB;
    cv::Mat imgLum;
    cv::Mat imgA;
    cv::Mat imgB;

    imgOriginal = cv::imread("color_wheel.png");          // open image

    if (imgOriginal.empty()) {                                  // if unable to open image
        std::cout << "error: image not read from file\n\n";     // show error message on command line
        _getch();                                               // may have to modify this line if not using Windows
        return(0);                                              // and exit program
    }

    cv::Mat imgsBgrChannels[3];
    cv::split(imgOriginal, imgsBgrChannels);
    imgBlueChannel = imgsBgrChannels[0];
    imgGreenChannel = imgsBgrChannels[1];
    imgRedChannel = imgsBgrChannels[2];

    cv::cvtColor(imgOriginal, imgHSV, CV_BGR2HSV);
    cv::Mat imgsHsvChannels[3];
    cv::split(imgHSV, imgsHsvChannels);
    imgHue = imgsHsvChannels[0];
    imgSaturation = imgsHsvChannels[1];
    imgValue = imgsHsvChannels[2];

    cv::cvtColor(imgOriginal, imgLAB, CV_BGR2Lab);
    cv::Mat imgsLabChannels[3];
    cv::split(imgLAB, imgsLabChannels);
    imgLum = imgsLabChannels[0];
    imgA = imgsLabChannels[1];
    imgB = imgsLabChannels[2];

    cv::imshow("imgOriginal", imgOriginal);
    cv::imshow("imgBlueChannel", imgBlueChannel);
    cv::imshow("imgGreenChannel", imgGreenChannel);
    cv::imshow("imgRedChannel", imgRedChannel);
    
    cv::imshow("imgHSV", imgHSV);
    cv::imshow("imgHue", imgHue);
    cv::imshow("imgSaturation", imgSaturation);
    cv::imshow("imgValue", imgValue);

    cv::imshow("imgLAB", imgLAB);
    cv::imshow("imgLum", imgLum);
    cv::imshow("imgA", imgA);
    cv::imshow("imgB", imgB);
    
    cv::waitKey(0);                 // hold windows open until user presses a key

    return(0);
}




