#include "stdafx.h"
#include "UtilityFunc.h"
#include <iostream>
#include <random>
using namespace std;
void PushHeap(int Array[], int holeIndex, int nTopIndex, int nValue)
{
	int nKeyParent = (holeIndex - 1) / 2;
	while (holeIndex > nTopIndex && *(Array + nKeyParent) < nValue)
	{
		*(Array + holeIndex) = *(Array + nKeyParent);
		holeIndex = nKeyParent;
		nKeyParent = (holeIndex - 1) / 2;
	}
	*(Array + holeIndex) = nValue;
}

void AjustHeap(int Array[], int holeIndex, int nLength, int nValue)
{
	int nTobIndex = holeIndex;
	int nSencondChild = 2 * holeIndex + 2;
	while (nSencondChild < nLength)
	{
		if (*(Array + nSencondChild) < *(Array + nSencondChild - 1))
		{
			--nSencondChild;
		}

		*(Array + holeIndex) = *(Array + nSencondChild);
		holeIndex = nSencondChild;
		nSencondChild = 2 * holeIndex + 2;
	}
	if (nSencondChild == nLength)
	{
		*(Array + holeIndex) = *(Array + nSencondChild - 1);
		holeIndex = nSencondChild - 1;
	}
	PushHeap(Array, holeIndex, nTobIndex, nValue);
}

void makeheap(int Array[], int nLength)
{
	if (nLength <= 1)
	{
		return;
	}
	int keyIndex = (nLength - 2) / 2;
	while (true)
	{
		AjustHeap(Array, keyIndex, nLength, *(Array + keyIndex));
		if (keyIndex == 0)
		{
			return;
		}
		--keyIndex;
	}
}

void GetRandomArray(int Array[], int nLength, int nMin, int nMax)
{
	int nDif = nMax - nMin + 1;
	std::random_device rd;
	for (int i = 0; i < nLength; ++i)
	{
		Array[i] = (rd() % nDif) + nMin;
	}
}

void OutPrintIntArray(int Array[], int nLength, int nLineNum)
{
	for (int i = 0; i < nLength; ++i)
	{
		cout << Array[i] << "    ";
		if ((i + 1) % nLineNum == 0)
		{
			cout << endl;
		}
	}
	if (nLength % nLineNum != 0)
	{
		cout << endl;
	}
}

void OutPrintHeapArray(int Array[], int nLength)
{
	int nPrintNum = 0;
	int nPrintLine = 1;
	while ((nPrintNum + nPrintLine) < nLength)
	{
		for (int i = 0; i < nPrintLine; ++i)
		{
			cout << Array[nPrintNum + i] << "	";
		}
		cout << endl;
		nPrintNum = nPrintNum + nPrintLine;
		nPrintLine = nPrintLine * 2;
		//nPrintLine = n
	}
	for (int i = nPrintLine; i < nLength; ++i)
	{
		cout << Array[i] << "    ";
	}
	cout << endl;
}
