#include <iostream>
using namespace std;
/*Write a C++ program that uses inline assembly to add two C++ integer variables and store the result in another variable.*/
int main() {
    int a = 6, b = 7, sum = 0;
    __asm
    {
        mov eax, a
        add eax, b
        mov sum, eax
    }
    cout << "The sum of " << a << " and " << b << " is: " << sum << endl;
    return 0;
}