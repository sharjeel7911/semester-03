#include "vehicle.h"

Vehicle::Vehicle(double fuelCapacity, double distanceTraveled) : m_fuelCapacity(fuelCapacity), m_distanceTraveled(distanceTraveled) {}


double Vehicle::calculateFuelEfficiency() {
    if (m_fuelCapacity == 0) return 0;
    return m_distanceTraveled / m_fuelCapacity;
}

void Vehicle::display() {
    cout << "Fuel Capacity: " << m_fuelCapacity << endl;
    cout << "Distance Traveled: " << m_distanceTraveled << endl;
    cout << "Fuel Efficiency: " << calculateFuelEfficiency() << endl;
}

/*__________________________________________________________________________________________________*/

Car::Car(int maxSpeed, int speed, double fuelCapacity, double distanceTraveled) : Vehicle(fuelCapacity, distanceTraveled), m_maxSpeed(maxSpeed), m_speed(speed) {}

double Car::calculateFuelEfficiency() {
    if (m_fuelCapacity == 0) return 0;
    double efficiency = m_distanceTraveled / m_fuelCapacity;

    //increase efficiency by 4 if speed is within max limit
    if (m_speed <= m_maxSpeed) efficiency += 4;
    return efficiency;
}

void Car::display() {
    cout << "Car Details: " << endl;
    cout << "Max Speed: " << m_maxSpeed << endl;
    cout << "Current Speed: " << m_speed << endl;
    Vehicle::display();
}

/*__________________________________________________________________________________________________*/

Truck::Truck(int payloadCapacity, double fuelCapacity, double distanceTraveled) : Vehicle(fuelCapacity, distanceTraveled), m_payLoadCapacity(payloadCapacity) {}

double Truck::calculateFuelEfficiency() {
    if (m_fuelCapacity == 0) return 0;
    double efficiency = m_distanceTraveled / m_fuelCapacity;

    //decrease efficiency by 7% if payload > 30 tons
    if (m_payLoadCapacity > 30) efficiency *= 0.93;
    return efficiency;
}

void Truck::display() {
    cout << "Truck Details: " << endl;
    cout << "Payload Capacity: " << m_payLoadCapacity << " tons" << endl;
    Vehicle::display();
}