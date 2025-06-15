#pragma once
#include "positions2D.h"
#include "Color.h"

class Shape {
public:
    virtual ~Shape() = default;
    virtual void move(float dx, float dy) = 0;
    virtual Position2D getPosition() const = 0;

    void setColor(const Color& newColor) {}
    const Color& getColor() const { return color_; }

protected:
    Shape(const Color& color) : color_(color) {}

private:
    Color color_;
};


class Circle : public Shape {
public:
    Circle(Position2D center, float radius, Color color) : Shape(color), center_(center), radius_(radius) {}
    void move(float dx, float dy) override {}
    Position2D getPosition() const override { return center_; }
    float getRadius() const { return radius_; }

private:
    Position2D center_;
    float radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(Position2D topLeft, Position2D size, Color color) : Shape(color), topLeft_(topLeft), size_(size) {}
    
    void move(float dx, float dy) override {}
    Position2D getPosition() const override { return topLeft_; } 
    Position2D getSize() const { return size_; }

private:
    Position2D topLeft_;
    Position2D size_;
};