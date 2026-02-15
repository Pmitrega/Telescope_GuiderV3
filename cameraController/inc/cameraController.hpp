#ifndef CAMERA_CONTROLLER_HPP
#define CAMERA_CONTROLLER_HPP

#include <cstdint>
#include <string>
// Your code here

enum class CameraControllerResult
{
    SUCCESS,
    ERROR,
    ROI_NOT_SUPPORTED,
    EXPOSURE_NOT_SUPPORTED,
    GAIN_NOT_SUPPORTED,
    INTERVAL_NOT_SUPPORTED,
    CAMERA_NOT_CONNECTED,
    PERMISSION_DENIED,
    UNKNOWN_ERROR
};

enum class CameraSetupableControl
{
    EXPOSURE,
    GAIN,
    INTERVAL
};

enum class ControlReadableControl
{
    EXPOSURE,
    GAIN,
    INTERVAL,
    TEMPERATURE
};

class CameraController
{
public:
    virtual ~CameraController() = default;
    virtual std::string getCameraInfo() const = 0;
    virtual CameraControllerResult initialize() = 0;
    virtual CameraControllerResult startImageCapture() = 0;
    virtual CameraControllerResult stopImageCapture() = 0;
    virtual CameraControllerResult startVideoCapture() = 0;
    virtual CameraControllerResult stopVideoCapture() = 0;
    virtual bool isBufferReady() = 0;
    virtual CameraControllerResult getImageBuffer(uint8_t *buffer, int &size) = 0;
    virtual CameraControllerResult setROI(int x, int y, int width, int height) = 0;
    virtual CameraControllerResult getROIMaxValues(int &maxWidth, int &maxHeight) = 0;
    virtual CameraControllerResult setControlValue(CameraSetupableControl control, int value) = 0;
    virtual CameraControllerResult getControlValue(ControlReadableControl control, int &value) = 0;
    virtual CameraControllerResult openCamera() = 0;
    virtual CameraControllerResult closeCamera() = 0;
};

#endif // CAMERA_CONTROLLER_HPP