#include "class.h"

ElectronicDevice::ElectronicDevice(const char* brand, int warranty) {
    m_warranty = warranty;
    if (brand) {
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);
    } else {
        m_brand = nullptr;
    }
}

ElectronicDevice::~ElectronicDevice() {
    delete[] m_brand;
}

void ElectronicDevice::display() {
    cout << "Brand: " << (m_brand ? m_brand : "Unknown") << endl;
    cout << "Warranty: " << m_warranty << " months" << endl;
}

/*____________________________________________________________________________________________________________________________*/

SmartDevice::SmartDevice(const char* brand, int warranty, bool isBatterySupport) : ElectronicDevice(brand, warranty), m_isBatterySupport(isBatterySupport) {}

void SmartDevice::display() {
    ElectronicDevice::display();
    cout << "Battery Support: " << (m_isBatterySupport ? "Yes" : "No") << endl;
}

/*____________________________________________________________________________________________________________________________*/

SmartPhone::SmartPhone(const char* brand, int warranty, bool isBatterySupport, int storage, float resolution, double price) : SmartDevice(brand, warranty, isBatterySupport), m_storage(storage), m_resolution(resolution), m_price(price) {}

void SmartPhone::display() {
    SmartDevice::display();
    cout << "Storage: " << m_storage << " GB" << endl;
    cout << "Resolution: " << m_resolution << " MP" << endl;
    cout << "Price: Rs. " << m_price << endl;
}