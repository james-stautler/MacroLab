#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include "../include/CameraHandler.h"


int main(int argc, char* argv[])
{
    CameraHandler camera;
    int result = camera.connect();
    if (result != 0)
    {
        return 1;
    }
    return 0;
}


