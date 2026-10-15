#include "class.h"

void appliance() {
    clearScreen();
    cout << "Color attribute should be const char* " << endl;
    Appliance* app = new AirConditioner(100, 5, "Sony", "Red", "Electrical");
    app->display();
    cout << endl;
    app->showAttributes();
    cout << endl;
    AirConditioner ac(1000, 10, "Mitsubishi", "Violet", "AC");
    ac.display();
    cout << endl;
    ac.showAttributes();
    pauseScreen();
}