#ifndef CAMERA_CONTROLLER_HPP
#define CAMERA_CONTROLLER_HPP

// Your code here

enum class CameraControllerResult {
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

class CameraController {
public:
    virtual ~CameraController() = default;
    virtual CameraControllerResult initialize() = 0;
    virtual CameraControllerResult openCamera() = 0;
    virtual CameraControllerResult captureImage() = 0;
    virtual CameraControllerResult closeCamera() = 0;
};


#endif // CAMERA_CONTROLLER_HPP