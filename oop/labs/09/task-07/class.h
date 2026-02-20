#include "../main.h"

class ElectronicDevice {
protected:
    char* m_brand;
    int m_warranty;
public:
    ElectronicDevice(const char* brand = nullptr, int warranty = 0);
    virtual ~ElectronicDevice();
    virtual void display();
};

class SmartDevice :public ElectronicDevice {
protected:
    bool m_isBatterySupport;
public:
    SmartDevice(const char* brand = nullptr, int warranty = 0, bool isBatterySupport = 0);
    void display() override;
};

class SmartPhone :public SmartDevice {
private:
    int m_storage;
    float m_resolution;
    double m_price;
public:
    SmartPhone(const char* brand = nullptr, int warranty = 0, bool isBatterySupport = 0, int storage = 0, float resolution = 0.0, double price = 0.0);
    void display() override;
};