#pragma once

struct Orientation {
    float pitch;
    float yaw;
    float roll;

    void normalize();
};