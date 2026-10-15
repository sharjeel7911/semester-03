#include <iostream>
using namespace std;

template<class T>
T findMax(T num1, T num2);

int main() {
    cout << "Larger Number: " << findMax(1, 4) << endl;
    return 0;
}

template<class T>
T findMax(T num1, T num2) {
    return (num1 > num2) ? num1 : num2;
}