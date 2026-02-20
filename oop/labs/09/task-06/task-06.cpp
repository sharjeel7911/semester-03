#include "class.h"

void employeeX() {
    clearScreen();
    //Employee* em = new Manager(10, 10000, "Sharjeel", 0, 1500); //In private Inheritance, base class can't be accessed by outside code
    //em->display();
    //cout << endl;
    ManagerX m(15, 50000, "Ahmad", 1, 2000);
    m.display();
    pauseScreen();
}