#include "../main.h"

class Vehicle {
protected:
    double m_fuelCapacity;
    double m_distanceTraveled;
public:
    Vehicle(double fuelCapacity = 0.0, double distanceTraveled = 0.0);
    virtual double calculateFuelEfficiency();
    virtual void display();
};

class Car :public Vehicle {
private:
    int m_maxSpeed;
    int m_speed;
public:
    Car(int maxSpeed = 0, int speed = 0, double fuelCapacity = 0.0, double distanceTraveled = 0.0);
    double calculateFuelEfficiency();
    void display();
};

class Truck : public Vehicle {
private:
    int m_payLoadCapacity;
public:
    Truck(int payloadCapacity = 0, double fuelCapacity = 0.0, double distanceTraveled = 0.0);
    double calculateFuelEfficiency();
    void display();
};