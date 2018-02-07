#include "stdafx.h"
#include "Complex.h"





Complex& Complex::operator*=(const Complex&z)
{
	double realPart = this->m_realPart* z.m_realPart - \
		this->m_imPart * z.m_imPart;
	double imPart = this->m_realPart * z.m_imPart + \
		this->m_imPart * z.m_realPart;
	this->m_realPart = realPart;
	this->m_imPart = imPart;
	return *this;
}

Complex& Complex::operator/=(const Complex&z)
{
	double nToDepart = z.m_imPart * z.m_imPart + \
		z.m_realPart* z.m_realPart;
	double realPart = this->m_realPart* z.m_realPart + \
		this->m_imPart * z.m_imPart;
	double imPart = -this->m_realPart * z.m_imPart + \
		this->m_imPart * z.m_realPart;
	this->m_realPart = realPart / nToDepart;
	this->m_imPart = imPart / nToDepart;
	return *this;
}

Complex::~Complex()
{

}

bool operator==(const Complex&a, const Complex&b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(const Complex&a, const Complex&b)
{
	return !(a == b);
}

ostream& operator<<(ostream& out, const Complex &a)
{
	if (a.imag() < 0)
	{
		out << a.real() << a.imag() << "i";
	}
	else {
		out << a.real() << "+" << a.imag() << "i";
	}
	
	return out;
}

Complex operator+(const Complex& a, const Complex& b)
{
	Complex Temp = a;
	return Temp += b;
}

Complex operator-(const Complex& a, const Complex& b)
{
	Complex Temp = a;
	return Temp -= b;
}

Complex operator-(const Complex& a)
{
	return{ -a.real(),-a.imag() };
}

Complex operator*(const Complex& a, const Complex& b)
{
	Complex Temp = a;
	return Temp *= b;
}

Complex operator/(const Complex& a, const Complex& b)
{
	Complex Temp = a;
	return Temp /= b;
}
