#include "main.h"

class Student {
private:
    int m_id;
    string m_name;
    int m_age;
    double m_gpa;

    int m_UNIQUE_ID;
    static int m_TOTAL_STUDENTS;

public:
    Student(const string& name = "", int id = 0, int age = 0, float gpa = 0.0);
    ~Student();

    Student(const Student&);
    Student& operator=(const Student&);

    // Setters
    void setName(const string& name);
    void setId(int id);
    void setAge(int age);
    void setGpa(float gpa);

    // Getters
    int getId() const;
    string getName() const;
    int getAge() const;
    double getGpa() const;
    int getUniqueId() const;

    void toCsv() const;

    friend void searchById();
    friend void searchByName();
    friend ostream& operator<<(ostream&, const Student&);
    friend istream& operator>>(istream&, Student&);
};