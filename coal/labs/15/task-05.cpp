#include <iostream>
using namespace std;

/*
Write a C++ program that declares a byte array of 80 elements. Using MMX instructions, count how many elements in the array are greater than 50.
*/

int main() {
	unsigned char arr[80]{};
	unsigned char temp[8]{};
	unsigned char rand[80]{};

	for (int i = 0; i < 80; i++)
		arr[i] = i;
	for (int i = 0; i < 8; i++)
		temp[i] = 50;

	for (int i = 0; i < 80; i += 8) {
		__asm
		{
			push esi
			mov esi, i

			movq mm0, [arr + esi]
			movq mm1, [temp]
			pcmpgtb mm0, mm1
			movq[rand + esi], mm0

			emms
			pop esi
		}
	}

	int count = 0;
	for (int i = 0; i < 80; i++) {
		if (rand[i] == 0xff) count++;
	}
	cout << "Total values above 50: " << count;
	return 0;
}