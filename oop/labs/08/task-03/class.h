#include "../main.h"

class Student {
private:
    int m_id;
    string m_name;
public:
    Student(int id = 0, const string& name = "");

    void setId(int id);
    int getId() const;
    void setName(const string& name);
    string getName() const;
    void displayStudent() const;
};

class Club {
private:
    string m_clubName;
public:
    Club(const string& clubName = "");

    void setClubName(const string& clubName);
    string getClubName() const;
    void displayClub() const;
};

class Membership {
private:
    Student* m_student;
    Club* m_club;
public:
    Membership(Student* student = nullptr, Club* club = nullptr);

    void setStudent(Student* student);
    Student* getStudent() const;
    void setClub(Club* club);
    Club* getClub() const;
    void displayMembership() const;
};