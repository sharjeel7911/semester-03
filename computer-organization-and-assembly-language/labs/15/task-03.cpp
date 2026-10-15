#include <iostream>
using namespace std;

/*
Write a program in C++ that declares a byte array of 80 elements and initialize it with some data. The program then calculates the sum of even and odd elements using MMX instructions and prints them.
*/

int main() {
	unsigned char arr[80]{};
	unsigned char arr0[8]{};
	unsigned char arr1[8]{};
	unsigned char arrOdd[80]{};
	unsigned char arrEven[80]{};
	int evenSum = 0;
	int oddSum = 0;

	for (int i = 0; i < 80; i++) 
		arr[i] = i + 1;

    for (int i = 0; i < 8; i++) arr0[i] = 0;
    for (int i = 0; i < 8; i++) arr1[i] = 1;
        
	for (int i = 0; i < 80; i+= 8) {
		__asm
		{
			push esi
			mov esi, i

			movq mm0, [arr + esi] ;move 8 bytes
			movq mm1, [arr1]  ;move mask of 1's
			pand mm0, mm1 ;and both, mm0 will contain ZEROS in all bits except lsb[where some lsb will have value(mean odd num) or ZERO] 

			movq mm1, [arr0] ;move mask of 0's
			pcmpgtb mm0, mm1 ;compare with mm0, if val on mm0 > 0, 0xff will be stored in mm0
			pand mm0, [arr + esi] ;just odd numbers of array are loaded in mm0 
			movq[arrOdd + esi], mm0 ;all odd numbers are stored in array

			emms
			pop esi
		}
	}
	for (int i = 0; i < 80; i++) oddSum += (int)arrOdd[i];

	for (int i = 0; i < 80; i += 8) {
		__asm
		{
			push esi
			mov esi, i

			movq mm0, [arr + esi]
			movq mm1, [arr1]
			pand mm0, mm1

			movq mm1, [arr0]
			pcmpeqb mm0, mm1 ;if val == 0, 0xff will be stored in mm0
			pand mm0, [arr + esi]
			movq[arrEven + esi], mm0

			emms
			pop esi
		}
	}
	for (int i = 0; i < 80; i++) evenSum += (int)arrEven[i];

	cout << "Odd Sum: " << oddSum << "\nEven Sum: " << evenSum;
    return 0;
}