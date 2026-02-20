#include "class.h"

Animal::Animal(const char* name, int age) {
    if (name == nullptr) {
        m_name = nullptr;
        return;
    }
    int size = 0;
    while (name[size] != '\0') size++;
    m_name = new char[size + 1];
    for (int i = 0; i < size; i++) m_name[i] = name[i];
    m_name[size] = '\0';

    m_age = age;
}

Animal::~Animal() {
    delete[] m_name;
}

void Animal::display() {
    cout << "Animal object created" << endl;
}

Cat::Cat(const char* name, int age) : Animal(name, age) {}

void Cat::display() {
    cout << "Cat object created" << endl;
}