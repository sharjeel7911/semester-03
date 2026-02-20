#include "../main.h"

class Engine {
private:
    string m_type;
    int m_horsepower;
public:
    Engine(const string& type = "", int horsepower = 0);
    void displayEngine() const;
};

class Car {
private:
    Engine* m_engine;
public:
    Car(const string& type, int horsepower);
    ~Car();
    void displayCar() const;
};