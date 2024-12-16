#include <iostream>
#include <math.h>
using namespace std;

float eps = 0.0001;
float fi(float x)
{
	return sqrt(1 - 0.4 * pow(x, 2))-asin(x);
}
float pr(float x)
{
	return -((2*x)/(5*sqrt(1-0.4*pow(x,2))))-(1/sqrt(1-pow(x,2)));
}
void func(float x, float (*fi)(float), float (*pr)(float))
{
	while (abs((x - (fi(x) / pr(x)) - x)) > eps)
	{
		cout << "xn = " << x << ", xn+1 = " << x - (fi(x) / pr(x)) << endl;
		x = x-(fi(x)/pr(x));
	}
	cout << "������ ��������� = " << x;
}
int main()
{
	setlocale(LC_ALL, "RU");
	float x = 0.9;
	func(x, fi, pr);
}