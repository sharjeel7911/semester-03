#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	int m_id;
	string m_name;
public:
	Employee(int id, const string& name);
	void displayEmployee() const;
};

class Company {
public:
	Company();
	void assignEmployee(Employee* employee);
};