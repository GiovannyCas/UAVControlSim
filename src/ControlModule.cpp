#include "ControlModule.h"
#include <cmath>

ControlCommand ControlModule::computeControl(const SensorData& data) {
    ControlCommand cmd;

    // Very simple logic: if altitude too low, increase power
    if (data.altitude < 150.0) {
        cmd.motorPower = 0.8; // 80% throttle
    }
    else {
        cmd.motorPower = 0.5; // cruise
    }

    // Dummy heading adjustment
    cmd.directionAngle = std::fmod(data.longitude * 1000, 360.0); // fake angle
    return cmd;
}