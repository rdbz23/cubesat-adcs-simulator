#include "Orientation.h"
#include <cmath>

void Orientation::normalize() {
    pitch = fmod(pitch + 360.0f, 360.0f);
    yaw   = fmod(yaw + 360.0f, 360.0f);
    roll  = fmod(roll + 360.0f, 360.0f);
}