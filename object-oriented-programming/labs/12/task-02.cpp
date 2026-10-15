#include <iostream>
using namespace std;

template <class T>
T addNum(T a, T b);

template <class T>
T addNum(T a, T b, T c);

int main() {
    cout << "Two addition: " << addNum(4.9, 77.1) << endl;
    cout << "Three addition: " << addNum(4, 77, 3) << endl;
    return 0;
}

template <class T>
T addNum(T a, T b) {
    return a + b;
}

template <class T>
T addNum(T a, T b, T c) {
    return a + b + c;
}