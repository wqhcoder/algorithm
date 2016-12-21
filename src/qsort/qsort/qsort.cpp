// qsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Test1.h"
#include "Test2.h"
#include <random>
#include <time.h>
#include <stdlib.h>
#include <chrono>


#include "B.h"

using namespace std;
using namespace chrono;
const int NUMBER = 3000000;

void show(int* num, int n)
{
	for (int i = 0; i <= n; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
}

void swap(int* num, int begin, int end)
{
	int temp = num[begin];
	num[begin] = num[end];
	num[end] = temp;
}

int getPivot(int* num, int begin, int end)
{
	//int i = begin, j = end, pivot = num[begin];
	//while (i < j)
	//{
	//	
	//	while (i < j && num[i] < pivot) i++;
	//	swap(num, i, j);
	//	while (i < j && num[j] > pivot) j--;
	//	swap(num, i, j);
	//}
	//num[i] = pivot;
	//return i;

	int i = begin, j = end, key = num[begin];
	while (i < j)
	{
		while (i < j && num[j] > key) j--;
		if (i < j) num[i++] = num[j];
		while (i < j && num[i] < key) i++;
		if (i < j) num[j--] = num[i];
	}
	num[i] = key;
	return i;
}

void quickSort(int* num, int begin, int end)
{
	if (num == nullptr || begin >= end) return;
	int pos = getPivot(num, begin, end);
	quickSort(num, begin, pos - 1);
	quickSort(num, pos + 1, end);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num[NUMBER];
	srand(time(0));
	for (int i = 0, size = NUMBER; i < size; i++)
	{
		num[i] = (int) rand() % 500000;
	}

	cout << "====================" << endl;
	steady_clock::time_point begin = steady_clock::now();
	quickSort(num, 0, NUMBER - 1);
	steady_clock::time_point end = steady_clock::now();
	cout << "results time = " << duration_cast<chrono::milliseconds>(end - begin).count() << endl;
	//show(num, NUMBER - 1);

	system("pause");
	return 0;
}

