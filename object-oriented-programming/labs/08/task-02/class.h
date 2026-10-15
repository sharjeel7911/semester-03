#include "../main.h"

class Teacher;
class Course;

class Course {
private:
    string m_courseCode;
    string m_title;
public:
    Course(const string& m_courseCode = "", const string& m_title = "");
    void setCourseCode(const string& courseCode);
    string getCourseCode() const;
    void setTitle(const string& title);
    string getTitle() const;
    void display() const;
};

class Teacher {
private:
    Course* m_courses[5];
    string m_name;
    int m_courseCount;
public:
    Teacher(const string& name = "", Course** courses = nullptr);
    void setName(const string& name);
    string getName() const;
    bool addCourse(Course* course);
    void displayCourses() const;
};