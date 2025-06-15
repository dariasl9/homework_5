#pragma once
#include "document.h"

class Controller {
public:
    Controller(std::unique_ptr<Document> doc) : document(std::move(doc)) {}

    void attachView(IObserver* view) { document->attach(view); }
    void detachView(IObserver* view) { document->detach(view); }

    void createCircle(Position2D center, float radius, Color color) {
        document->addShape<Circle>(center, radius, color);
    }
    void createRectangle(Position2D topLeft, Position2D size, Color color) {
        document->addShape<Rectangle>(topLeft, size, color);
    }

private:
    std::unique_ptr<Document> document;
};