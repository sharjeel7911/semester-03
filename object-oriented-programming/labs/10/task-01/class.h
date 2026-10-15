#include "../main.h"

class Person {
protected:
    char* m_name;
    int m_age;
public:
    Person(const char* name = nullptr, int age = 0);
    virtual ~Person();
    virtual void display();
};

class Employee :public Person {
protected:
    int m_id;
    char* m_dept;
public:
    Employee(const char* dept = nullptr, int id = 0, const char* name = nullptr, int age = 0);
    ~Employee();
    void display() override;
};

class Manager :public Employee {
private:
    int m_teamSize;
public:
    Manager(int teamSize = 0, const char* dept = nullptr, int id = 0, const char* name = nullptr, int age = 0);
    void display() override;
};