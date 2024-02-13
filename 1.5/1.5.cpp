// 1.5.cpp Описать функции для выполнения следующего задания двумя способами: используя механизм рекурсии и через цикл. 
// Найти n-й член числовой последовательности чисел Фибоначчи.

#include <iostream>
using namespace std;

int fibonacciCauntingRecursion(int FibNumber);
void fibonacciCauntingCycle(int n);

int main()
{
	int n, choice;
	setlocale(LC_ALL, "ru");
	cout << "Enter number of Fibonacci Num" << endl;
	cin >> n;
	if (n < 1)
	{
		cout << "incorrect number was entered";
		return 0;
	}

	cout << "Выберите алгоритм: " << endl << "1 - Рекурсия" << endl << "2 - Цикл" << endl;
	cin >> choice;
	if (choice == 1)
	{
		for (int i = 0; i < n; i++)
		{
			int c = fibonacciCauntingRecursion(i);
			if (i == n - 1)
			{
				cout << "Fibonacci Num number: " << i + 1 << " = " << c << endl;
			}
		}
	}
	if (choice == 2)
	{
		fibonacciCauntingCycle(n);
	}
}

int fibonacciCauntingRecursion(int FibNumber)
{
	if (FibNumber == 0)
		return 0;
	if (FibNumber == 1)
		return 1;
	return fibonacciCauntingRecursion(FibNumber - 1) + fibonacciCauntingRecursion(FibNumber - 2);
}

void fibonacciCauntingCycle(int n)
{
	int a = 0, b = 1, c = 0;
	for (int i = 0; i < n; i++)
	{
		if (n == 1)
		{
			cout << "Fibonacci Num number: " << 1 << " = " << 0 << endl;
			break;
		}

		if (n == 2)
		{
			cout << "Fibonacci Num number: " << 2 << " = " << 1 << endl;
			break;
		}

		if (i > 1)
		{
			c = a + b;
			if (i + 1 == n)
				cout << "Fibonacci Num number: " << i + 1 << " = " << c << endl;
			a = b;
			b = c;
		}
	}
}

