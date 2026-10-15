#include "class.h"

Shape::Shape(const char* color) {
    if (color) {
        m_color = new char[strlen(color) + 1];
        strcpy(m_color, color);
    } else {
        m_color = nullptr;
    }
}

Shape::~Shape() {
    delete[] m_color;
}

void Shape::display() {
    cout << "Color: " << m_color << endl;
}

/*_______________________________________________________________________________________*/

TwoDShape::TwoDShape(const char* color, int sides) : Shape(color), m_sides(sides) {}

void TwoDShape::display() {
    Shape::display();
    cout << "Sides: " << m_sides << endl;
}

/*_______________________________________________________________________________________*/

Rectangle::Rectangle(const char* color, int sides, double length, double width) : TwoDShape(color, sides), m_length(length), m_width(width) {}

double Rectangle::calculateArea() {
    return m_length * m_width;
}

double Rectangle::calculatePerimeter() {
    return 2 * (m_length + m_width);
}

void Rectangle::display() {
    TwoDShape::display();
    cout << "Length: " << m_length << endl;
    cout << "Width: " << m_width << endl;
    cout << "Area: " << calculateArea() << endl;
    cout << "Perimeter: " << calculatePerimeter() << endl;
}
