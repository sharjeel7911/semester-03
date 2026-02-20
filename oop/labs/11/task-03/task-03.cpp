#include "personx.h"

void personVirtual() {
    clearScreen();
    cout << "=== Person (Virtual Inheritance) ===" << endl << endl;

    Personx* p1 = new Personx("Sharjeel", 30);
    p1->display();
    cout << endl;
    Studentx* s1 = new Studentx("Ayesha", 20, "A");
    s1->display();
    cout << endl;
    Teacherx* t1 = new Teacherx("Mr. Khan", 45, "Mathematics");
    t1->display();
    cout << endl;
    TAx* ta1 = new TAx("Bilal", 25);
    ta1->display();
    cout << endl;
    delete p1;
    delete s1;
    delete t1;
    delete ta1;
    pauseScreen();
}