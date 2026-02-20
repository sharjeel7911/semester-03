#include "../main.h"

class Teacher {
protected:
    char* m_name;
    char* m_subject;
public:
    Teacher(const char* name = nullptr, const char* subject = nullptr);
    virtual ~Teacher();
    virtual void display();
};

class Researcher {
protected:
    char* m_researchArea;
    int m_publications;
public:
    Researcher(const char* area = nullptr, int publications = 0);
    virtual ~Researcher();
    virtual void display();
};

class Professor :public Teacher, public Researcher {
private:
    char* m_department;
    int m_load;
public:
    Professor(const char* name = nullptr, const char* subject = nullptr, const char* area = nullptr, int publications = 0, const char* department = nullptr, int load = 0);
    ~Professor();
    void display() override;
};