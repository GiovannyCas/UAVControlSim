#pragma once

#include "SensorModule.h"
#include "ControlModule.h"
#include "CommandModule.h"

class HardwareAbstractionLayer {
public:
    SensorModule sensor;
    ControlModule control;
    CommandModule command;
};