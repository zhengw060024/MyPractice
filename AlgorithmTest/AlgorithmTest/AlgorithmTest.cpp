// AlgorithmTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../utilityFunc//UtilityFunc.h"
#include <iostream>
using namespace std;
void SortHeap(int Array[], int nLength)
{
	makeheap(Array, nLength);
	int nTemp;
	for (int i = nLength - 1; i > 0; --i)
	{
		nTemp = Array[i];
		Array[i] = Array[0];
		Array[0] = nTemp;
		AjustHeap(Array,0 ,i,Array[0]);
	}
}
int main()
{
	int A[20] = { 0 };
	GetRandomArray(A, 20, 0, 100);
	OutPrintIntArray(A, 20, 5);
	cout << endl;
	makeheap(A, 20);
	OutPrintIntArray(A, 20, 5);
	cout << endl;
	OutPrintHeapArray(A, 20);
	cout << endl;
	SortHeap(A, 20);
	OutPrintIntArray(A, 20, 5);
	cout << "hello world! Algorithm test";
	getchar();
    return 0;
}

