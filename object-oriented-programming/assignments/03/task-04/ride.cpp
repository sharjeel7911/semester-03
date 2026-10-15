#include "ride.h"

Vehicle::Vehicle(int vehicleNumber) : m_vehicleNumber(vehicleNumber) {}

//_________________________________________________________________________

Car::Car(int seatCount, int vehicleNumber) : Vehicle(vehicleNumber), m_seatCount(seatCount) {}

void Car::calculateFare() {
    double fare = m_seatCount * 10.0;
    cout << "Car Fare for vehicle number " << m_vehicleNumber << " with " << m_seatCount << " seats is: Rs." << fare << endl;
}

//_________________________________________________________________________

Bike::Bike(int seatCount, int vehicleNumber) : Vehicle(vehicleNumber), m_seatCount(seatCount) {}

void Bike::calculateFare() {
    double fare = m_seatCount * 5.0;
    cout << "Bike Fare for vehicle number " << m_vehicleNumber << " with " << m_seatCount << " seats is: Rs." << fare << endl;
}

//_________________________________________________________________________

Driver::Driver(int driverID) : m_driverID(driverID) {}

void Driver::acceptRide() {
    cout << "Driver with ID " << m_driverID << " has accepted the ride." << endl;
}