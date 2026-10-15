#include "../main.h"

class Employee {
protected:
    char* m_name;
    int m_id;
    double m_salary;
public:
    Employee(const char* name = nullptr, int id = 0, double salary = 0.0);
    virtual ~Employee();
    virtual void display() = 0;
};

class Manager :protected Employee {
private:
    int m_teamSize;
    double m_budget;
public:
    Manager(int teamSize = 0, double budget = 0, const char* name = nullptr, int id = 0, double salary = 0.0);
    void display() override;
};