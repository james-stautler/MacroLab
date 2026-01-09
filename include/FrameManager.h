#pragma once

#include <condition_variable>
#include <mutex>
#include <opencv4/opencv2/opencv.hpp>
#include "CameraHandler.h"
#include "Logger.h"

class FrameManager
{
private:
    CameraHandler m_camera;
    cv::Mat m_sharedFrame;
    bool m_hasNewFrame = false;
    bool m_running = true;
    std::mutex m_mtx;
    std::condition_variable m_cond;

public:
    FrameManager(CameraHandler& camera): m_camera(camera) {};
    void producer();
    void consumer();
    void stop();

};
