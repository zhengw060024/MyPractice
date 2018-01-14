// Smart_Ptr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#define new new( _CLIENT_BLOCK, __FILE__, __LINE__) 
//#define _Circle_Ptr
using namespace std;
class DataBuffer
{
public:
	struct MyUniqueStruct
	{
		MyUniqueStruct(int a, int b):m_a(a),m_b(b)
		{

		}
		int m_a;
		int m_b;
	};
	DataBuffer(int Num) :m_Num(Num),m_pUniqueItem(new MyUniqueStruct(1,5))
	{

	}
	~DataBuffer()
	{
		cout << "item is destroyed!" << endl;
	}
	int get()
	{
		return m_Num;
	}
	void set(int Num)
	{
		m_Num = Num;
	}
protected:
private:
	int m_Num;
	//unique_ptr只能在某个对象独享，不可多个对象共享
	std::unique_ptr<MyUniqueStruct> m_pUniqueItem;
};
class A
{
public:
	A(std::shared_ptr<DataBuffer> ptInt):m_dataA(ptInt)
	{

	}
	void SetNum(int Num)
	{
		m_dataA->set(Num);
	}
	int GetNum() {
		return m_dataA->get();
	}
protected:
	//多个对象共享一个指针
	std::shared_ptr<DataBuffer> m_dataA;
private:
};
class B
{
public:
	B(std::shared_ptr<DataBuffer>ptInt) :m_dataB(ptInt)
	{

	}
	void SetNum(int Num)
	{
		m_dataB->set(Num);
	}
	int GetNum()
	{
		return m_dataB->get();
	}
protected:
private:
	std::shared_ptr<DataBuffer> m_dataB;
};

void TestCirle_ptr_Case() {
	class Parent;
	class Child;
	class Parent
	{
	public:
		shared_ptr<Child> m_Child;
		~Parent() {
			cout << "Parent Destroy" << endl;
		}
	protected:
	private:

	};
	class Child
	{
	public:
		~Child() {
			cout << "Child Destroy" << endl;
		}
#ifdef _Circle_Ptr
	shared_ptr<Parent> m_Parent;
#else
		weak_ptr<Parent> m_Parent;
#endif
		
	protected:
	private:
	};
	shared_ptr<Parent> father = std::make_shared<Parent>();
	shared_ptr<Child> child = std::make_shared<Child>();
	father->m_Child = child;
	
#ifdef _Circle_Ptr
	child->m_Parent = father;
#else
	child->m_Parent = weak_ptr<Parent>(father);
#endif
	
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	shared_ptr<DataBuffer> Temp = std::make_shared<DataBuffer>(14);
	A a(Temp);
	B b(Temp);
	cout << a.GetNum() << endl;
	a.SetNum(16);
	cout << b.GetNum() << endl;

	TestCirle_ptr_Case();
	getchar();
    return 0;
}

