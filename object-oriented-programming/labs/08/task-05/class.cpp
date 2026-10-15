#include "class.h"

Engine::Engine(const string& type, int horsepower) : m_type(type), m_horsepower(horsepower) {}

void Engine::displayEngine() const {
    cout << "Engine Type: " << m_type << endl << "Horsepower: " << m_horsepower << endl;
}

/*_________________________________________________________________________________________________________________________*/

Car::Car(const string& type, int horsepower) {
    m_engine = new Engine(type, horsepower);
}

Car::~Car() {
    delete m_engine;
}

void Car::displayCar() const {
    if (m_engine) {
        cout << "Car Details:" << endl;
        m_engine->displayEngine();
    } else cout << "No engine information available." << endl;
}