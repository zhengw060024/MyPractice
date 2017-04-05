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
////这里的原理假设b[j]为以a[j]为结尾的最大子串和，则最大子串一定是b[0]- b[n-1]
//中的最大一项
int GetMaxSubQuenceSubOrg(int Array[], int nLength, SubQuenceInfo*pInfo)
{
	int nMax = Array[0];
	for (int i = 0; i < nLength; ++i)
	{
		int nMaxSubEnd = 0;
		for (int j = i; j >= 0; --j)
		{
			nMaxSubEnd += Array[j];
			if (nMaxSubEnd > nMax)
			{
				nMax = nMaxSubEnd;
				pInfo->m_nEnd = i;
				pInfo->m_nStart = j;
			}
		}
	}
	return nMax;
}
//优化：这里的原理假设b[j]为以a[j]为结尾的最大子串和，则最大子串一定是b[0]- b[n-1]
//中的最大一项。而对于b[j]; b[j] = a[j] + b[j- 1]<0?0:b[j-1];这样可以将复杂度将为O(n)
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
//分治法，复杂度n*lg(n)
//////////////////
int  GetMaxSubQuenceSubDepartRecur(int Array[], SubQuenceInfo*pInfo)
{
	if (pInfo->m_nEnd == pInfo->m_nStart)
	{
		return Array[pInfo->m_nEnd];
	}
	int nDepartIndex = (pInfo->m_nEnd + pInfo->m_nStart) / 2;
	SubQuenceInfo InfoLeft, InfoRight;
	InfoLeft.m_nEnd = nDepartIndex;
	InfoLeft.m_nStart = pInfo->m_nStart;

	int nMaxSubquenceSum = 0;
	int nMaxLeft = GetMaxSubQuenceSubDepartRecur(Array, &InfoLeft);
	InfoRight.m_nStart = nDepartIndex + 1;
	InfoRight.m_nEnd = pInfo->m_nEnd;
	int nMaxRight = GetMaxSubQuenceSubDepartRecur(Array, &InfoRight);
	/////////////////////////////////////////////////////////
	int nMaxEndLeft = Array[nDepartIndex];
	int nMaxStartRight = Array[nDepartIndex + 1];
	int nSubLeftEnd = 0;
	int nSubRightStart = 0;
	int nLeft = nDepartIndex;
	int nRight = nDepartIndex + 1;
	for (int i = nDepartIndex; i >= pInfo->m_nStart; --i)
	{
		nSubLeftEnd += Array[i];
		if (nSubLeftEnd > nMaxEndLeft)
		{
			nLeft = i;
			nMaxEndLeft = nSubLeftEnd;
		}
	}
	for (int j = nDepartIndex +1; j <= pInfo->m_nEnd; ++j)
	{
		nSubRightStart += Array[j];
		if (nSubRightStart > nMaxStartRight)
		{
			nRight = j;
			nMaxStartRight = nSubRightStart;
		}
	}
	int nMaxMid = nMaxStartRight + nMaxEndLeft;
	int nMax;
	if (nMaxLeft < nMaxRight)
	{
		if (nMaxRight < nMaxMid)
		{
			pInfo->m_nStart = nLeft;
			pInfo->m_nEnd = nRight;
			nMax = nMaxMid;
		}
		else
		{
			pInfo->m_nStart = InfoRight.m_nStart;
			pInfo->m_nEnd = InfoRight.m_nEnd;
			nMax = nMaxRight;
		}
	}
	else
	{
		if (nMaxLeft < nMaxMid)
		{
			pInfo->m_nStart = nLeft;
			pInfo->m_nEnd = nRight;
			nMax = nMaxMid;
		}
		else
		{
			pInfo->m_nEnd = InfoLeft.m_nEnd;
			pInfo->m_nStart = InfoLeft.m_nStart;
			nMax = nMaxLeft;
		}
	}
	return nMax;
}
int  GetMaxSubQuenceSubDepart(int Array[], int nLength, SubQuenceInfo*pInfo)
{
	pInfo->m_nStart = 0;
	pInfo->m_nEnd = nLength - 1;
	return GetMaxSubQuenceSubDepartRecur(Array, pInfo);
}

/////////////////
int main()
{
	int A[20] = { 0 };
	GetRandomArray(A, 20, -100, 100);
	OutPrintIntArray(A, 20, 12);
	SubQuenceInfo Temp;
	int nMaxSum = GetMaxSubQuenceSub(A, 20, &Temp);
	cout << nMaxSum << "   " << Temp.m_nStart << "   " << Temp.m_nEnd << endl;
	int nMaxSum1 = GetMaxSubQuenceSubOrg(A, 20, &Temp);
	cout << nMaxSum1 << "   " << Temp.m_nStart << "   " << Temp.m_nEnd << endl;
	int nMaxSum2 = GetMaxSubQuenceSubDepart(A, 20, &Temp);
	cout << nMaxSum2 << "   " << Temp.m_nStart << "   " << Temp.m_nEnd << endl;
	getchar();

    return 0;
}

