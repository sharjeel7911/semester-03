#include "../main.h"

class EmployeeX {
protected:
    char* m_name;
    int m_id;
    double m_salary;
public:
    EmployeeX(const char* name = nullptr, int id = 0, double salary = 0.0);
    virtual ~EmployeeX();
    virtual void display() = 0;
};

class ManagerX :private EmployeeX {
private:
    int m_teamSize;
    double m_budget;
public:
    ManagerX(int teamSize = 0, double budget = 0, const char* name = nullptr, int id = 0, double salary = 0.0);
    void display() override;
};