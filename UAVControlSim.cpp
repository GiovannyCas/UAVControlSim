// UAVControlSim.cpp : Defines the entry point for the application.
//



#include "HardwareAbstractionLayer.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{

    HardwareAbstractionLayer hal;

    std::cout << "Starting UAV Control Simulation..." << std::endl;

    for (int i = 0; i < 20; ++i) { // Run 20 iterations
        SensorData data = hal.sensor.readSensors();
        ControlCommand cmd = hal.control.computeControl(data);
        hal.command.sendCommand(cmd);

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 2Hz loop
    }

    std::cout << "Simulation ended." << std::endl;
	cout << "Hello CMake." << endl;
	return 0;
}
