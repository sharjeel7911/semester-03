#include <iostream>
using namespace std;
/*Write a C++ program that declares an array of 5 integers & uses assembly to rotate Even indexed elements to the left & Odd indexed elements to the right and Print the array.*/
int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	__asm
	{
		push ebx
		push esi
		mov ecx, 0
		lea esi, arr
		rotateLoop:
		           cmp ecx, 4
                   ja done

				   mov eax, [esi + ecx * 4]

                   test ecx, 1
				   jnz oddIndex

				   rol eax, 1
				   jmp storeValue
                   oddIndex:
				            ror eax, 1
				   storeValue:
					          mov [esi + ecx * 4], eax
	     inc ecx
		 jmp rotateLoop
		 done :
		 pop esi
		 pop ebx
	}
	for(int i = 0; i < 5; i++) cout << arr[i] << endl;
	return 0;
}