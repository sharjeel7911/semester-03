#include "../main.h"

class Person;
class Passport;

class Passport {
private:
    int m_passportNumber;
    string m_nationality;
public:
    Passport(int passportNumber = 0, const string& nationality = "");
    void setPassportNumber(int passportNumber);
    int getPassportNumber() const;
    void setNationality(const string& nationality);
    string getNationality() const;
    void display() const;
};

class Person {
private:
    Passport* m_passport;
    string m_name;
public:
    Person(const string& name = "", Passport* passport = nullptr);
    void setName(const string& name);
    string getName() const;
    void setPassport(Passport* passport);
    Passport* getPassport() const;
    void display() const;
};