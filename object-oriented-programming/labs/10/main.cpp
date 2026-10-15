#include "main.h"

//g++ main.cpp task-01/*.cpp task-02/*.cpp task-03/*.cpp -o x && ./x

void person();
void animal();
void teacher();

int main() {
    int choice;
    do {
        clearScreen();
        cout << "                                        ***  Menu  *** " << endl;
        cout << "1. Person                               2. Animal                     3. Teacher" << endl;
        cout << "                                        0. Exit" << endl;
        cout << endl << "Enter your choice (1 - 3): ";
        cin >> choice;
        switch (choice) {
        case 1:
            person();
            break;
        case 2:
            animal();
            break;
        case 3:
            teacher();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3" << endl;
            pauseScreen();
            break;
        }
    } while (choice != 0);
    return 0;
}