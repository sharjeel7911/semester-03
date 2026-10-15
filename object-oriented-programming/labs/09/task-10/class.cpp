#include "class.h"

Teacher::Teacher(const char* name, const char* subject) {
    if (name) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    } else m_name = nullptr;

    if (subject) {
        m_subject = new char[strlen(subject) + 1];
        strcpy(m_subject, subject);
    } else m_subject = nullptr;
}

Teacher::~Teacher() {
    delete[] m_name;
    delete[] m_subject;
}

void Teacher::display() {
    cout << "Name: " << (m_name ? m_name : "N/A") << endl;
    cout << "Subject: " << (m_subject ? m_subject : "N/A") << endl;
}

/*_____________________________________________________________________________*/

Researcher::Researcher(const char* area, int publications) : m_publications(publications) {
    if (area) {
        m_researchArea = new char[strlen(area) + 1];
        strcpy(m_researchArea, area);
    } else m_researchArea = nullptr;
}

Researcher::~Researcher() {
    delete[] m_researchArea;
}

void Researcher::display() {
    cout << "Research Area: " << (m_researchArea ? m_researchArea : "N/A") << endl;
    cout << "Publications: " << m_publications << endl;
}

/*_______________________________________________________________________________*/


Professor::Professor(const char* name, const char* subject, const char* area, int publications, const char* department, int load) : Teacher(name, subject), Researcher(area, publications), m_load(load) {
    if (department) {
        m_department = new char[strlen(department) + 1];
        strcpy(m_department, department);
    } else m_department = nullptr;
}

Professor::~Professor() {
    delete[] m_department;
}

void Professor::display() {
    Teacher::display();
    Researcher::display();
    cout << "Department: " << (m_department ? m_department : "N/A") << endl;
    cout << "Teaching Load: " << m_load << endl;
}