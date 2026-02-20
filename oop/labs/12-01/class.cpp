#include "class.h"

Employee::Employee(int id, const string& name) : m_id(id), m_name(name) {}

void Employee::displayEmployee() const {
	cout << "Employee Name: " << m_name << endl;
	cout << "Employee Id: " << m_id << endl;
}

/*__________________________________________________________________*/

Company::Company() {
	cout << "Company created.." << endl;
}

void Company::assignEmployee(Employee* employee) {
	cout << "Employee Assigned: " << endl;
	employee->displayEmployee();
}
