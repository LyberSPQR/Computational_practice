//1.6 
#include <iostream>
#include <iomanip>
using namespace std;

void findingSqrt(double x1, double x2, double b);
void findingSqrt2(double x1, double x2, double b, double s);

int main()
{
	double b = 1, b2 = 2 , coun = 0;
	double  s = 3;
	double x1 = b;
	double x2 = 20;
	
	findingSqrt(x1, x2, b);

	findingSqrt2(x1, x2, b2, s);
}

void findingSqrt(double x1, double x2, double b)
{
	
	int coun = 0;
	while (abs(pow(x2 + 3.0, 3) - 8.0) > 1e-6)
	{
		x2 = x1 - double((pow(x1 + 3.0, 3) - 8.0) / (3.0 * pow(x1 + 3.0, 2)));

		double func = abs(pow(x2 + 3.0, 3) - 8.0);

		x1 = x2;

		coun++;
		cout << " Func= " << func << endl;
		cout << "X= " << x2 << endl;
		cout << " K_iter= " << coun << endl;
	}
	cout << endl << endl;
	
}

void findingSqrt2(double x1, double x2, double b, double s)
{

	int coun = 0;
	while (abs(cos(3.14 * x2) - pow(x2, s)) > 1e-6)
	{
		x2 = x1 + (cos(3.14 * x1) - pow(x1, s)) / (3.14 * sin(3.14 * x1) + s * pow(x1, s - 1));
		double func = abs(cos(3.14 * x2) - pow(x2, s));
		x1 = x2;

		coun++;
		cout << " (b)(Func= " << func << endl;
		cout << "(b) X= " << x2 << endl;
		cout << " (b) K_iter= " << coun << endl;
	}
}