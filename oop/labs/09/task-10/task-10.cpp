#include "class.h"

void professor() {
    clearScreen();
    Teacher* t1 = new Professor("Dr. Sharjeel", "Math", "AI", 10, "CS", 15);
    Researcher* r1 = new Professor("Dr. Ahmad", "Physics", "Quantum", 7, "Physics", 12);
    Professor* p1 = new Professor("Dr. Ali", "Biology", "Genetics", 8, "Biology", 14);

    t1->display();
    cout << endl;
    r1->display();
    cout << endl;
    p1->display();
    cout << endl;

    delete t1;
    delete r1;
    delete p1;

    //_____________________________________________________________________

    Professor prof("Dr. Usman", "Math", "Algebra", 6, "Mathematics", 11); //stack obj
    prof.display();
    cout << endl;
    Teacher* t2 = &prof; //Teacher t(....) for stack obj
    t2->display();
    cout << endl;
    Researcher* r2 = &prof; //Researcher r(....) for stack obj
    r2->display();
    pauseScreen();
}