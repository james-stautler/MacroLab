#include "../include/DecisionFunctions.h"
#include "../include/FrameAnalyzer.h"

DecisionCallback DECISION_FUNCTIONS::motionDetection(double threshold)
{
    return [threshold] (const cv::Mat& prev, const cv::Mat& curr) -> bool 
    {
        cv::Mat diff;
        cv::absdiff(prev, curr, diff);
        return (cv::mean(diff)[0] > threshold);
    };
}
