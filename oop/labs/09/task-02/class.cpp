#include "class.h"

VehicleX::VehicleX() {
    m_brand = nullptr;
    m_regNum = 0;
    cout << "Vehicle constructor called" << endl;
}

VehicleX::VehicleX(const char* brand, int regNum) {
    if (brand == nullptr) {
        m_brand = nullptr;
        return;
    }
    int size = 0;
    while (brand[size] != '\0') size++;
    m_brand = new char[size + 1];
    for (int i = 0; i < size; i++) m_brand[i] = brand[i];
    m_brand[size] = '\0';

    m_regNum = regNum;
}

VehicleX::~VehicleX() {
    delete[] m_brand;
}

/*
void Vehicle::display() {
    cout << "Brand: ";
    if (m_brand) cout << m_brand;
    else cout << "N/A";
    cout << ", Registration No: " << m_regNum << endl;
}
*/

/*____________________________________________________________________________________________________________________*/

CarX::CarX() : VehicleX() {
    cout << "Car constructor called" << endl;
}

CarX::CarX(const char* brand, int regNum) :VehicleX(brand, regNum) {}

void CarX::display() {
    cout << "Car Object Details" << endl;
    //Vehicle::display(); //if we don't define Vehicle::display(), we can also access protected attributes 
    cout << "Brand: ";
    if (m_brand) cout << m_brand;
    else cout << "N/A";
    cout << ", Registration No: " << m_regNum << endl;
}