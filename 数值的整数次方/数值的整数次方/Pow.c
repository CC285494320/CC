#include<stdio.h>
#include<math.h>
#define ACCURACY 0.0000001

 //0表示结果正常,1表示异常
int flag = 0;
int Equal(double num1,double num2)
{
	if ( (num1 - num2 > -ACCURACY) && (num1 - num2 < ACCURACY) )
	{
		return 1;
	}
	else
		return 0;
}

double PowExponent_1(double base, int exponent)
{
	double result = 1.0;
	int i = 0;
	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}

double PowExponent_2(double base, int exponent)
{
	
	if ( exponent== 0)
	{
		return 1.0;
	}
	if (exponent == 1)
	{
		return base;
	}
	double ret = PowExponent_2(base, exponent >>1);
	ret *= ret;
	if (exponent & 1)
	{
		ret *= base;
	}
	return ret;
}

double Pow(double base, int exponent)
{
	flag = 0;
	double ret = 0.0;
	if ( Equal(base, 0.0) && exponent <=0 )
	{
		flag = 1;
		return 0.0;
	}

	if (exponent < 0)
	{
		//	ret = PowExponent_1(base, -exponent);
		ret = PowExponent_2(base, -exponent);
		ret = 1.0 / ret;
	}
	else
	{
		//	ret = PowExponent_1(base, exponent);
		ret = PowExponent_2(base, exponent);
	}
	return ret;
}

int main()
{
	double ret = Pow(0,-3);
	if ( flag==0 )
	{
		printf("正常:%lf\n", ret);
	}
	else{
		printf("异常:%lf\n", ret);
	}
	return 0;
}