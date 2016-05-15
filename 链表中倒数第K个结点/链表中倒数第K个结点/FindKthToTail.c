
#include<stdio.h>
typedef struct ListNode
{
	int data;
	struct ListNode *Next;
}*PNode;
PNode FindKthToTail(PNode *head, int k)
{
	if ( (NULL == head) || (k <= 0) )
	{
		return NULL;
	}
	PNode Apoint = head;
	PNode Bpoint = NULL;
	for (int i = 0; i < k-1; i++)
	{
		if (NULL != Apoint->Next)
		{
			Apoint = Apoint->Next;
		}
		else
			return NULL;
	}
	Bpoint = head;
	while (NULL != Apoint->Next)
	{
		Apoint = Apoint->Next;
		Bpoint = Bpoint->Next;
	}
	return Bpoint;
}