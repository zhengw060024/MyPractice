// MinKPostionNum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "../utilityFunc//UtilityFunc.h"
//#include <algorithm>
using namespace std;
//�㷨һ����ǰk������Ϊ������������ȵ�ǰ����Ҫ��ʹ��룬
//��֮����
void Swap(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}
int MinKthPostionNum1(int Array[] ,int nLength,int kTh)
{
	int KthMin;
	for (int i = 0; i < kTh; ++i)
	{
		for (int j = kTh; j < nLength; ++j)
		{
			if (Array[i] > Array[j] )
			{
				Swap(Array[i], Array[j]);
			}
		}
	}
	KthMin = Array[0];
	for (int i = 1; i < kTh; ++i)
	{
		if (KthMin < Array[i])
		{
			KthMin = Array[i];
		}
	}
	return KthMin;
}
//�㷨������һ���иĽ�����ǰk�������ɴ�heap��
// Ȼ�󽫺������ݺͶ��е�������ݱȽϣ����С
// �������У����������ԣ����heap����������Ҫ��
//����
int MinKthPostionNum2(int Array[], int nLength,int nKth)
{
	makeheap(Array, nKth);
	for (int i = nKth; i < nLength; ++i)
	{
		if (Array[0] > Array[i])
		{
			Swap(Array[0], Array[i]);
			AjustHeap(Array, 0, nKth, Array[0]);
			//makeheap(Array, nKth);
		}
	}
	return Array[0];
}
int main()
{
	int Array[20] = { 0 };
	GetRandomArray(Array, 20, 1, 28);
	OutPrintHeapArray(Array, 20);
	cout << MinKthPostionNum2(Array, 20, 6) << endl;
	//cout << MinKthPostionNum1(Array, 20, 6) << endl;
	//SortHeap(Array, 20);
	//std::sort(Array, Array + 20);
	OutPrintIntArray(Array, 20, 5);
	getchar();
    return 0;
}

