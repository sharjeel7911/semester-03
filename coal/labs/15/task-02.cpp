#include <iostream>
using namespace std;

/*
Write a C++ program that declares two byte arrays of 80 elements. Using MMX instructions, subtract the corresponding elements of the second array from the first array and store the result in a third array.
*/

int main() {
	unsigned char arr1[80]{};
	unsigned char arr2[80]{};
	unsigned char sub[80]{};

	for (int i = 0; i < 80; i++) 
		arr1[i] = i + 2;
	for (int i = 0; i < 80; i++)
		arr2[i] = i + 1;
	
	for (int i = 0; i < 80; i+= 8) {
		__asm
		{
			push esi
			mov esi, i

			movq mm0, [arr1 + esi]
			movq mm1, [arr2 + esi]
			psubb mm0, mm1

			movq[sub + esi], mm0

			emms
			pop esi
		}
	}
	cout << "Subtracted Array \n";
	for (int i = 0; i < 80; i++) cout << (int)sub[i] << " ";
    return 0;
}