// DynamicCastTest.cpp : 定义控制台应用程序的入口点。
//
//zhengwei dynamic_cast 效率比较低，一般能不使用尽量不使用。
#include "stdafx.h"
#include <iostream>
using namespace std;
class TT
{
public:
	virtual bool IsEqual(TT* pTemp) = 0;
protected:
private:
};
class TT1 :public TT
{
public:
	TT1(int t) :a(t)
	{

	}
	bool IsEqual(TT* pTemp)
	{
		TT1* p = dynamic_cast<TT1*>(pTemp);
		if (p)
		{
			return p->a == a;
		}
		return false;

	}
protected:
private:
	int a;
};
class TT2 :public TT
{
public:
	TT2(int t) :b(t)
	{

	}
	bool IsEqual(TT* pTemp)
	{
		TT2* p = dynamic_cast<TT2*>(pTemp);
		if (p)
		{
			return p->b == b;
		}
		return false;
	}
protected:
private:
	int b;
};

int main()
{
	TT1 a1(10);
	TT2 a2(10);
	TT1 b1(10);
	if (a1.IsEqual(&a2))
	{
		cout << "test failed" << endl;
	}
	else
	{
		cout << "test success" << endl;
	}
	if (a1.IsEqual(&b1))
	{
		cout << "---------------ok-----------" << endl;
	}
	getchar();
	return 0;
}

