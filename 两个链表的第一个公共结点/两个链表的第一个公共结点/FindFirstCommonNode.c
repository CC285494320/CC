#include<stdio.h>
typedef struct List
{
	int data;
	struct List *Next;
}*PNode;
int List_Length(PNode head)
{
	int length = 0;
	PNode point = head;
	while (NULL != point)
	{
		length++;
		point = point->Next;
	}
	return length;
}

PNode FindFirstCommonNode(PNode head1, PNode head2)
{
	int length1 = List_Length(head1);
	int length2 = List_Length(head2);
	int lengthdif = length1 - length2;
	PNode ListLong = head1;
	PNode ListShort = head2;
	if (lengthdif<0)
	{
		lengthdif = length2 - length1;
		ListLong = head2;
		ListShort = head1;
	}
	while (lengthdif--)
	{
		ListLong = ListLong->Next;
	}
	while ((NULL != ListLong) && (NULL != ListShort) && (ListLong != ListShort))
	{
		ListLong = ListLong->Next;
		ListShort = ListShort->Next;
	}
	return ListLong;
}
int main()
{
	return 0;
}