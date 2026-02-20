#include "class.h"

void task02() {
    clearScreen();
    cout << "-------------------- Task 02 --------------------" << endl << endl;

    Course course1("O101", "Object Oriented Programming");
    Course course2("D101", "Data Structures");
    Course course3("P101", "Programming Fundamentals");
    Course course4("A101", "Algorithms");
    Course course5("C101", "Computer Architecture");

    Course course6("N101", "Networking");

    Course* courses[] = { &course1, &course2, &course3, &course4, &course5, &course6 };

    Teacher teacher("Hafiz Bilal", courses);
    teacher.displayCourses();

    if (teacher.addCourse(&course6)) cout << endl << "Added new course successfully." << endl;
    else cout << endl << "Failed to add new course. Maximum limit reached." << endl;
    pauseScreen();
}