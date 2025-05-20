#pragma once

struct SensorData {
    float gyro[3];
    float magneto[3];
};

SensorData readSensorData();
float random_noise();