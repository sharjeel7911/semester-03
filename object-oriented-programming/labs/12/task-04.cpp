#include <iostream>
#include <string>
using namespace std;

template<class T>
T multiplyNum(T a, T b = 2);

int main() {
    cout << "Multiple: " << multiplyNum(5) << endl;
    cout << "Multiple: " << multiplyNum(5.5, 10.5) << endl;
    return 0;
}

template<class T>
T multiplyNum(T a, T b) {
    return a * b;
}