 #include "../include/FrameManager.h"

void FrameManager::producer() 
{ 
    while (m_running)
    {
        cv::Mat frame = m_camera.getPreviewFrame();
        if (!frame.empty())
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            m_sharedFrame = frame;
            m_hasNewFrame = true;
            m_cond.notify_one();
        }
    }
}

void FrameManager::consumer() 
{ 
    while (m_running)
    {
        cv::Mat frameToProcess;
        {
            std::unique_lock<std::mutex> lock(m_mtx);
            m_cond.wait(lock, [this] { return m_hasNewFrame || !m_running; });
            if (!m_running)
            {
                return;
            }
            frameToProcess = m_sharedFrame;
            m_hasNewFrame = false;
        }

        m_frameAnalyzer.setFrame(frameToProcess);
        if (m_frameAnalyzer.decision())
        {
            // PUT DECISION LOGIC IN HERE
            m_running = false;
        }
    }
}

void FrameManager::stop()
{
    m_running = false;
}
