#include "class.h"

Student::Student(int id, const string& name) : m_id(id), m_name(name) {}

void Student::setId(int id) {
    m_id = id;
}

int Student::getId() const {
    return m_id;
}

void Student::setName(const string& name) {
    m_name = name;
}

string Student::getName() const {
    return m_name;
}

void Student::displayStudent() const {
    cout << "Student ID: " << m_id << ", Name: " << m_name << endl;
}

/*_________________________________________________________________________________________________________________*/

Club::Club(const string& clubName) : m_clubName(clubName) {}

void Club::setClubName(const string& clubName) {
    m_clubName = clubName;
}

string Club::getClubName() const {
    return m_clubName;
}

void Club::displayClub() const {
    cout << "Club Name: " << m_clubName << endl;
}

/*_________________________________________________________________________________________________________________*/

Membership::Membership(Student* student, Club* club) : m_student(student), m_club(club) {}

void Membership::setStudent(Student* student) {
    m_student = student;
}

Student* Membership::getStudent() const {
    return m_student;
}

void Membership::setClub(Club* club) {
    m_club = club;
}

Club* Membership::getClub() const {
    return m_club;
}

void Membership::displayMembership() const {
    if (m_student && m_club) {
        m_student->displayStudent();
        m_club->displayClub();
    } else cout << "Membership is incomplete." << endl;
}