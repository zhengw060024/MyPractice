#pragma once
//hole Index已经放入节点底部
void PushHeap(int Array[], int holeIndex, int nTopIndex, int nValue);
void AjustHeap(int Array[], int holeIndex, int nLength, int nValue);
void makeheap(int Array[], int nLength);
void GetRandomArray(int Array[], int nLength, int nMin, int nMax);
void OutPrintIntArray(int Array[], int nLength, int nLineNum);
void OutPrintHeapArray(int Array[], int nLength);

