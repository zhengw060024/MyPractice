// IntToTypeTemplate.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��int ӳ������Ͳ���
#include "stdafx.h"
#include <iostream>
using namespace std;
enum MyEnum
{
	http_post,
	http_get,
	http_put,
	http_del
};
template <MyEnum v>
struct  IntType
{
public:
	enum
	{
		value = v
	};
protected:
private:
};
class B
{
public:
protected:
private:
};
class AAA
{
public:
	template<MyEnum v>
	void DoSomething2()
	{
		DoSomething(IntType<v>());
	}
protected:
	void DoSomething(IntType<http_get>)
	{
		cout << "http_get" << endl;
	}
	void DoSomething(IntType<http_put>)
	{
		cout << "http_put" << endl;
	}
	void DoSomething(IntType<http_post>)
	{
		cout << "http_post" << endl;
	}
	void DoSomething(IntType<http_del>)
	{
		cout << "http_del" << endl;
	}
private:
};
int main()
{
	AAA temp;
	temp.DoSomething2<http_get>();
	getchar();
	return 0;
}
