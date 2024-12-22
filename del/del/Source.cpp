#include <iostream>
#include <math.h>
using namespace std;

float eps = 0.0001;
float fi(float x)
{
	return sqrt(1 - 0.4 * pow(x, 2))-asin(x);
}
void func(float x, float a, float b, float (*fi)(float))
{
	cout << "xn = " << x << ", xn+1 = " << (a + b) / 2 << endl;
	if (fi(a) * fi(x) < 0)
	{
		b = x;
	}
	if (fi(b) * fi(x) < 0)
	{
		a = x;
	}
	while (abs((a+b)/2 - x) > eps)
	{
		x = (a + b) / 2;
		if (fi(a) * fi(x) < 0)
		{
			b = x;
		}
		if (fi(b) * fi(x) < 0)
		{
			a = x;
		}
		cout << "xn = " << x << ", xn+1 = " << (a + b) / 2 << endl;
	}
	cout << "Корень уравнения = " << x;
}
int main()
{
	setlocale(LC_ALL, "RU");
	float a=0,b=1,x=0.5;
	func(x, a,b,fi);
}