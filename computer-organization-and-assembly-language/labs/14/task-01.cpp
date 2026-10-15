#include <iostream>
using namespace std;
/*Write a C++ program that uses inline assembly to move the value of one 32-bit register into another register. Declare an integer variable in C++ and use inline assembly to load its value into the EAX register.*/
int main() {
    int num = 43;
    int result = 0;
    __asm
    {
        mov eax, num
        mov ebx, eax
        mov result, ebx
    }
    cout << "The value moved to EAX and then to EBX is: " << result << endl;

    return 0;
}