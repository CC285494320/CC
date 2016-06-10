#include<assert.h>
#include<iostream>
using namespace std;
class String
{
public:
	String(char* str = "")
	{
		if (NULL == str)
		{
			_Pdata = new char[1 + 4];
			*(int *)_Pdata = 1;
			_Pdata += 4;
			*_Pdata = '\0';
		}
		else
		{
			_Pdata = new char[strlen(str) + 1 + 4];
			*(int *)_Pdata = 1;
			_Pdata += 4;
			strcpy(_Pdata, str);
		}
	}
	
	String(const String& Str)
	{
		_Pdata = Str._Pdata;
		++GetRef();
	}

	
	String& operator=(const String& Str)
	{
		if (_Pdata != Str._Pdata)
		{
			Reverse();
			_Pdata = Str._Pdata;
			++GetRef();
		}
		return *this;
	}

	
	char& operator[](int index)
	{
		assert(index >= 0);
		if (GetRef() > 1)
		{
			char* tmp = new char[strlen(_Pdata) + 1 + 4];
			strcpy(tmp + 4, _Pdata);
			*(int *)tmp = 1;
			--GetRef();
			_Pdata = tmp + 4;
		}
		return _Pdata[index];
	}
	
	const char& operator[](int index)const
	{
		assert(index >= 0);
		return _Pdata[index];

	}
	
	~String()
	{
		Reverse();

	}

	void Print()
	{
		cout << GetRef() << endl;
		cout << _Pdata << endl;
	}

private:
	int &GetRef()
	{
		return *(int*)(_Pdata - 4);
	}
	void Reverse()
	{
		if (--GetRef() == 0)
		{
			delete[](_Pdata - 4);
		}
	}
private:
	char* _Pdata;
};
int main()
{
	String s1("abc");
	String s2(s1);
	String s3;
	s3.Print();
	s3 = s1;
	s1.Print();
	s2.Print();
	s3.Print();
	return 0;
}