#include "smart-home.h"

Device::Device(int id) : m_id(id) {}

void Device::turnOn() {
    cout << "Device " << m_id << " is turned ON." << endl;
}

void Device::turnOff() {
    cout << "Device " << m_id << " is turned OFF." << endl;
}

//__________________________________________________________________

Light::Light(int id, int brightness) : Device(id), m_brightness(brightness) {}

void Light::turnOn() {
    cout << "Light " << m_id << " is turned ON with brightness " << m_brightness << "." << endl;
}

void Light::turnOff() {
    cout << "Light " << m_id << " is turned OFF." << endl;
}

//__________________________________________________________________

Thermostat::Thermostat(int id, float temperature) : Device(id), m_temperature(temperature) {}

void Thermostat::turnOn() {
    cout << "Thermostat " << m_id << " is turned ON with temperature set to " << m_temperature << "°C." << endl;
}

void Thermostat::turnOff() {
    cout << "Thermostat " << m_id << " is turned OFF." << endl;
}

//__________________________________________________________________

Home::Home(Device** devices, int deviceCount) : m_devices(nullptr), m_deviceCount(0) {
    if (deviceCount > 0 && devices != nullptr) {
        m_deviceCount = deviceCount;
        m_devices = new Device * [m_deviceCount];
        for (int i = 0; i < m_deviceCount; ++i) {
            m_devices[i] = devices[i];
        }
    }
}

Home::~Home() {
    delete[] m_devices;
}

void Home::addDevice(Device* device) {
    Device** newDevices = new Device * [m_deviceCount + 1];
    for (int i = 0; i < m_deviceCount; ++i) {
        newDevices[i] = m_devices[i];
    }
    newDevices[m_deviceCount] = device;
    delete[] m_devices;
    m_devices = newDevices;
    ++m_deviceCount;
}

void Home::controlDevices() {
    for (int i = 0; i < m_deviceCount; ++i) {
        m_devices[i]->turnOn();
    }
    cout << "All devices are now ON." << endl;
    for (int i = 0; i < m_deviceCount; ++i) {
        m_devices[i]->turnOff();
    }
    cout << "All devices are now OFF." << endl;
}