#include "../main.h"

class Teacher {
protected:
    string m_name;
    int m_age;
    string m_qualification;
    int m_noOfStudents;
public:
    Teacher(const string& name = "", int age = 0, string qualification = "", int noOfStudents = 0);
    virtual void display();
};

class PermanentTeacher : public Teacher {
private:
    double m_salary;
public:
    PermanentTeacher(const string& name = "", int age = 0, string qualification = "", int noOfStudents = 0, double salary = 0.0);
    void display() override;
};

class VisitingTeacher : public Teacher {
private:
    double m_hourlyRate;
    int m_hoursWorked;
public:
    VisitingTeacher(const string& name = "", int age = 0, string qualification = "", int noOfStudents = 0, double hourlyRate = 0.0, int hoursWorked = 0);
    void display() override;
};