#include "../main.h"

class Shape {
protected:
    char* m_color;

public:
    Shape(const char* color = nullptr);
    virtual ~Shape();

    virtual void display();
};

class TwoDShape : public Shape {
protected:
    int m_sides;

public:
    TwoDShape(const char* color = nullptr, int sides = 0);
    void display() override;
};

class Rectangle : public TwoDShape {
private:
    double m_length;
    double m_width;

public:
    Rectangle(const char* color = nullptr, int sides = 4, double length = 0, double width = 0);

    double calculateArea();
    double calculatePerimeter();
    void display() override;
};