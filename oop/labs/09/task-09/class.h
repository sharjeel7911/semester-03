#include "../main.h"

class Vehicle {
protected:
    int m_regNum;
    char* m_brand;
public:
    Vehicle(const char*, int);
    virtual ~Vehicle();
    virtual void display();
};

class RoadVehicle :public Vehicle {
protected:
    int m_noOfWheels;
public:
    RoadVehicle(const char*, int, int);
    void display() override;
};

class Car :public RoadVehicle {
private:
    char* m_color;
    int m_miles;
public:
    Car(const char*, int, char*, int);
    ~Car();
    void display() override;
};
