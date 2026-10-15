#include "main.h"

//g++ main.cpp task-01/*.cpp task-02/*.cpp task-03/*.cpp task-04/*.cpp task-05/*.cpp -o x && ./x

void task01();
void task02();
void task03();
void task04();
void task05();

int main() {
    int choice;
    do {
        clearScreen();
        cout << "                                  ***  Menu  *** " << endl;
        cout << "1. Task - 01" << "                       2. Task - 02" << "                   3. Task - 03" << endl;
        cout << "4. Task - 04" << "                       5. Task - 05" << "                   0. Exit" << endl;
        cout << endl << "Enter your choice (1 - 5): ";
        cin >> choice;
        switch (choice) {
        case 1:
            task01();
            break;
        case 2:
            task02();
            break;
        case 3:
            task03();
            break;
        case 4:
            task04();
            break;
        case 5:
            task05();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 7" << endl;
            pauseScreen();
            break;
        }
    } while (choice != 0);
    return 0;
}