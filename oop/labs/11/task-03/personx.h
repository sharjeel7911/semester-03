#include "../main.h"

class Personx {
protected:
    char* m_name;
    int m_age;

public:
    Personx(const char* name = nullptr, int age = 0);
    virtual ~Personx();
    virtual void display();
};

class Studentx : virtual public Personx {
protected:
    char* m_section;
public:
    Studentx(const char* name = nullptr, int age = 0, const char* section = nullptr);
    ~Studentx();
    void display() override;
};

class Teacherx : virtual public Personx {
protected:
    char* m_subject;
public:
    Teacherx(const char* name = nullptr, int age = 0, const char* subject = nullptr);
    ~Teacherx();

    void display() override;
};

class TAx : public Studentx, public Teacherx {
public:
    TAx(const char* name = nullptr, int age = 0);
    ~TAx();
    void display() override;
};