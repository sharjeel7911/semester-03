#include "../main.h"

class Animal {
private:
    char* m_name;
    int m_age;
public:
    Animal(const char* name = nullptr, int age = 0);
    virtual ~Animal();
    virtual void display();
    virtual void makeSound();
};

class Cat :public Animal {
public:
    Cat(const char* name = nullptr, int age = 0);
    void display();
    void makeSound();
};

class Dog :public Animal {
public:
    Dog(const char* name = nullptr, int age = 0);
    void display();
    void makeSound();
};