#include <iostream>
#include <math.h>
using namespace std;

float eps = 0.0001;
float fi(float x)
{
	return sin(sqrt(1-0.4*pow(x,2)));
}
void func(float x, float (*fi)(float))
{
	while (abs((fi(x) - x)) > eps)
	{
		cout << "xn = " << x << ", xn+1 = " << fi(x)<<endl;
		x = fi(x);
	}
	cout << "Корень уравнения = " << x;
}
int main()
{
	setlocale(LC_ALL, "RU");
	float x = 0;
	func(x,fi);
}