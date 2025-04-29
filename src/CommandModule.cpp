#include "CommandModule.h"
#include <iostream>

void CommandModule::sendCommand(const ControlCommand& cmd) {
    std::cout << "Motor Power: " << cmd.motorPower
        << ", Direction Angle: " << cmd.directionAngle << " degrees" << std::endl;
}
