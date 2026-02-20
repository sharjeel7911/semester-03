#include "class.h"

Appliance::Appliance(const char* brand, char* color, const char* type)
    : m_color(color), m_type(type)  // initialize const pointers
{
    if (brand) {
        int len = strlen(brand);
        char* temp = new char[len + 1];
        strcpy(temp, brand);
        m_brand = temp;  // deep copy, pointer can change but content is const
    } else m_brand = nullptr;
}

Appliance::~Appliance() {
    delete[] m_brand;
}

void Appliance::showAttributes() {
    cout << "Brand: " << (m_brand ? m_brand : "N/A") << endl;
    cout << "Color: " << (m_color ? m_color : "N/A") << endl;
    cout << "Type: " << (m_type ? m_type : "N/A") << endl;
}

/*________________________________________________________________________________________________________________*/

AirConditioner::AirConditioner(double price, int warranty, const char* brand, char* color, const char* type) : Appliance(brand, color, type), m_price(price), m_warranty(warranty) {}

void AirConditioner::display() {
    cout << "Air Conditioner Details:" << endl;

    cout << "Brand: " << (m_brand ? m_brand : "N/A") << " (deep copied, content can't change)" << endl;
    cout << "Color: " << (m_color ? m_color : "N/A") << " (pointer const, content can change)" << endl;
    cout << "Type: " << (m_type ? m_type : "N/A") << " (pointer & content const)" << endl;
    cout << "Price: Rs. " << m_price << endl;
    cout << "Warranty: " << m_warranty << " months" << endl;
}