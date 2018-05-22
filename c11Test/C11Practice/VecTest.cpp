#include "stdafx.h"
#include "VecTest.h"
#include <memory>
#include <iterator>
#include <iostream>
VecTest::VecTest()
{
}


VecTest::VecTest(std::initializer_list<double>lst):m_elem{ new double[lst.size()] }, m_nSize(lst.size())
{
	// 这个地方使用stdext::checked_array_iterator防止c4996错误
	std::copy(lst.begin(), lst.end(), stdext::checked_array_iterator<double*>(m_elem,lst.size()));
}

void VecTest::PrintData()
{
	for (int i = 0; i < this->m_nSize; ++i)
	{
		std::cout << (this->m_elem)[i] << std::endl;
	}
}

VecTest::~VecTest()
{
	if (this->m_elem)
	{
		delete[] this->m_elem;
		this->m_nSize = 0;
		this->m_elem = nullptr;
	}
}
