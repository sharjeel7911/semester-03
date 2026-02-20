#include "class.h"

void task01() {
    clearScreen();
    cout << "-------------------- Task 01 --------------------" << endl << endl;

    Passport passport1(12345, "Pakistan");
    Person person1("Sharjeel", &passport1);

    cout << "Person Details:" << endl;
    person1.display();

    passport1.setPassportNumber(54321);
    passport1.setNationality("India");

    cout << endl << "After Update:" << endl;
    person1.display();
    pauseScreen();
}