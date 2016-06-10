#include<iostream>
using namespace std;
class C
{
public:
	C(char *pdata="")
	{
		if (NULL == pdata)
		{
			_pData = new char[1];
			*_pData = '\0';
		}
		else
		{
			_pData = new char[strlen(pdata)+1];
			strcpy(_pData, pdata);
		}
	}
	C(const C& str)
	{
		_pData = new char[strlen(str._pData) + 1];
		strcpy(_pData, str._pData);
	}

	void Print()
	{
		cout << _pData << endl;
	}
	C& operator=(const C& str);
	~C()
	{
		if (NULL != _pData)
		{
			delete[]_pData;
			_pData = NULL;
		}

	}
private:
	char *_pData;
};

//////////////////////////////////////////////////////////////////////
// 1
C& C::operator=(const C& str)
{
	if (this != &str)
	{
		char *tmp = new char[strlen(str._pData) + 1];
		strcpy(tmp,str._pData);
		delete[]_pData;
		_pData = tmp;
	}
	return *this;
}

//////////////////////////////////////////////////////////////////////
//  2
C& C::operator=(const C& str)
{
	if (this != &str){
		C tmp(str);
		std::swap(_pData, tmp._pData);
	}
	return *this;
}
void fun()
{
	C c1(NULL);
	C c2("123");
	C c3(c1);
	c1 = c2;
	c1.Print();
}
int main()
{
	fun();
	return 0;
}