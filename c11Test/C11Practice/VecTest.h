#pragma once
#include <initializer_list>
class VecTest
{
public:
	VecTest();
	~VecTest();
	VecTest(std::initializer_list<double>lst);
	void PrintData();
private:
	double* m_elem;
	int m_nSize;
};

