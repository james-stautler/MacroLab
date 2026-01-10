#pragma once

#include <condition_variable>
#include <mutex>
#include <opencv4/opencv2/opencv.hpp>
#include "CameraHandler.h"
#include "Logger.h"
#include "FrameAnalyzer.h"

class FrameManager
{
private:
    CameraHandler m_camera;
    FrameAnalyzer m_frameAnalyzer;
    cv::Mat m_sharedFrame;
    bool m_hasNewFrame = false;
    bool m_running = true;
    std::mutex m_mtx;
    std::condition_variable m_cond;

public:
    FrameManager(CameraHandler& camera, FrameAnalyzer& frameAnalyzer): m_camera(camera), m_frameAnalyzer(frameAnalyzer) {};
    void producer();
    void consumer();
    void stop();

};
