#include "class.h"

void vehicles() {
    clearScreen();
    Vehicle* veh = new Vehicle("Toyota", 2000);
    veh->display();
    cout << endl;
    Vehicle* veh0 = new RoadVehicle("Honda", 2005, 22);
    veh0->display();
    cout << endl;
    Vehicle* veh1 = new Car("Tesla", 2010, "Green", 10000);
    veh1->display();
    cout << endl;

    delete veh;
    delete veh0;
    delete veh1;

    //______________________________________________________________________________-

    Vehicle s("Alto", 2020);
    s.display();
    cout << endl;
    RoadVehicle t("BMW", 2000, 6);
    t.display();
    cout << endl;
    Car r("Yellow", 2024, "Blue", 1000);
    r.display();
    cout << endl;
    pauseScreen();
}