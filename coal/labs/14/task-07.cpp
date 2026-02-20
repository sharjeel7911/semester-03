#include <iostream>
using namespace std;
/*Write an inline assembly function that rotates an integer value either left or right
Direction is passed as a parameter: 0 → rotate left, 1 → rotate right
Call this function from main() and display the result
*/
unsigned int rotate(unsigned int num, int dir);
int main() {
	unsigned int num = 15;

	unsigned int leftRot = rotate(num, 0);
	unsigned int rightRot = rotate(num, 1);

	cout << "Original: " << num << endl;
	cout << "Rotate left : " << leftRot << endl;
	cout << "Rotate right: " << rightRot << endl;
	return 0;
}

unsigned int rotate(unsigned int num, int dir) {
	int result = 0;
	__asm
	{
		push ebx
		push esi

		mov eax, num
		cmp dir, 0
		je rotateLeft
		ror eax, 1
		jmp done

		rotateLeft:
		           rol eax, 1
        done:
			  mov result, eax
		pop esi
		pop ebx
	}
	return result;
}