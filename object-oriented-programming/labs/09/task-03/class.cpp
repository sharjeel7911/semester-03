#include "class.h"

ShapeX::ShapeX(const char* color, int sides) : m_sides(sides) {
    if (color) {
        int len = strlen(color);
        m_color = new char[len + 1];
        strcpy(m_color, color);
    } else {
        m_color = nullptr;
    }
}

ShapeX::~ShapeX() {
    delete[] m_color;
}

/*___________________________________________________________________________________________________________________*/

RectangleX::RectangleX(double length, double width, const char* color) : ShapeX(color, 4), m_length(length), m_width(width) {}

double RectangleX::area() {
    return m_length * m_width;
}

void RectangleX::display() {
    cout << "Rectangle Details:" << endl;
    cout << "Color: " << (m_color ? m_color : "N/A") << endl;
    cout << "Sides: " << m_sides << endl;
    cout << "Length: " << m_length << ", Width: " << m_width << endl;
    cout << "Area: " << area() << endl;
}