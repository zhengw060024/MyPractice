// C11Practice.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Complex.h"
#include <iostream>
#include "VecTest.h"
using namespace std;
int main()
{
	Complex a(12, 14.5);
	Complex b(3, 11);
	Complex c = a / b ;
	Complex d = c * b;
	cout << c << endl;
	cout << d << endl;
	// cout << -1 / 2 << endl;
	VecTest temp = { 1,2,5,4,23 };
	temp.PrintData();
	getchar();
    return 0;
}

