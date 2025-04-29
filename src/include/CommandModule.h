#pragma once
#include "ControlModule.h"

class CommandModule {
public:
    void sendCommand(const ControlCommand& cmd);
};