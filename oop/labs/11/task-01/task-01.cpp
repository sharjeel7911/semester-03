#include "vehicle.h"

void vehicle() {
    clearScreen();
    Vehicle* v1 = new Vehicle(50, 1000);
    v1->display();
    cout << endl;
    Vehicle* v2 = new Car(150, 110, 40, 500);
    v2->display();
    cout << endl;
    Vehicle* v3 = new Truck(150, 40, 500);
    v3->display();
    delete v1, delete v2, delete v3;
    v1 = nullptr, v2 = nullptr, v3 = nullptr;
    pauseScreen();
}