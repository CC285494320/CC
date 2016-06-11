#include<iostream>
using namespace std;
#include<assert.h>
struct ListNode
{
	int _data;
	ListNode* pNext;
};
void AddTail(ListNode **pHead,int value)
{
	assert(pHead);
	ListNode* NewNode = new ListNode();
	NewNode->_data = value;
	NewNode->pNext = NULL;
	if (NULL == *pHead)
	{
		*pHead = NewNode;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (NULL != pNode->pNext)
		{
			pNode = pNode->pNext;
		}
		pNode->pNext = NewNode;
	}
}

void RemoveNode(ListNode **pHead,int value)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	if ((*pHead)->_data ==value)
	{
		ListNode *DelNode = *pHead;
		*pHead = (*pHead)->pNext;
		delete DelNode;
	}
	else
	{
		ListNode *pNode = *pHead;
		while ((pNode->pNext != NULL) && (pNode->pNext->_data) != value)
		{
			pNode = pNode->pNext;
		}
		if ((pNode->pNext != NULL) && (pNode->pNext->_data == value))
		{
			ListNode* DelNode = pNode->pNext;
			pNode->pNext = pNode->pNext->pNext;
			delete DelNode;
		}
	}
}
int main()
{
	ListNode*head = NULL;
	AddTail(&head, 1);
	AddTail(&head, 2);
	AddTail(&head, 3);
	AddTail(&head, 4);
	RemoveNode(&head, 3);
	return 0;
}