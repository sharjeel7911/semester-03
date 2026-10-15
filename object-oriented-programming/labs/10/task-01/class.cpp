#include "class.h"

Person::Person(const char* name, int age) {
    if (name) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    } else m_name = nullptr;

    m_age = age;
}

Person::~Person() {
    delete[] m_name;
}

void Person::display() {
    cout << "Name: " << (m_name ? m_name : "N/A") << endl;
    cout << "Age: " << m_age << endl;
}

/*_________________________________________________________________________________________________________________*/

Employee::Employee(const char* dept, int id, const char* name, int age) : Person(name, age) {
    if (dept) {
        m_dept = new char[strlen(dept) + 1];
        strcpy(m_dept, dept);
    } else m_dept = nullptr;

    m_id = id;
}

Employee::~Employee() {
    delete[] m_dept;
}

void Employee::display() {
    Person::display();
    cout << "Department: " << (m_dept ? m_dept : "N/A") << endl;
    cout << "ID: " << m_id << endl;
}

/*_________________________________________________________________________________________________________________*/

Manager::Manager(int teamSize, const char* dept, int id, const char* name, int age) : Employee(dept, id, name, age) {
    m_teamSize = teamSize;
}

void Manager::display() {
    Employee::display();
    cout << "Team Size: " << m_teamSize << endl;
}