#pragma once
#include <iostream>
using namespace std;
class Complex
{
public:
	~Complex();
	Complex(double real, double im) :m_realPart{ real }, m_imPart{ im } {

	}
	Complex(double  real) :m_realPart{ real }, m_imPart(0){

	}
	Complex() :m_realPart(0), m_imPart(0) {

	}
	double real()const {
		return m_realPart;
	}
	double imag() const {
		return m_imPart;
	}
	Complex &operator+=(const Complex& z) {
		m_imPart += z.m_imPart;
		m_realPart += z.m_realPart;
		return *this;
	}
	Complex &operator-=(const Complex&z) {
		m_realPart -= z.m_realPart;
		m_imPart -= z.m_imPart;
		return *this;
	}
	Complex&operator *=(const Complex&z);
	Complex&operator /=(const Complex&z);
private:
	double m_realPart;
	double m_imPart;
};
Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);
Complex operator-(const Complex& a);
Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);
bool operator ==(const Complex&a, const Complex&b);
bool operator != (const Complex&a, const Complex&b);
ostream& operator << (ostream& out, const Complex &a);


