#include <iostream>
using namespace std;
/*
Write a program in C++ that declares and initializes an integer array of 5 elements. The
program then rotates the least significant byte (i.e., byte #0) and most significant byte (i.e.,
byte #3) to the left and byte #1 and byte #2 to the right of each element of the array using
inline assembly language programming.
*/
int main() {
	unsigned int arr[] = { 0x12345678, 0x9abcdef0, 0x0fedcba9, 0x87654321, 0x11223344 };
		__asm
		{
			push ebx
			push esi
			lea esi, arr
			mov ecx, 0

			inlineLoop:
			           cmp ecx, 4
			           ja done
			           mov eax, [esi + ecx * 4];

					   ; rotate byte 0 to the left
						   mov ebx, eax
						   and ebx, 0x000000ff
						   rol bl, 1
						   and eax, 0xffffff00
						   or eax, ebx
					   ; rotate byte 1 to the right
						   mov ebx, eax
						   and ebx, 0x0000ff00
						   ror bh, 1
						   and eax, 0xffff00ff
						   or eax, ebx
					   ; rotate byte 2 to the right
						   mov ebx, eax
						   and ebx, 0x00ff0000
						   shr ebx, 16
						   ror bl, 1
						   shl ebx, 16
						   and eax, 0xff00ffff
						   or eax, ebx
					   ; rotate byte 3 to the left
						   mov ebx, eax
						   and ebx, 0xff000000
						   shr ebx, 24
						   rol bl, 1
						   shl ebx, 24
						   and eax, 0x00ffffff
						   or eax, ebx

				       mov [esi + ecx * 4] , eax
					   inc ecx
			jmp inlineLoop
			done:
			pop esi
			pop ebx
		}
		for (int i = 0; i < 5; i++) cout << hex << arr[i] << endl;
	return 0;
}