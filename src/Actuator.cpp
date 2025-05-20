#include "Actuator.h"

void applyPIDCorrection(Orientation &current, const Orientation &target) {
    float kp = 0.5f;
    current.pitch += kp * (target.pitch - current.pitch);
    current.yaw   += kp * (target.yaw - current.yaw);
    current.roll  += kp * (target.roll - current.roll);
    current.normalize();
}