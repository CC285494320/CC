#include<iostream>
using namespace std;
typedef int DataType;
struct Node
{
	Node(int data = 0)
		: pNextNode(NULL)
		, pPreNode(NULL)
		, _data(data)
	{

	}
	Node* pNextNode;
	Node* pPreNode;
	DataType _data;

};

class DList
{
	friend ostream& operator<<(ostream &_cout,const DList& _list);
public:
	void Delete_pos(Node* pos);
	DList()
		: pHead(NULL)
		, pTail(NULL)
		, _size(0)
	{

	}
	
	void PushBack(DataType data)
	{
		Node *pNode = new Node(data);
		if (NULL == pHead)
		{
			pHead = pNode;
			pTail = pNode;
		}
		else
		{
			pTail->pNextNode = pNode;
			pNode->pPreNode = pTail;
			pTail = pNode;
		}
		_size++;
	}

	void PopBack()
	{
		if (NULL == pHead)
		{
			return;
		}
		else if (NULL == pHead->pNextNode)
		{
			delete pHead;
			pHead = NULL;
			pTail = NULL;
		}
		else
		{
			pTail = pTail->pPreNode;
			delete  pTail->pNextNode;
			pTail->pNextNode = NULL;
		}
		_size--;
	}
    
	Node* Find(int data)
	{
		Node* pNode = pHead;
		while (NULL != pNode && pNode->_data != data)
		{
			pNode = pNode->pNextNode;
		}
		return pNode;
	}

	void PushFront(int data)
	{
		Node* pNode = new Node(data);
		if (NULL == pHead)
		{
			pHead = pTail = pNode;
		}
		else
		{
			pNode->pNextNode = pHead;
			pHead->pPreNode = pNode;
			pHead = pNode;
		}
		_size++;
	}
////////////////////////////////////////////////////////////////////////////////////
	void PopFront()
	{
		if (NULL == pHead)
		{
			return;
		}
		else if (NULL ==pHead->pNextNode)
		{
			delete pHead;
			pHead = pTail = NULL;
		}
		else
		{
			pHead = pHead->pNextNode;
			delete pHead->pPreNode;
			pHead->pPreNode = NULL;
		}
		_size--;
	}
	void Insert_Pos(Node* pos,int data)
	{
		if (NULL == pos)
		{
			return;
		}
		else if (pos ==pTail)
		{
			PushBack(data);
		}
		else
		{
			Node* pNode = new Node(data);
			pNode->pNextNode = pos->pNextNode;
			pos->pNextNode->pPreNode = pNode;
			pNode->pPreNode = pos;
			pos->pNextNode = pNode;
			_size++;
		}
	}


	void Print_negative()
	{
		cout << _size << endl;
		Node* pNode = pTail;
		while (NULL != pNode)
		{
			cout << pNode->_data<<" ->";
			pNode = pNode->pPreNode;
		}
		cout << " NULL" << endl;
	}
	void Empty()
	{
		Node* pNode = pHead;
		while (NULL != pNode)
		{
			pHead = pNode->pNextNode;
			delete pNode;
			pNode = pHead;
		}
		pTail = NULL;
		_size = 0;
	}

	~DList()
	{
		Empty();
	}
private:
	Node* pHead;
	Node* pTail;
	size_t  _size;
};

ostream& operator<<(ostream &_cout, const DList& _list)
{
	cout << _list._size << endl;
	Node* pNode = _list.pHead;
	while (NULL != pNode)
	{
		cout << pNode->_data <<" ->" ;
		pNode = pNode->pNextNode;
	}
	cout << " NULL" << endl;
	return _cout;
}


void DList:: Delete_pos(Node* pos)
{
	if (NULL == pos)
	{
		return;
	}
	else if (pos == pHead)
	{
		PopFront();
	}
	else if (pos == pTail)
	{
		PopBack();
	}
	else
	{
		Node*pNode = pos;
		pos->pPreNode->pNextNode = pos->pNextNode;
		pos->pNextNode->pPreNode = pos->pPreNode;
		delete pos;
		_size--;
	}
}
int main()
{
	DList list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushFront(-1);
	Node* find = list.Find(1);
	list.Delete_pos(find);
	cout << list;
	list.Print_negative();
}