// Smart_Ptr.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <memory>
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
	//unique_ptrֻ����ĳ������������ɶ��������
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
	//���������һ��ָ��
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

int main()
{
	shared_ptr<DataBuffer> Temp = std::make_shared<DataBuffer>(14);
	A a(Temp);
	B b(Temp);
	cout << a.GetNum() << endl;
	a.SetNum(16);
	cout << b.GetNum() << endl;
	getchar();
    return 0;
}

