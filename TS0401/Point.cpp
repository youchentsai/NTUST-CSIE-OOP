#define _USE_MATH_DEFINES
#include "Point.h"
#include <cmath>

void Point::Set(int _vertical, int _horizontal) {
    vertical = _vertical;
    horizontal = _horizontal;
}

void Point::Move(int x, int y) {
    vertical += x;
    horizontal += y;
}
void Point::Rotate() {
    double cita = atan2(vertical, horizontal);
    double length = sqrt(pow(vertical, 2) + pow(horizontal, 2));
    vertical = round(length * sin(cita + (90 * (M_PI / 180)))); // sin use rad
    horizontal = round(length * cos(cita + (90 * (M_PI / 180))));
}
