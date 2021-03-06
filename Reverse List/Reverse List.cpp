// Reverse List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	int value;
	node* next;
};

typedef node* List;

List CreateNode(int value)
{
	List n = new node;
	n->value = value;
	n->next = NULL;
	return n;
}

int ReadValues(List &v, string fileName)
{
	int n, value;
	ifstream fin(fileName);

	fin >> n;
	fin >> value;
	v = CreateNode(value);

	List head = v;

	for (int i = 1; i < n; i++)
	{
		fin >> value;
		head->next = CreateNode(value);
		head = head->next;
	}
	return n;
}
void WriteList(List v)
{
	List head = v;
	while (head)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

List ReverseList1(List v)
{
	List reversedList = CreateNode(v->value);
	v = v->next;
	while (v)
	{
		List nod = CreateNode(v->value);
		nod->next = reversedList;
		reversedList = nod;

		v = v->next;
	}
	return reversedList;
}
void ReverseList2(List &v)
{
	List prev = v;
	v = v->next;
	prev->next = NULL;
	while (v)
	{
		List tmp = v->next;
		v->next = prev;
		prev = v;
		v = tmp;
	}
	v = prev;
}

List MergeLists(List A, List B)
{
	while (A&&B)
	{
		if (A->next != NULL)
			if (A->value < B->value&&
				B->value < A->next->value)
			{
				List bNext = B->next;
				B->next = A->next;
				A->next = B;
				B = bNext;
			}
			else
			{
				A = A->next;
			}
		else
			break;
	}
	while (B)
	{
		A->next = B;
		A = A->next;
		B = B->next;
	}
	return A;
}

void SplitLists(List c,List &a,List &b)
{
	a = c;
	b = c->next;
	c = c->next->next;
	List headA = a;
	List headB = b;
	while (c)
	{
		headA->next = c;
		if (c->next) 
		{
			headB->next = c->next;
			c = c->next;
		}
		else
		{
			headB->next = NULL;
		}
		headA = headA->next;
		headB = headB->next;
		c = c->next;
	}
	headA->next = NULL;
}
int main()
{
	int m, n;
	List v1 = NULL;
	List v2 = NULL;

	m = ReadValues(v1, "a.txt");
	n = ReadValues(v2, "b.txt");

	WriteList(v1);
	WriteList(v2);

	//WriteList(ReverseList1(v1));

	//ReverseList2(v2);
	//WriteList(v2);

	MergeLists(v1, v2);
	List a = NULL;
	List b = NULL;
	WriteList(v1);
	SplitLists(v1, a, b);
	WriteList(a);
	WriteList(b);

	return 0;
}