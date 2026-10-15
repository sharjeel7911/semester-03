#include <iostream>
using namespace std;
/*
Write a program in C++ that declares and initializes an integer array of 5 elements. The 
program then swaps the least and most significant bytes and the nibbles of the second byte 
of each element of the array using inline assembly language programming. 
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

			           mov ebx, eax
				       and ebx, 0x000000ff
				       shl ebx, 24

				       mov ecx, eax
				       shr ecx, 24
				       and ecx, 0x000000ff

				       and eax, 0x00ffff00
				       or eax, ebx
				       or eax, ecx

				       ;swap nibbles of second byte
				       mov ebx, eax
				       shr ebx, 8
				       and ebx, 0x000000ff
				       mov edx, ebx
				       and ebx, 0x0f
				       shl ebx, 4
				       and edx, 0xf0
				       shr edx, 4
				       or ebx, edx
				       shl ebx, 8
				       and eax, 0xffff00ff; 
			           or eax, ebx

				       mov [esi + ecx * 4] , eax
					   inc ecx
			jmp inlineLoop
			done:
			pop esi
			pop ebx
		}
	for (int i = 0; i < 5; i++) cout << arr[i] << endl;
	return 0;
}