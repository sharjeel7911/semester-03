#include "person.h"

Person::Person(const char* name, int age) {

    if (name) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    } else {
        m_name = new char[8];
        strcpy(m_name, "Unknown");
    }
    m_age = age;
}

Person::~Person() {
    delete[] m_name;
}

void Person::display() {
    cout << "Name: " << m_name << endl;
    cout << "Age: " << m_age << endl;
}

/*_____________________________________________________________________________________________________*/

Student::Student(const char* name, int age, const char* section) : Person(name, age) {
    if (section) {
        m_section = new char[strlen(section) + 1];
        strcpy(m_section, section);
    } else {
        m_section = new char[8];
        strcpy(m_section, "Not Assigned");
    }
}

Student::~Student() {
    delete[] m_section;
}

void Student::display() {
    cout << "Student" << endl;
    Person::display();
    cout << "Section: " << (m_section ? m_section : "Not Assigned") << endl;
}

/*_____________________________________________________________________________________________________*/

Teacher::Teacher(const char* name, int age, const char* subject) : Person(name, age) {
    if (subject) {
        m_subject = new char[strlen(subject) + 1];
        strcpy(m_subject, subject);
    } else {
        m_subject = new char[8];
        strcpy(m_subject, "Unknown");
    }
}

Teacher::~Teacher() {
    delete[] m_subject;
}

void Teacher::display() {
    cout << "Teacher" << endl;
    Person::display();
    cout << "Subject: " << (m_subject ? m_subject : "Not Assigned") << endl;
}

/*_____________________________________________________________________________________________________*/

TA::TA(const char* name, int age) : Student(name, age), Teacher(name, age) {
}

TA::~TA() {
}

void TA::display() {
    cout << "Teacher" << endl;
    Student::display();
    Teacher::display();
    //Person::display(); //ambiguous
}