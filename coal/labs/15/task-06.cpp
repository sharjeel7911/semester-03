#include <iostream>
using namespace std;

/*
Write a C++ program that declares a array of 8 elements. Using MMX instructions, find the maximum value in the array and print it.
*/

int main() {
    short int arr[8] = { 15, 42, 8, 67, 23, 91, 34, 56 };
    short int result[4]{}; 
    short int maxValue = 0;

    cout << "Array: ";
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    cout << endl;

    __asm 
    {
        movq mm0, qword ptr[arr]
        movq mm1, qword ptr[arr + 8]

        pmaxsw mm0, mm1
        movq qword ptr[result], mm0

        movq mm1, mm0
        psrlq mm1, 32

        pmaxsw mm0, mm1
        movq mm1, mm0
        psrlq mm1, 16
        pmaxsw mm0, mm1
        movd dword ptr[maxValue], mm0

        emms
    }

    cout << "Maximum: " << maxValue << endl;
    return 0;
}