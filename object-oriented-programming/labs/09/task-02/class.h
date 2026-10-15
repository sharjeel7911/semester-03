#include "../main.h"

class VehicleX {
protected:
    int m_regNum;
    char* m_brand;
public:
    VehicleX();
    VehicleX(const char*, int);
    virtual ~VehicleX();
    virtual void display() = 0; //pure virtual function
};

class CarX :public VehicleX {
public:
    CarX();
    CarX(const char* brand, int regNum);
    void display() override;
};