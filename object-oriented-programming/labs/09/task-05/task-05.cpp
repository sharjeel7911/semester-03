#include "class.h"

void employee() {
    clearScreen();
    //Employee* em = new Manager(10, 10000, "Sharjeel", 0, 1500); //In protected Inheritance, base class can't be accessed by outside code
    //em->display();
    //cout << endl;
    Manager e(15, 50000, "Ahmad", 1, 2000);
    e.display();
    pauseScreen();
}