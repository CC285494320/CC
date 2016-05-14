#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct List *PNode;
struct List
{
	PNode next;
	int data;
};

void DelNode(PNode *Phead,PNode delnode)
{
	assert(Phead);
	if ((NULL == *Phead) || (NULL == delnode))
	{
		return;
	}
	if (delnode->next != NULL)
	{
		PNode point = delnode->next;
		delnode->data = point->data;
		delnode->next = point->next;
		free(point);
	}
	else if (delnode == *Phead)
	{
		*Phead = NULL;
		free(delnode);
	}
	else
	{
		PNode point = *Phead;
		while (point->next!=delnode)
		{
			point = point->next;
		}
		point->next = NULL;
		free(delnode);
	}
}

int main()
{
	return 0;
}