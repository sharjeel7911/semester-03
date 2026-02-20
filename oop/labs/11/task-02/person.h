#include "../main.h"
//example of bad code with multiple inheritance and ambiguity
class Person {
protected:
    char* m_name;
    int m_age;
public:
    Person(const char* name = nullptr, int age = 0);
    ~Person(); //should be virtual in real applications
    void display();
};

class Student : public Person {
protected:
    char* m_section;
public:
    Student(const char* name = nullptr, int age = 0, const char* subject = nullptr);
    ~Student();
    void display();
};

class Teacher : public Person {
protected:
    char* m_subject;
public:
    Teacher(const char* name = nullptr, int age = 0, const char* subject = nullptr);
    ~Teacher();
    void display();
};

class TA : public Student, public Teacher {
public:
    TA(const char* name = nullptr, int age = 0);
    ~TA();
    void display();
};