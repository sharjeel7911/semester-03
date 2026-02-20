#include <iostream>
#include "class.h"
using namespace std;

int main() {
	Employee* employee1 = new Employee(01, "Sharjeel");
	Employee* employee2 = new Employee(02, "Ahmad");

	employee1->displayEmployee();
	employee2->displayEmployee();
	cout << endl;
	Company* company = new Company();

	company->assignEmployee(employee1);
	company->assignEmployee(employee2);

	delete company;

	cout << "\nAfter company destroyed" << endl;
	employee1->displayEmployee();
	employee2->displayEmployee();

	delete employee1;
	delete employee2;
	return 0;
}