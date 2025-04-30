#pragma once

struct SensorData {
    double latitude;
    double longitude;
    double altitude;
    double velocity;
};

class SensorModule {
public:
    SensorModule();
    SensorData readSensors();
    
};