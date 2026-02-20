#include "smart-home.h"

void smartHome() {
    clearScreen();
    cout << "********** Smart Home Simulation **********" << endl;
    Home* home = new Home();
    Device* light1 = new Light(1, 75);
    light1->turnOn();
    light1->turnOff();
    Device* thermostat1 = new Thermostat(2, 22.5);
    thermostat1->turnOn();
    thermostat1->turnOff();
    home->addDevice(thermostat1);
    home->addDevice(light1);
    home->controlDevices();
    delete home;
    delete light1;
    delete thermostat1;
    pauseScreen();
}