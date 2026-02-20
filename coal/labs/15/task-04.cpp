#include <iostream>
using namespace std;

/*
Write an assembly language procedure that computes the sum of all elements in an array using MMX (MultiMedia eXtensions) instructions. The procedure should receive the array, its size, and the size of each element as arguments.
*/

unsigned int sumArray(unsigned char* array, int arrSize);
unsigned int sumOfArray(unsigned char* array, int arrSize);
int main() {
	unsigned char arr[80]{};
	for (int i = 0; i < 80; i++)
		arr[i] = i;


	cout << "Sum of Array: " << (int)sumOfArray(arr, 80);
	cout << endl;
	cout << "Sum Array: " << (int)sumArray(arr, 80);
	return 0;
}

//function definition
unsigned int sumArray(unsigned char* array, int arrSize) {
	unsigned int sum = 0;
	unsigned int x = 0;
	unsigned char arr[8] = { 0 };
	for (int i = 0; i < arrSize; i += 8) {
		__asm
		{
			push esi
			mov esi, i
			mov ebx, array
			add ebx, esi

			movq mm0, [ebx]
			movq mm1, arr
			psadbw mm0, mm1; | mm0[i] - mm1[i] | = | val - 0 | psadbw = packed sum of absolute differences of bytes
			; mm0[0..3] = sum(| mm0 - lower - 4 - bytes - mm1 - lower - 4 - bytes | )
			; mm0[4..7] = sum(| mm0 - upper - 4 - bytes - mm1 - upper - 4 - bytes | )
			movd eax, mm0
			mov x, eax

			emms
			pop esi
		}
		sum += x;
	}
	return sum;
}

unsigned int sumOfArray(unsigned char* array, int arrSize) {
	unsigned int sum = 0;
	unsigned int temp = 0;

	short int arr0[4] = { 0,0,0,0 };
	short int arr1[4] = { 1,1,1,1 };

	for (int i = 0; i < arrSize; i += 8) {
		__asm
		{
			push esi
			push ebx

			mov esi, i
			mov ebx, array
			add ebx, esi

			movq mm0, arr0
			movq mm1, arr1
			movq mm2, [ebx]; move array 8 bites

			movq mm3, mm2; copy mm2 to mm3
			punpcklbw mm3, mm0
			pmaddwd mm3, mm1
			movq mm4, mm3; save lower 4 byte sum

			punpckhbw mm2, mm0
			pmaddwd mm2, mm1
			paddd mm2, mm4

			movq mm5, mm2
			psrlq mm5, 32
			paddd mm2, mm5

			movd eax, mm2
			mov temp, eax

			emms
			pop ebx
			pop esi
		}
		sum += temp;
	}
	return sum;
}