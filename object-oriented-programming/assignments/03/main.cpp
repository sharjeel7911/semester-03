#include "main.h"

//g++ main.cpp task-01/*.cpp task-02/*.cpp task-03/*.cpp task-04/*.cpp task-05/*.cpp -o x && ./x

void shopping();
void hospital();
void mediaFile();
void ride();
void smartHome();

int main() {
    int choice;
    do {
        clearScreen();
        cout << "                                        ***  Menu  *** " << endl;
        cout << "1. Shopping                               2. Hospital                     3. Media File" << endl;
        cout << "4. Vehicle                                 5. Smart Home                       0. Exit" << endl;
        cout << endl << "Enter your choice (1 - 5): ";
        cin >> choice;
        switch (choice) {
        case 1:
            shopping();
            break;
        case 2:
            hospital();
            break;
        case 3:
            mediaFile();
            break;
        case 4:
            ride();
            break;
        case 5:
            smartHome();
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