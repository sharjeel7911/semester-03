#include "../main.h"

class Device {
protected:
    int m_id;
public:
    Device(int id = 0);
    virtual void turnOn();
    virtual void turnOff();
};

class Light : public Device {
private:
    int m_brightness;
public:
    Light(int id = 0, int brightness = 0);
    void turnOn() override;
    void turnOff() override;
};

class Thermostat : public Device {
private:
    float m_temperature;
public:
    Thermostat(int id = 0, float temperature = 20.0);
    void turnOn() override;
    void turnOff() override;
};

class Home {
private:
    Device** m_devices;
    int m_deviceCount;
public:
    Home(Device** devices = nullptr, int deviceCount = 0);
    ~Home();
    void addDevice(Device* device);
    void controlDevices();
};