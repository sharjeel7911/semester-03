#include "class.h"

void teacher() {
    clearScreen();
    Teacher* t0 = new Teacher("Ali", 40, "Ph.D. in Physics", 40);
    Teacher* t1 = new PermanentTeacher("Sharjeel", 35, "M.Sc. in Mathematics", 30, 55000.0);
    Teacher* t2 = new VisitingTeacher("Ayesha", 29, "B.Ed.", 25, 500.0, 20);
    Teacher* staff[]{ t0, t1, t2 };

    for (int i = 0; i < 3; ++i) {
        staff[i]->display();
        cout << endl << endl;
    }
    delete t0;
    delete t1;
    delete t2;
    pauseScreen();
}