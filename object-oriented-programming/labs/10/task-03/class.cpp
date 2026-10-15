#include "class.h"

Teacher::Teacher(const string& name, int age, string qualification, int noOfStudents) : m_name(name), m_age(age), m_qualification(qualification), m_noOfStudents(noOfStudents) {}

void Teacher::display() {
    cout << "Name: " << (!m_name.empty() ? m_name : "N/A") << endl;
    cout << "Age: " << m_age << endl;
    cout << "Qualification: " << m_qualification << endl;
    cout << "Number of Students: " << m_noOfStudents << endl;
}

/*_______________________________________________________________________________________________________________*/

PermanentTeacher::PermanentTeacher(const string& name, int age, string qualification, int noOfStudents, double salary) : Teacher(name, age, qualification, noOfStudents), m_salary(salary) {}

void PermanentTeacher::display() {
    Teacher::display();
    cout << "Salary: Rs. " << m_salary << endl;
}

/*_______________________________________________________________________________________________________________*/

VisitingTeacher::VisitingTeacher(const string& name, int age, string qualification, int noOfStudents, double hourlyRate, int hoursWorked) : Teacher(name, age, qualification, noOfStudents), m_hourlyRate(hourlyRate), m_hoursWorked(hoursWorked) {}

void VisitingTeacher::display() {
    Teacher::display();
    cout << "Hourly Rate: Rs. " << m_hourlyRate << endl;
    cout << "Hours Worked: " << m_hoursWorked << endl;
}