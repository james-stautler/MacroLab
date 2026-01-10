#include "../include/FrameAnalyzer.h"

void FrameAnalyzer::setCallback(DecisionCallback cb)
{
    m_callback = cb;
}

void FrameAnalyzer::setFrame(cv::Mat& frame)
{
    if (!m_currentFrame.empty())
    {
        m_currentFrame.copyTo(m_previousFrame);
    }
    
    m_currentFrame = frame.clone();
}

bool FrameAnalyzer::decision()
{
    if (m_previousFrame.empty() || m_currentFrame.empty())
    {
        return false;
    }

    if (!m_callback)
    {
        Logger::Log(LogLevel::ERROR, "No decision function set for frame analyzer");
        return false;
    }

    return m_callback(m_previousFrame, m_currentFrame);
}
