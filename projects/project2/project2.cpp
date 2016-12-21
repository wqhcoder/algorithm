// project2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

void swap(char* str, int i, int j)
{
	char ch;
	ch = str[i];
	str[i] = str[j];
	str[j] = ch;
}

void permutation(char* str, int k, int n) 
{
	if (k == n - 1)
	{
		cout << str << endl;
		return;
	}

	for (int i = k; i < n; i++)
	{
		swap(str, k, i);
		permutation(str, k + 1, n);
		swap(str, k, i);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s[] = "abc";
	char* str = s;
	permutation(str, 0, strlen(str));

	system("pause"); 
	return 0;
}

