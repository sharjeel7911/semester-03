#include "class.h"

void task03() {
    clearScreen();
    cout << "-------------------- Task 03 --------------------" << endl << endl;

    Student student1(1, "Sharjeel");
    Student student2(2, "Ahmad");

    Club club1("Chess Club");
    Club club2("Sports Club");

    Membership membership1(&student1, &club1);
    Membership membership2(&student2, &club2);

    cout << "Students Information:" << endl;
    student1.displayStudent();
    student2.displayStudent();
    cout << endl;

    cout << "Club Information:" << endl;
    club1.displayClub();
    club2.displayClub();
    cout << endl;

    cout << "Membership Information:" << endl;
    membership1.displayMembership();
    membership2.displayMembership();
    cout << endl;
    pauseScreen();
}

