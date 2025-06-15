#include <iostream>
#include <memory>
#include "controller.h"
#include "document.h"

class Controller;

class IView {
public:
    virtual ~IView() = default;
    virtual void update() = 0;
};


class GUIWindow : public IView, public IObserver {
public:
    GUIWindow() {}
    ~GUIWindow() { if (ctrl) ctrl->detachView(this); }

    void setController(Controller* controller) { ctrl = controller; if (ctrl) ctrl->attachView(this);}

    void mainLoop() {
        // handle user events
    }

    void update() override {
        refresh();
    }

    void show() {}
    void refresh() {}

private:
    Controller* ctrl;

    // user events
    void handleAddCircle(Position2D center, float radius, Color color) { ctrl->createCircle(center, radius, color); }
    void handleAddRectangle(Position2D topLeft, Position2D size, Color color) { ctrl->createRectangle(topLeft, size, color); }

    void onSaveButtonClick() {}
    void onExitButtonClick() {}
};

class SimpleApplication
{
public:
    SimpleApplication(int argc, char *argv[]) {};
    int exec(GUIWindow* w)
    {
        w->show();
        w->mainLoop();
        return 0;
    }
};

int main(int argc, char *argv[]) {
    SimpleApplication app(argc, argv);

    auto doc = std::make_unique<Document>();
    Controller ctrl(std::move(doc));

    auto mainWindow = std::make_unique<GUIWindow>();
    mainWindow->setController(&ctrl);

    return app.exec(mainWindow.get());
}