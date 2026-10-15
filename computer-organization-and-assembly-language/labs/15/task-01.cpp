#include <iostream>
using namespace std;

/*
Write a program in C++ that declares two byte-type arrays of 80 elements each and initialize them with some data. The program then adds the corresponding elements of these two arrays and stores them in a third array using MMX instructions.
*/

int main() {
	unsigned char arr1[80]{};
	unsigned char arr2[80]{};
	unsigned char sum[80]{};

	for (int i = 0; i < 80; i++) 
		arr1[i] = i + 1;
	for (int i = 0; i < 80; i++)
		arr2[i] = i + 2;
	
	for (int i = 0; i < 80; i+= 8) {
		__asm
		{
			push esi
			mov esi, i

			movq mm0, [arr1 + esi]
			movq mm1, [arr2 + esi]
			paddb mm0, mm1

			movq[sum + esi], mm0

			emms
			pop esi
		}
	}
	cout << "Sum Array \n";
	for (int i = 0; i < 80; i++) cout << (int)sum[i] << " ";
    return 0;
}