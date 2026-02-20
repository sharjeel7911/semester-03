#include "../main.h"

class Shape {
protected:
    char* m_color;
    int m_sides;
public:
    Shape(const char* color = nullptr, int sides = 0);
    virtual ~Shape();
    virtual void area() = 0;
    virtual void display();
};

class Circle : public Shape {
private:
    float m_radius;
public:
    Circle(const char* color = nullptr, float radius = 0.0f);
    void area() override;
    void display() override;
};

class Rectangle : public Shape {
private:
    float m_length;
    float m_width;
public:
    Rectangle(const char* color = nullptr, float length = 0.0f, float width = 0.0f);
    void area() override;
    void display() override;
};