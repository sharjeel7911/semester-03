#include "main.h"
#include "student.h"

void searchById();
void createStudent();
void readStudent();
void updateStudent();
void deleteStudent();
void loadfromCsv();
bool rollNumberExists(int rollNo);

int main() {
    clearScreen();
    int choice;

    do {
        clearScreen();
        cout << "                                                          ~~~  MENU  ~~~ " << endl << endl;
        cout << "1. Create Student                    2. Read Student                       3. Update Student                    4. Delete Student " << endl << endl;
        cout << "                                                      5. Display from CSV            " << endl << endl;
        cout << "                                                             0. Exit              " << endl << endl;
        cout << "Enter your choice (0 - 5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            createStudent();
            break;
        case 2:
            readStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            loadfromCsv();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 0 and 5" << endl;
            pauseScreen();
            break;
        }
    } while (choice != 0);
    return 0;
}

bool rollNumberExists(int rollNo) {
    ifstream read("students.csv");
    if (!read) return false;

    string line;
    while (getline(read, line)) {
        stringstream ss(line);
        string field;
        int uniqueId, id;

        getline(ss, field, ',');
        uniqueId = stoi(field);
        getline(ss, field, ',');
        id = stoi(field);

        if (id == rollNo) {
            read.close();
            return true;
        }
    }
    read.close();
    return false;
}

void createStudent() {
    clearScreen();
    Student st;
    cin >> st;

    // Check if roll number already exists
    if (rollNumberExists(st.getId())) {
        cout << "Error: A student with roll number " << st.getId()
            << " already exists!" << endl;
        pauseScreen();
        return;
    }

    st.toCsv();
    cout << "Student added to database" << endl;
    pauseScreen();
}

void readStudent() {
    clearScreen();
    searchById();
}

void searchById() {
    clearScreen();
    int searchRoll;
    cout << "Enter roll number to search: ";
    cin >> searchRoll;

    ifstream read("students.csv");
    if (!read) {
        cout << "CSV file not found!" << endl;
        pauseScreen();
        return;
    }

    cout << left << setw(10) << "RollNo" << setw(20) << "Name" << setw(5) << "Age" << setw(5) << "GPA" << endl;
    cout << "----------------------------------------" << endl;

    string line;
    bool found = false;
    while (getline(read, line)) {
        stringstream ss(line);
        string field;
        int uniqueId, rollNo, age;
        string name;
        float gpa;

        getline(ss, field, ',');
        uniqueId = stoi(field);
        getline(ss, field, ',');
        rollNo = stoi(field);
        getline(ss, name, ',');
        getline(ss, field, ',');
        age = stoi(field);
        getline(ss, field, ',');
        gpa = stof(field);

        if (rollNo == searchRoll) {
            cout << left << setw(10) << rollNo << setw(20) << name << setw(5) << age << setw(5) << gpa << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No student found with roll number " << searchRoll << endl;

    read.close();
    pauseScreen();
}

void loadfromCsv() {
    clearScreen();
    ifstream read("students.csv");
    if (!read) {
        cout << "CSV file not found!" << endl;
        pauseScreen();
        return;
    }

    cout << left << setw(10) << "RollNo" << setw(20) << "Name" << setw(5) << "Age" << setw(5) << "GPA" << endl;
    cout << "----------------------------------------" << endl;

    string line;
    while (getline(read, line)) {
        stringstream ss(line);
        string field;
        int uniqueId, rollNo, age;
        string name;
        float gpa;

        getline(ss, field, ',');
        uniqueId = stoi(field);
        getline(ss, field, ',');
        rollNo = stoi(field);
        getline(ss, name, ',');
        getline(ss, field, ',');
        age = stoi(field);
        getline(ss, field, ',');
        gpa = stof(field);

        cout << left << setw(10) << rollNo << setw(20) << name << setw(5) << age << setw(5) << gpa << endl;
    }

    read.close();
    pauseScreen();
}

void updateStudent() {
    clearScreen();
    int rollNo;
    cout << "Enter roll number to update: ";
    cin >> rollNo;

    ifstream read("students.csv");
    if (!read) {
        cout << "CSV file not found!" << endl;
        pauseScreen();
        return;
    }

    ofstream temp("temp.csv");
    string line;
    bool found = false;

    while (getline(read, line)) {
        stringstream ss(line);
        string field, name;
        int uniqueId, id, age;
        float gpa;

        getline(ss, field, ',');
        uniqueId = stoi(field);
        getline(ss, field, ',');
        id = stoi(field);
        getline(ss, name, ',');
        getline(ss, field, ',');
        age = stoi(field);
        getline(ss, field, ',');
        gpa = stof(field);

        if (id == rollNo) {
            cout << "Student found. Enter new details:\n";
            Student st;
            cin >> st;
            // Write updated student to temp file
            temp << uniqueId << "," << st.getId() << "," << st.getName()
                << "," << st.getAge() << "," << st.getGpa() << endl;
            found = true;
        } else {
            // Write existing student to temp file
            temp << uniqueId << "," << id << "," << name << ","
                << age << "," << gpa << endl;
        }
    }

    read.close();
    temp.close();

    if (!found) {
        cout << "No student found with roll number " << rollNo << endl;
        remove("temp.csv");
        pauseScreen();
        return;
    }

    remove("students.csv");
    rename("temp.csv", "students.csv");

    cout << "Student updated successfully." << endl;
    pauseScreen();
}

void deleteStudent() {
    clearScreen();
    int rollNo;
    cout << "Enter roll number to delete: ";
    cin >> rollNo;

    ifstream read("students.csv");
    if (!read) {
        cout << "CSV file not found!" << endl;
        pauseScreen();
        return;
    }

    ofstream temp("temp.csv");
    string line;
    bool found = false;

    while (getline(read, line)) {
        stringstream ss(line);
        string field, name;
        int uniqueId, id, age;
        float gpa;

        getline(ss, field, ',');
        uniqueId = stoi(field);
        getline(ss, field, ',');
        id = stoi(field);
        getline(ss, name, ',');
        getline(ss, field, ',');
        age = stoi(field);
        getline(ss, field, ',');
        gpa = stof(field);

        if (id == rollNo) {
            found = true;
            continue;  // Skip this student (don't write to temp)
        } else {
            // Write existing student to temp file
            temp << uniqueId << "," << id << "," << name << ","
                << age << "," << gpa << endl;
        }
    }

    read.close();
    temp.close();

    if (!found) {
        cout << "No student found with roll number " << rollNo << endl;
        remove("temp.csv");
        pauseScreen();
        return;
    }

    remove("students.csv");
    rename("temp.csv", "students.csv");

    cout << "Student deleted successfully." << endl;
    pauseScreen();
}