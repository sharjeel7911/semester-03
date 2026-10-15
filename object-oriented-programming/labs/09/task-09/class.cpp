#include "class.h"

Vehicle::Vehicle(const char* brand, int regNum) : m_regNum(regNum) {
    if (brand) {
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);
    } else {
        m_brand = nullptr;
    }
}

Vehicle::~Vehicle() {
    delete[] m_brand;
}

void Vehicle::display() {
    cout << "Registration Number: " << m_regNum << endl;
    cout << "Brand: " << m_brand << endl;
}

/*____________________________________________________________________________________*/

RoadVehicle::RoadVehicle(const char* brand, int regNum, int wheels) : Vehicle(brand, regNum), m_noOfWheels(wheels) {}

void RoadVehicle::display() {
    Vehicle::display();
    cout << "Number of Wheels: " << m_noOfWheels << endl;
}

/*____________________________________________________________________________________*/

Car::Car(const char* brand, int regNum, char* color, int miles) : RoadVehicle(brand, regNum, 4), m_miles(miles) {
    if (color) {
        m_color = new char[strlen(color) + 1];
        strcpy(m_color, color);
    } else {
        m_color = nullptr;
    }
}

Car::~Car() {
    delete[] m_color;
}

void Car::display() {
    RoadVehicle::display();
    cout << "Color: " << m_color << endl;
    cout << "Miles Driven: " << m_miles << endl;
}