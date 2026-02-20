#include "class.h"

void shape() {
    clearScreen();
    RectangleX r(6, 8, "Red");
    r.display();
    cout << endl;
    ShapeX* shape = new RectangleX(7, 6, "Brown");
    shape->display();
    delete shape;
    pauseScreen();
}