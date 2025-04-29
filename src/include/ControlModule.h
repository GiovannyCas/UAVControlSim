#pragma once


#include "SensorModule.h"

struct ControlCommand {
    double motorPower;
    double directionAngle;
};


class ControlModule {
public:
    ControlCommand computeControl(const SensorData& data);
};