#include <iostream>
using namespace std;
/*Write a C++ program that uses inline assembly to increment all elements of an integer array using a loop in assembly language.*/
int main() {
    int arr[] = { 10, 20, 30, 40, 50 };
    __asm
    {
        lea eax, arr
        mov ecx, 5
        xor esi, esi
        incLoop:
                mov ebx, [eax + esi]
                inc ebx
                mov[eax + esi], ebx
                add esi, 4
        loop incLoop
    }
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    return 0;
}