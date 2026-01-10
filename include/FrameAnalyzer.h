#pragma once

#include "Logger.h"
#include <opencv4/opencv2/opencv.hpp>
#include <functional>

using DecisionCallback = std::function<bool(const cv::Mat&, const cv::Mat&)>;

class FrameAnalyzer
{
private:
    cv::Mat m_previousFrame;
    cv::Mat m_currentFrame;
    DecisionCallback m_callback;

public:
    FrameAnalyzer() : m_callback(nullptr) {};
    void setCallback(DecisionCallback cb);
    void setFrame(cv::Mat& frame);
    bool decision();

};
