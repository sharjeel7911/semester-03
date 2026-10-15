#include "fraction.h"

int Fraction::m_totalFractions = 0;

Fraction::Fraction(): m_ID(++m_totalFractions) {
	m_name = nullptr;
	m_numerator = 0;
	m_denominator = 0;
}

Fraction::~Fraction() {
	delete m_name;
	m_totalFractions--;
}

Fraction::Fraction(char* name, int n, int d): m_ID(++m_totalFractions) {
	int size = 0;
	while (name[size] != '\0') size++;
	m_name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		m_name[i] = name[i];
	}
	m_name[size] = '\0';

	m_numerator = n;
	m_denominator = d;
}

Fraction::Fraction(const Fraction& obj) : m_ID(++m_totalFractions) {
	int size = 0;
	while (obj.m_name[size] != '\0') size++;
	m_name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		m_name[i] = obj.m_name[i];
	}
	m_name[size] = '\0';

	m_numerator = obj.m_numerator;
	m_denominator = obj.m_denominator;
}

void Fraction::setName(char* name) {
	int size = 0;
	while (name[size] != '\0') size++;
	m_name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		m_name[i] = name[i];
	}
	m_name[size] = '\0';
}

char* Fraction::getName() {
	int size = 0;
	while (m_name[size] != '\0') size++;
	char* temp = new char[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = m_name[i];
	}
	temp[size] = '\0';
	return temp;

}

void Fraction::setNum(int n) {
	m_numerator = n;
}

int Fraction::getNum() {
	return m_numerator;
}

void Fraction::setDen(int d) {
	m_denominator = d;
}

int Fraction::getDen() {
	return m_denominator;
}

void Fraction::display() {
	cout << "**** Displaying values ****" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Numerator: " << getNum() << endl;
	cout << "Denominator: " << getDen() << endl;
	cout << "Id of fraction: " << m_ID << endl;
	cout << "Total Fractions: " << m_totalFractions << endl;
}

Fraction Fraction::addFractions(Fraction& obj) {
	Fraction temp;
	char name[18] = "resultantFraction";
	temp.setName(name);
	
	temp.m_numerator = this	->m_numerator + obj.m_numerator;
	temp.m_denominator = this->m_denominator + obj.m_denominator;
	
	return temp;
}
