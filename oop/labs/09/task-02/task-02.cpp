#include "class.h"

void vehicle() {
    clearScreen();
    VehicleX* vehicle = new CarX;
    cout << endl;
    VehicleX* veh = new CarX("Toyota", 2000);
    vehicle->display();
    cout << endl;
    veh->display();
    cout << endl;

    CarX c;
    cout << endl;
    CarX car("Honda", 2010);
    c.display();
    cout << endl;
    car.display();
    delete vehicle;
    delete veh;
    pauseScreen();
}