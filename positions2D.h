#pragma once
#include <iostream>

class Position2D {
public:
    Position2D() : x_(0), y_(0) {}
    Position2D(float x, float y) : x_(x), y_(y) {}
private:
    float x_;
    float y_;
};