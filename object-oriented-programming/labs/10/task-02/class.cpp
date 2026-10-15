#include "class.h"

Animal::Animal(const char* name, int age) {
    if (name) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    } else m_name = nullptr;

    m_age = age;
}

Animal::~Animal() {
    delete[] m_name;
}

void Animal::display() {
    cout << "Name: " << (m_name ? m_name : "Unknown") << endl << "Age: " << m_age << endl;
}

void Animal::makeSound() {
    cout << "Base class: Animal" << endl;
}

/*______________________________________________________________________________________________*/

Cat::Cat(const char* name, int age) : Animal(name, age) {}

void Cat::display() {
    cout << "Cat Details" << endl;
    Animal::display();
}

void Cat::makeSound() {
    cout << "Derived class: Cat" << endl;
}

/*______________________________________________________________________________________________*/

Dog::Dog(const char* name, int age) : Animal(name, age) {}

void Dog::display() {
    cout << "Dog Details" << endl;
    Animal::display();
}

void Dog::makeSound() {
    cout << "Derived class: Dog" << endl;
}