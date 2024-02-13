#include <iostream>
#include <cmath>
using namespace std;

void countingFunc(double func,double x,int n, double constX, int i);

int main()
{

	double func = 0, x = 1, constX = 0.20;
	int degree, number,n,i = 0;
	cout << "Enter n " << endl;
	cin >> n;

	countingFunc(func, x, n, constX, i);
}

void countingFunc(double func, double x, int n, double constX, int i)
{
	for (; x < 2.0; i++)
	{
		x = 1;
		x = x + i * constX;

		if (x <= 2.0)
		{
			cout << "x num " << i + 1 << " = " << x << endl;
			for (int N = n; N >= 0; N--)
			{
				func = func + ((9 - N) * pow(x, N));
			}
			cout << "Func number " << i + 1 << " = " << func << endl;
		}
		func = 0;
	}
}