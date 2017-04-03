// MaxSubquenceSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "../utilityFunc/UtilityFunc.h"
typedef struct _SubQuenceInfo
{
	int m_nStart;
	int m_nEnd;
}SubQuenceInfo; 
//这里的原理假设b[j]为以a[j]为结尾的最大子串和，则最大子串一定是b[0]- b[n-1]
//中的最大一项。而对于b[j]; b[j] = a[j] + b[j- 1]<0?0:b[j-1];
int  GetMaxSubQuenceSub(int Array[], int nLength, SubQuenceInfo*pInfo)
{
	int nSum = 0;
	int nMax = Array[0];
	pInfo->m_nStart = 0;
	pInfo->m_nEnd = 0;
	int nTempIndexStart = 0;
	for (int i = 0; i < nLength; ++i)
	{
		nSum += Array[i];
		if (nSum > nMax)
		{
			nMax = nSum;
			pInfo->m_nEnd = i;
			pInfo->m_nStart = nTempIndexStart;
		}
		if (nSum < 0)
		{
			//pInfo->m_nStart = i;
			nSum = 0;
			nTempIndexStart = i + 1;
		}
	}
	return nMax;
}
int main()
{
	int A[20] = { 0 };
	GetRandomArray(A, 20, -100, 100);
	OutPrintIntArray(A, 20, 12);
	SubQuenceInfo Temp;
	int nMaxSum = GetMaxSubQuenceSub(A, 20, &Temp);
	cout << nMaxSum << "   " << Temp.m_nStart << "   " << Temp.m_nEnd << endl;
	getchar();

    return 0;
}

