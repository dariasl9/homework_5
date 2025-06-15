#pragma once
#include <vector>
#include <memory>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update() = 0;
};

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notify() = 0;
};