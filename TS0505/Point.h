#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class Point {
private:
    double* coords;

public:
    Point();

    // copy constructor
    Point(const Point& other);

    // decontructor
    ~Point();

    void Set(int, int);

    void Move(int, int);

    void Rotate();

    void Reflect();

    double GetHorizontal();

    double GetVertical();
};