#pragma once

extern "C"
{
    #include <gphoto2/gphoto2-camera.h>
    #include <gphoto2/gphoto2-context.h>
}

#include <string>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

class CameraHandler
{

private:
    Camera* m_camera;
    GPContext* m_context;

public:
    CameraHandler();

    int connect();
    void disconnect();

    std::string getCameraMode();
    std::string getConfiguration(const std::string& setting);

    bool setConfiguration(const std::string& setting, const std::string& value);
    
    bool captureImage(const std::string& fileName);
    cv::Mat getImageFrame();
    cv::Mat getPreviewFrame();

};

