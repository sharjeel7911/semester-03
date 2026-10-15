#include "main.h"

//g++ main.cpp task-01/*.cpp task-02/*.cpp task-03/*.cpp task-04/*.cpp task-05/*.cpp task-06/*.cpp task-07/*.cpp task-08/*.cpp task-09/*.cpp task-10/*.cpp -o x && ./x

void animal();
void vehicle();
void shape();
void appliance();
void employee();
void employeeX();
void elecDevice();
void shapes();
void vehicles();
void professor();

int main() {
    int choice;
    do {
        clearScreen();
        cout << "                                        ***  Menu  *** " << endl;
        cout << "1. Animal                               2. Vehicle                     3. Shape" << endl;
        cout << "4. Appliance                            5. Employee (protected)        6. Employee (private)" << endl;
        cout << "7. Eletronic Device                     8. Shapes                      9.Vehicles" << endl;
        cout << "10. Professor                                                          0. Exit" << endl;
        cout << endl << "Enter your choice (1 - 10): ";
        cin >> choice;
        switch (choice) {
        case 1:
            animal();
            break;
        case 2:
            vehicle();
            break;
        case 3:
            shape();
            break;
        case 4:
            appliance();
            break;
        case 5:
            employee();
            break;
        case 6:
            employeeX();
            break;
        case 7:
            elecDevice();
            break;
        case 8:
            shapes();
            break;
        case 9:
            vehicles();
            break;
        case 10:
            professor();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 10" << endl;
            pauseScreen();
            break;
        }
    } while (choice != 0);
    return 0;
}