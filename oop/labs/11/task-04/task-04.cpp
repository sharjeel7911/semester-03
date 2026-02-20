#include "shape.h"

void shape() {
    clearScreen();
    Shape* s1 = new Circle("Red", 5.0f);
    Shape* s2 = new Rectangle("Blue", 4.0f, 6.0f);
    s1->display();
    s1->area();
    cout << endl;
    s2->display();
    s2->area();
    delete s1;
    delete s2;
    pauseScreen();
}