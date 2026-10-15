#include <iostream>
using namespace std;
/*Write a program in C++ that declares and initializes an integer array of 5 elements. The program then swaps the least and most significant bytes of each element of the array using inline assembly language programming. */
int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	__asm
	{
		push ebx
		push esi
		mov ecx, 0
		lea esi, arr
		byteLoop:
		         cmp ecx, 4
		         ja done
		         mov eax, [esi + ecx * 4];

		         mov ebx, eax
		       	 and ebx, 0x000000ff
			     shl ebx, 24

			     mov edx, eax
			     shr edx, 24
			     and edx, 0x000000ff

			     and eax, 0x00ffff00
			     or eax, ebx
			     or eax, edx

			     mov [esi + ecx * 4], eax
	    inc ecx
        jmp byteLoop
	    done:
	    pop esi
	    pop ebx
	}
	for (int i = 0; i < 5; i++) cout << arr[i] << endl;
	return 0;
}