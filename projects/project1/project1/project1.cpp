// project1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node{
	int value;
	struct Node *next;
};

struct Node* createList(int arr[], int length);
void showList(struct Node *list);
struct Node* swapList(struct Node *list);
bool isOdd(int value);

int _tmain(int argc, _TCHAR* argv[])
{
	const int N = 5;
	struct Node *list;
	int arr[N] = { 2, 4, 6, 8, 10 };
	list = createList(arr, N);
	showList(list);

	cout << "=========================" << endl;
	struct Node *head = swapList(list);
	showList(head);
	system("pause");
	return 0;
}

struct Node* createList(int arr[], int length)
{
	struct Node *head = NULL, *tail = NULL;
	for(int i = 0, size = length; i < size; i++)
	{
		struct Node *node = new struct Node();
		node->value = arr[i];
		node->next = NULL;
		if (tail == NULL)
		{
			tail = node;
			head = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	return head;
}

void showList(struct Node *list)
{
	for (struct Node *head = list; head != NULL; head = head->next)
	{
		cout << head->value << " ";
	}
	cout << endl;
}

struct Node* swapList(struct Node *list)
{
	if (list == NULL || list->next == NULL)
		return list;

	struct Node *oddTail = NULL, *oddHead = NULL, *evenHead = NULL, *curNode = list;
	while (curNode)
	{
		struct Node *tmpNode = curNode;
		curNode = curNode->next;
		if (isOdd(tmpNode->value)) // 当前为奇数
		{
			if (oddTail == NULL) // 第一个奇数
			{
				oddHead = tmpNode;
				oddTail = tmpNode;
				tmpNode->next = NULL; // 这里非常重要，要置空
			}
			else
			{
				tmpNode->next = oddHead;
				oddHead = tmpNode;
			}
		}
		else
		{
			if (evenHead == NULL) // 第一个偶数
			{
				evenHead = tmpNode;
				tmpNode->next = NULL; // 这里非常重要，要置空
			}
			else
			{
				tmpNode->next = evenHead;
				evenHead = tmpNode;
			}
		}
	}

	if (oddTail != NULL) // 找到了奇数
	{
		oddTail->next = evenHead;
		return oddHead;
	}
	else // 没有找到奇数
	{
		return evenHead;
	}
}

bool isOdd(int value)
{
	return value & 0x01 == 1;
}

