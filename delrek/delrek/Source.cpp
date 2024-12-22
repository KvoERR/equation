#include <iostream>
#include <math.h>
using namespace std;

float eps = 0.0001;
float fi(float x)
{
	return sqrt(1 - 0.4 * pow(x, 2)) - asin(x);
}
float func(float a, float b, float (*fi)(float))
{
	float x = (b + a) / 2;
	if (abs(a - b) <= eps)
		return x;
	if (fi(x)*fi(a)<0)
		return func(a,x,fi);
	else
		return func(x, b, fi);
}
int main()
{
	setlocale(LC_ALL, "RU");
	float a = 0, b = 1;
	cout<< "Корень уравнения = "<<func(a, b, fi);
}