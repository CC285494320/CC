#include<iostream>
using namespace std;
class Temp
{
public:
	Temp()
	{
		n++;
		sum += n;
	}
	static int GetSum()
	{
		return sum;
	}
private:
	static int n;
	static int sum;
};
int Temp::n = 0;
int Temp::sum = 0;

int RetSum(size_t n)
{
	Temp *arr = new Temp[n];
	delete[]arr;
	arr = NULL;
	return Temp::GetSum();
}

int main()
{
	int sum = RetSum(10);
	cout << sum << endl;

	return 0;
}