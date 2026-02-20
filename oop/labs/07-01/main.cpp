#include "Fraction.h"

int main() {
	Fraction f1; //default constructor
	cout << "Enter name" << endl;
	char* name = new char[30];
	cin.getline(name, 30);
	cout << "Enter numerator and denomerator" << endl;
	int n, d;
	cin >> n >> d;
	f1.setName(name);
	f1.setNum(n);
	f1.setDen(d);
	system("cls");

	Fraction f2 = f1; //copy constructor
	Fraction f3(name, n, d); //parameterized constructor

	//calling new obj function merging two fractions
	Fraction f4 = f1.addFractions(f3);

	cout << "Display Function" << endl;
	f1.display();
	cout << endl;
	f2.display();
	cout << endl;
	f3.display();
	cout << endl;
	f4.display();
	system("pause");
	delete[] name;
	return 0;
}