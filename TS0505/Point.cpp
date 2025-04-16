#include "Point.h"

Point::Point() {
    coords = new double[2]{0, 0};
}

// copy constructor
Point::Point(const Point& other) {
    coords = new double[2];
    coords[0] = other.coords[0];
    coords[1] = other.coords[1];
}

Point::~Point() {
    delete[] coords;
}

void Point::Set(int x, int y) {
    coords[0] = x;
    coords[1] = y;
}

void Point::Move(int x, int y) {
    coords[0] += x;
    coords[1] += y;
}

void Point::Rotate() {
    double cita = atan2(coords[1], coords[0]);                // rad
    double cita_afterRotate = cita - ((90.0 / 180.0) * M_PI); // 90/180 => 0(interger division!!)
    double length = sqrt(pow(coords[0], 2) + pow(coords[1], 2));
    coords[0] = length * cos(cita_afterRotate);
    coords[1] = length * sin(cita_afterRotate);
    coords[0] = (coords[0] == 0) ? 0 : coords[0];
    coords[1] = (coords[1] == 0) ? 0 : coords[1];
}

void Point::Reflect() {
    coords[0] = (coords[0] == 0) ? 0 : -coords[0];
    coords[1] = (coords[1] == 0) ? 0 : -coords[1];
}

double Point::GetHorizontal() {
    return coords[0];
}

double Point::GetVertical() {
    return coords[1];
}