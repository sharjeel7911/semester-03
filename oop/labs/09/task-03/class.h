#include "../main.h"

class ShapeX {
protected:
    char* m_color;
    int m_sides;
public:
    ShapeX(const char* color = nullptr, int sides = 0);
    virtual ~ShapeX();
    virtual double area() = 0;
    virtual void display() = 0;
};

class RectangleX :public ShapeX {
private:
    double m_length;
    double m_width;
public:
    RectangleX(double length = 0, double width = 0, const char* color = nullptr);
    double area() override;
    void display() override;
};
