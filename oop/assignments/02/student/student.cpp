#include "student.h"

int Student::m_TOTAL_STUDENTS = 0;

// Constructor
Student::Student(const string& name, int rollNo, int age, float gpa)
    : m_UNIQUE_ID(++m_TOTAL_STUDENTS), m_id(rollNo), m_age(age), m_gpa(gpa) {
    m_name = name;
}

// Destructor
Student::~Student() {}

// Copy Constructor
Student::Student(const Student& obj)
    : m_UNIQUE_ID(++m_TOTAL_STUDENTS), m_id(obj.m_id),
    m_name(obj.m_name), m_age(obj.m_age), m_gpa(obj.m_gpa) {
}

// Assignment Operator
Student& Student::operator=(const Student& obj) {
    if (this != &obj) {
        m_id = obj.m_id;
        m_name = obj.m_name;
        m_age = obj.m_age;
        m_gpa = obj.m_gpa;
    }
    return *this;
}

// Setters with validation
void Student::setName(const string& name) {
    string clean;
    int letterCount = 0;

    for (char ch : name) {
        if (isalpha(ch) || ch == ' ') {
            clean += ch;
            if (isalpha(ch)) letterCount++;
        }
    }

    while (letterCount < 3) {
        cout << "Invalid name! Enter again (at least 3 letters): ";
        string temp;
        getline(cin, temp);
        clean.clear();
        letterCount = 0;
        for (char ch : temp) {
            if (isalpha(ch) || ch == ' ') {
                clean += ch;
                if (isalpha(ch)) letterCount++;
            }
        }
    }

    m_name = clean;
}

void Student::setId(int id) {
    while (id <= 0) {
        cout << "Invalid ID (must be > 0). Enter again: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    m_id = id;
}

void Student::setAge(int age) {
    while (age < 16 || age > 25) {
        cout << "Invalid age (must be between 16 and 25). Enter again: ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    m_age = age;
}

void Student::setGpa(float gpa) {
    while (gpa < 0.0 || gpa > 4.0) {
        cout << "Invalid GPA (0.0-4.0). Enter again: ";
        cin >> gpa;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    m_gpa = gpa;
}

// Getters
int Student::getId() const {
    return m_id;
}

string Student::getName() const {
    return m_name;
}

int Student::getAge() const {
    return m_age;
}

double Student::getGpa() const {
    return m_gpa;
}

int Student::getUniqueId() const {
    return m_UNIQUE_ID;
}

// Save to CSV
void Student::toCsv() const {
    ofstream write("students.csv", ios::app);
    if (!write) {
        cout << "Error opening CSV file!" << endl;
        return;
    }
    write << m_UNIQUE_ID << "," << m_id << "," << m_name << ","
        << m_age << "," << fixed << setprecision(2) << m_gpa << endl;
    write.close();
}

// Input operator
istream& operator>>(istream& in, Student& obj) {
    string name;
    int id, age;
    float gpa;

    // Clear any leftover input buffer first
    if (in.peek() == '\n') {
        in.ignore();
    }

    cout << "Enter student's name: ";
    getline(in, name);
    obj.setName(name);

    cout << "Enter roll number: ";
    in >> id;
    obj.setId(id);

    cout << "Enter age: ";
    in >> age;
    obj.setAge(age);

    cout << "Enter GPA: ";
    in >> gpa;
    obj.setGpa(gpa);

    return in;
}

// Output operator
ostream& operator<<(ostream& out, const Student& obj) {
    out << "Name: " << obj.m_name << endl;
    out << "Roll Number: " << obj.m_id << endl;
    out << "Age: " << obj.m_age << endl;
    out << "GPA: " << fixed << setprecision(2) << obj.m_gpa;
    return out;
}