#include "ride.h"

void ride() {
    clearScreen();
    cout << "********** Vehicle Ride Simulation **********" << endl;

    Vehicle* myCar = new Car(4, 101);
    myCar->calculateFare();
    Vehicle* myBike = new Bike(2, 202);
    myBike->calculateFare();

    Driver* driver = new Driver(1);
    driver->acceptRide();
    Driver* driver1 = new Driver(2);
    driver1->acceptRide();
    delete myCar;
    delete myBike;
    delete driver;
    delete driver1;
    pauseScreen();
}