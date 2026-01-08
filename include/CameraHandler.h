#pragma once

extern "C"
{
    #include <gphoto2/gphoto2-camera.h>
    #include <gphoto2/gphoto2-context.h>
}

#include <string>

class CameraHandler
{

private:
    Camera* m_camera;
    GPContext* m_context;

public:
    CameraHandler();

    int connect();
    void disconnect();

    bool setAperture(std::string value);
    bool setISO(std::string value);
    bool setShutterSpeed(std::string value);

};

