#include<stdio.h>
typedef struct Node
{
	Node(int _data=0)
	{
		data = _data;
		Next = NULL;
	}
	int data;
	struct Node* Next;
	
}*PNode;

PNode JosephCircle(PNode head, int k)
{
	if (NULL == head || k <= 0)
	{
		return NULL;
	}
	PNode pCurNode = head;
	PNode pDelNode = NULL;
	while (pCurNode->Next != pCurNode)
	{
		int step = k;
		while (--step)
		{
			pCurNode = pCurNode->Next;
		}
		pDelNode = pCurNode->Next;
		pCurNode->data = pDelNode->data;
		pCurNode->Next = pDelNode->Next;
		delete(pDelNode);
	}
	pCurNode->Next = NULL;
	return pCurNode;
}

PNode CreatCircleList(int n)
{
	if (n < 0)
	{
		return NULL;
	}
	PNode Head = new Node(0);
	PNode Tail = Head;
	int k = 1;
	while (k<=n)
	{
		PNode node = new Node(k);
		Tail->Next = node;
		Tail = node;
		k++;
	}
	Tail->Next = Head;
	return Head;
}

int main()
{
	int n = 5;
	int del = 3;
	PNode Head = CreatCircleList(n);
	PNode node = JosephCircle(Head, del);
	printf("%d\n", node->data);
	return 0;
}