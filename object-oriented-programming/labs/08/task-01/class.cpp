#include "class.h"

Passport::Passport(int passportNumber, const string& nationality) : m_passportNumber(passportNumber), m_nationality(nationality) {}

void Passport::setPassportNumber(int passportNumber) {
    m_passportNumber = passportNumber;
}

int Passport::getPassportNumber() const {
    return m_passportNumber;
}

void Passport::setNationality(const string& nationality) {
    m_nationality = nationality;
}

string Passport::getNationality() const {
    return m_nationality;
}

void Passport::display() const {
    cout << "Passport Number: " << getPassportNumber() << endl;
    cout << "Nationality : " << getNationality() << endl;
}

/*_____________________________________________________________________________________________________________________________________*/

Person::Person(const string& name, Passport* passport) : m_name(name), m_passport(passport) {}

void Person::setName(const string& name) {
    m_name = name;
}

string Person::getName() const {
    return m_name;
}

void Person::setPassport(Passport* passport) {
    m_passport = passport;
}

Passport* Person::getPassport() const {
    return m_passport;
}

void Person::display() const {
    cout << "Name: " << getName() << endl;
    if (m_passport != nullptr) m_passport->display();
    else cout << "No passport information available." << endl;
}