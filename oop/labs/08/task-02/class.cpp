#include "class.h"

Course::Course(const string& courseCode, const string& title) : m_courseCode(courseCode), m_title(title) {}

void Course::setCourseCode(const string& courseCode) {
    m_courseCode = courseCode;
}

string Course::getCourseCode() const {
    return m_courseCode;
}

void Course::setTitle(const string& title) {
    m_title = title;
}

string Course::getTitle() const {
    return m_title;
}

void Course::display() const {
    cout << "Course Code: " << getCourseCode() << endl << "Title: " << getTitle() << endl;
}

/*___________________________________________________________________________________________________________________________________*/

Teacher::Teacher(const string& name, Course** courses) : m_name(name), m_courseCount(0) {
    for (int i = 0; i < 5; ++i) m_courses[i] = nullptr;
    if (courses != nullptr)
        for (int i = 0; i < 5 && courses[i] != nullptr; ++i)
            m_courses[m_courseCount++] = courses[i];
}

void Teacher::setName(const string& name) {
    m_name = name;
}

string Teacher::getName() const {
    return m_name;
}

bool Teacher::addCourse(Course* course) {
    if (m_courseCount >= 5) return false;
    else m_courses[m_courseCount++] = course;
    return true;
}

void Teacher::displayCourses() const {
    cout << "Teacher Name: " << getName() << endl;
    cout << "Courses:" << endl;
    for (int i = 0; i < m_courseCount; i++) {
        cout << i + 1 << ". ";
        m_courses[i]->display();
    }
}