// C11Practice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Complex.h"
#include <iostream>
using namespace std;
int main()
{
	Complex a(12, 14.5);
	Complex b(3, 11);
	Complex c = a / b ;
	Complex d = c * b;
	cout << c << endl;
	cout << d << endl;
	getchar();
    return 0;
}

