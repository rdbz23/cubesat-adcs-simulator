#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "Orientation.h"
#include "Sensor.h"
#include "Actuator.h"

int main() {
    srand(time(nullptr));
    Orientation current = {0, 0, 0};
    Orientation target = {10, -5, 15};

    std::ofstream logfile("data/log.csv");
    logfile << "Pitch,Yaw,Roll\n";

    while (true) {
        SensorData data = readSensorData();
        applyPIDCorrection(current, target);

        std::cout << "Pitch: " << current.pitch
                  << " Yaw: " << current.yaw
                  << " Roll: " << current.roll << "\n";

        logfile << current.pitch << "," << current.yaw << "," << current.roll << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}