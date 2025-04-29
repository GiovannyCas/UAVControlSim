

#include "SensorModule.h"
#include <cstdlib> // for rand()
#include <ctime>

SensorModule::SensorModule() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random
}

SensorData SensorModule::readSensors() {
    SensorData data;
    data.latitude = 28.5383 + static_cast<double>(std::rand()) / RAND_MAX; // dummy near Orlando
    data.longitude = -81.3792 + static_cast<double>(std::rand()) / RAND_MAX;
    data.altitude = 100.0 + (std::rand() % 100); // 100–200 meters
    data.velocity = 5.0 + (std::rand() % 10);    // 5–15 m/s
    return data;
}
