#include "../main.h"

class Animal {
private:
    char* m_name;
    int m_age;
public:
    Animal(const char* name = nullptr, int age = 0);
    virtual ~Animal();
    virtual void display();
};

class Cat :public Animal {
public:
    Cat(const char* name = nullptr, int age = 0);
    void display();
};