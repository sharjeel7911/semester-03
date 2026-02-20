#include "shape.h"

Shape::Shape(const char* color, int sides) : m_sides(sides) {
    if (color) {
        m_color = new char[strlen(color) + 1];
        strcpy(m_color, color);
    } else {
        m_color = new char[1];
        m_color[0] = '\0';
    }
}

Shape::~Shape() {
    delete[] m_color;
}

void Shape::display() {
    cout << "Color: " << m_color << ", Sides: " << m_sides << endl;
}

/*____________________________________________________________________________________________*/

Circle::Circle(const char* color, float radius) : Shape(color, 0), m_radius(radius) {}

void Circle::area() {
    float area = 3.14159f * m_radius * m_radius;
    cout << "Circle Area: " << area << endl;
}

void Circle::display() {
    Shape::display();
    cout << "Shape: Circle, Radius: " << m_radius << endl;
}

/*____________________________________________________________________________________________*/

Rectangle::Rectangle(const char* color, float length, float width) : Shape(color, 4), m_length(length), m_width(width) {}

void Rectangle::area() {
    float area = m_length * m_width;
    cout << "Rectangle Area: " << area << endl;
}

void Rectangle::display() {
    Shape::display();
    cout << "Shape: Rectangle, Length: " << m_length << ", Width: " << m_width << endl;
}