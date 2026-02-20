#include "personx.h"

Personx::Personx(const char* name, int age) {
    if (name) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    } else {
        m_name = new char[8];
        strcpy(m_name, "Unknown");
    }

    m_age = age;
}

Personx::~Personx() {
    delete[] m_name;
}

void Personx::display() {
    cout << "Name: " << m_name << endl;
    cout << "Age: " << m_age << endl;
}

/*_____________________________________________________________________________________________________ */

Studentx::Studentx(const char* name, int age, const char* section) : Personx(name, age) {
    if (section) {
        m_section = new char[strlen(section) + 1];
        strcpy(m_section, section);
    } else {
        m_section = new char[8];
        strcpy(m_section, "Not Assigned");
    }
}

Studentx::~Studentx() {
    delete[] m_section;
}

void Studentx::display() {
    cout << "Student\n";
    Personx::display();
    cout << "Section: " << m_section << endl;
}

/*_____________________________________________________________________________________________________ */

Teacherx::Teacherx(const char* name, int age, const char* subject) : Personx(name, age) {
    if (subject) {
        m_subject = new char[strlen(subject) + 1];
        strcpy(m_subject, subject);
    } else {
        m_subject = new char[8];
        strcpy(m_subject, "Unknown");
    }
}

Teacherx::~Teacherx() {
    delete[] m_subject;
}

void Teacherx::display() {
    cout << "Teacher\n";
    Personx::display();
    cout << "Subject: " << m_subject << endl;
}

/*_____________________________________________________________________________________________________ */

TAx::TAx(const char* name, int age) : Personx(name, age), Studentx(name, age), Teacherx(name, age) {}

TAx::~TAx() {}

void TAx::display() {
    cout << "Teaching Assistant\n";
    Personx::display();
}