#include "../include/CameraHandler.h"
#include "../include/Logger.h"

CameraHandler::CameraHandler()
{
    m_camera = nullptr;
    m_context = gp_context_new();
}

int CameraHandler::connect()
{
    int res = 0;

    gp_camera_new(&m_camera);
    res = gp_camera_init(m_camera, m_context);

    if (res < GP_OK)
    {
        Logger::Log(LogLevel::ERROR, "Could not connect to camera. Code: %d", res);
        gp_camera_free(m_camera);
        m_camera = nullptr;
        return res;
    }

    Logger::Log(LogLevel::INFO, "Successfully connected to camera!");
    return res;
}

void CameraHandler::disconnect()
{
    if (m_camera)
    {
        gp_camera_exit(m_camera, m_context);
        gp_camera_free(m_camera);
    }
    gp_context_unref(m_context);
}

bool CameraHandler::setAperture(std::string value)
{
    return false;
}

bool CameraHandler::setISO(std::string value)
{
    return false;
}

bool CameraHandler::setShutterSpeed(std::string value)
{
    return false;
}
