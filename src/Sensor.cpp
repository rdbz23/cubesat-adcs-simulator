#include "Sensor.h"
#include <cstdlib>
#include <ctime>

float random_noise() {
    return ((rand() % 100) - 50) / 1000.0f;
}

SensorData readSensorData() {
    SensorData data;
    data.gyro[0] = 0.1f + random_noise();
    data.gyro[1] = -0.05f + random_noise();
    data.gyro[2] = 0.03f + random_noise();
    return data;
}