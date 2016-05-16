#include<stdio.h>
#include<assert.h>
typedef struct List
{
	int data;
	struct List*Next;
}*PNode;
//ÄæÐòÁ´±í
void InvertList(PNode *Phead)
{
	assert(Phead);
	if ((NULL == *Phead) || (NULL == (*Phead)->Next))
	{
		return;
	}
	PNode preNode = *Phead;
	PNode curNode = preNode->Next;
	PNode nextNode = curNode->Next;
	while (NULL != nextNode)
	{
		curNode->Next = preNode;
		preNode = curNode;
		curNode = nextNode;
		nextNode = nextNode->Next; 
	}
	curNode->Next = preNode;
	(*Phead)->Next = NULL; 
	*Phead = curNode;     
}

//Ã°ÅÝÅÅÐòÁ´±í
void BubbleSort(PNode head)
{
	if ((NULL == head) || (NULL == head->Next))
	{
		return;
	}
	PNode tailNode = NULL;
	PNode nextNode = NULL;
	PNode curNode = NULL;
	PNode point = NULL;
	while (head->Next != tailNode)
	{
		curNode = head;
		nextNode = curNode->Next;
		while (nextNode != tailNode)
		{
			if (curNode->data > nextNode->data)
			{
				int tmp = curNode->data;
				curNode->data = nextNode->data;
				nextNode->data = tmp;
			}
			curNode = curNode->Next;
			nextNode = nextNode->Next;
		}
		tailNode = curNode;
	}
}

//Á¬½ÓÓÐÐòÁ´±í
PNode LinkOrderList(PNode head1, PNode head2)
{
	if (NULL == head1)
	{
		return head2;
	}
	if (NULL == head2)
	{
		return head1;
	}
	PNode pNode1 = head1;
	PNode pNode2 = head2;
	PNode pNewhead = NULL;
	PNode pNode3 = NULL;
	if (head1->data < head2->data)
	{
		pNewhead = pNode1;
		pNode1 = pNode1->Next;
	}
	else
	{
		pNewhead = pNode2;
		pNode2 = pNode2->Next;
	}
	pNode3 = pNewhead;
	while ((NULL != pNode1) && (NULL != pNode2))
	{
		if (pNode1->data < pNode2->data)
		{
			pNode3->Next = pNode1;
			pNode3 = pNode1;
			pNode1 = pNode1->Next;
		}
		else
		{
			pNode3->Next = pNode2;
			pNode3 = pNode2;
			pNode2 = pNode2->Next;
		}
	}
	if (NULL == pNode1)
	{
		pNode3->Next = pNode2;
	}
	if (NULL == pNode2)
	{
		pNode3->Next = pNode1;
	}
	return pNewhead;
}
int main()
{
	return 0;
}