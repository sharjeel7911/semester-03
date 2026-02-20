#include "class.h"

Employee::Employee(const char* name, int id, double salary)
    : m_id(id), m_salary(salary) {
    if (name) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    } else m_name = nullptr;

}

Employee::~Employee() {
    delete[] m_name;
}

/*____________________________________________________________________________________________________________________________*/

Manager::Manager(int teamSize, double budget, const char* name, int id, double salary) : Employee(name, id, salary), m_teamSize(teamSize), m_budget(budget) {}

void Manager::display() {
    cout << "Name: " << m_name << "\n" << "ID: " << m_id << "\n" << "Salary: " << m_salary << "\n" << "Team Size: " << m_teamSize << "\n" << "Budget: " << m_budget << endl;
}