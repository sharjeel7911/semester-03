#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
	char* m_name;
	int m_numerator;
	int m_denominator;
	static int m_totalFractions;
	const int m_ID;
public:
	Fraction();
	~Fraction();
	Fraction(char*, int, int);
	Fraction(const Fraction&);

	void setName(char*);
	char* getName();
	void setNum(int);
	int getNum();
	void setDen(int);
	int getDen();
	void display();
	Fraction addFractions(Fraction&);
};