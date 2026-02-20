#include <iostream>
using namespace std;
/*Write an inline assembly code snippet that modifies the EBX register and then correctly restores its original value before exiting the assembly block.*/
int main() {
    int num = 10;
    __asm {
        push ebx
        mov ebx, num
        add ebx, 5
        mov num, ebx
        pop ebx
    }
    cout << "Modified num: " << num << endl;
    return 0;
}