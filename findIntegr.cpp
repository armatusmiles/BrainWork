#include <iostream>

#define f sin
int main()
{
	double a = 3.14;
	double b = 0;
	double n = 1000000;
	double h = (b - a) / n;
	double x[2];
	double sum = 0;
	for (int i = 1; i < n; i++) {
		x[0] = a + (i-1) * h;
		x[1] = a + i * h;
		sum += ((f(x[0]) + f(x[1])) / 2) * h;	
	}
	std::cout << sum;
}