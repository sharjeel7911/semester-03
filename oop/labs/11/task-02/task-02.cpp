#include "person.h"

void person() {
    clearScreen();
    Person* p1 = new Person("Sharjeel", 30);
    p1->display();
    cout << endl;
    Person* p2 = new Student("Ahmad", 20, "A");
    p2->display();
    cout << endl;
    Person* p3 = new Teacher("Ali", 40, "Math");
    p3->display();
    cout << endl;
    //Person* p4 = new TA("David", 25); //ambiguous
    TA* p4 = new TA("Shareef", 25);
    p4->display();
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;
    p4 = nullptr;
    pauseScreen();
}