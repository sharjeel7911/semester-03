#include "../main.h"

class Vehicle {
protected:
    int m_vehicleNumber;
public:
    Vehicle(int vehicleNumber = 0);
    virtual void calculateFare() = 0;
};

class Car :public Vehicle {
private:
    int m_seatCount;
public:
    Car(int seatCount = 0, int vehicleNumber = 0);
    void calculateFare();
};

class Bike :public Vehicle {
private:
    int m_seatCount;
public:
    Bike(int seatCount = 0, int vehicleNumber = 0);
    void calculateFare();
};

class Driver {
private:
    int m_driverID;
public:
    Driver(int driverID = 0);
    void acceptRide();
};