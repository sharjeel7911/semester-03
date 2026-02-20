#include "class.h"

void shapes() {
    clearScreen();
    Shape* shape = new Shape("Red");
    shape->display();
    cout << endl;
    Shape* shape0 = new TwoDShape("Violet", 5);
    shape0->display();
    cout << endl;
    Shape* shape1 = new Rectangle("Green", 4, 7, 8);
    shape1->display();
    cout << endl;

    delete shape;
    delete shape0;
    delete shape1;

    //__________________________________________________________________-

    Shape s("Black");
    s.display();
    cout << endl;
    TwoDShape t("Blue", 8);
    t.display();
    cout << endl;
    Rectangle r("Yellow", 4, 6, 5);
    r.display();
    cout << endl;
    pauseScreen();
}