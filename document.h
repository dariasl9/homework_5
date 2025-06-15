#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "shapes.h"
#include "observer.h"

class Shape;

class Document : public ISubject {
public:
    bool loadFromFile(const std::string& filename) { return 0; }
    bool saveToFile(const std::string& filename) { return 0; }

    void clear() {}

    template <typename ShapeT, typename... Args>
    void addShape(Args&&... args)
    {
        shapes.emplace_back(
            std::make_unique<ShapeT>(std::forward<Args>(args)...)
        );
        notify(); // for View
    }

    void attach(IObserver* observer) override {}
    void detach(IObserver* observer) override {}
    void notify() override {
        for (auto observer : observers) observer->update();
    }

private:
    std::vector<std::unique_ptr<Shape>> shapes;
    std::vector<IObserver*> observers;
};

