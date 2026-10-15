#include "../main.h"

class Appliance {
protected:
    const char* m_brand;       // cannot modify the string, pointer can change
    char* const m_color;       // pointer cannot change, string can be modified, (Compiler will probably give warning as passing a string to simple char* is forbidden. You should use const char* but it is done here for understanding)
    const char* const m_type;  // pointer and string content cannot change

public:
    Appliance(const char* brand = nullptr, char* color = nullptr, const char* type = nullptr);
    virtual ~Appliance();
    void showAttributes();
    virtual void display() = 0;
};

class AirConditioner :public Appliance {
private:
    double m_price;
    int m_warranty;
public:
    AirConditioner(double price = 0, int warranty = 0, const char* brand = nullptr, char* color = nullptr, const char* type = nullptr);
    void display() override;
};