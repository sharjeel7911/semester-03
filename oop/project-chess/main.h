#pragma once
//12 - 12 - 2025 (Saturday)
#include <iostream> //for cout, cin, endl, etc.
#include <string> //for string class
#include <fstream> //for file I/O
#include <sstream> //for stringstream
#include <iomanip> //for setw, setfill
using namespace std; //use standard namespace

inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H";
#endif
}

inline void pauseScreen() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}
//19 - 02 - 2026 (Thursday) [1st Ramadan]