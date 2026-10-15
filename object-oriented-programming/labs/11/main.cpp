#include "main.h"

//g++ main.cpp task-01/*.cpp task-02/*.cpp task-03/*.cpp task-04/*.cpp task-05/*.cpp -o x && ./x

void vehicle();
void person();
void personVirtual();
void shape();
void bank();

int main() {
    int choice;
    do {
        clearScreen();
        cout << "                                        ***  Menu  *** " << endl;
        cout << "1. Vehicle                               2. Person                     3. Person (Virtual)" << endl;
        cout << "4. Shape                                 5. Bank                       0. Exit" << endl;
        cout << endl << "Enter your choice (1 - 5): ";
        cin >> choice;
        switch (choice) {
        case 1:
            vehicle();
            break;
        case 2:
            person();
            break;
        case 3:
            personVirtual();
            break;
        case 4:
            shape();
            break;
        case 5:
            bank();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5" << endl;
            pauseScreen();
            break;
        }
    } while (choice != 0);
    return 0;
}