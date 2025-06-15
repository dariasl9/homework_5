#pragma once
#include <iostream>

class Color {
public:
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r_(r), g_(g), b_(b), a_(a) {}
private:
    uint8_t r_, g_, b_, a_;
};