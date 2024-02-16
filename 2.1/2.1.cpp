// 2.1 . Дан массив целых чисел, содержащий n элементов Элементы массива циклически сдвинуть на К позиций влево.

#include <iostream>
using namespace std;
void massOutput(int n, int mass[]);
void massShift(int n,int k, int mass[]);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива" << endl;
	int n;
	cin >> n;
	cout << "Введите сдвиг массива" << endl;
	int k;
	cin >> k;
	if (k >= n)
	{
		cout << "Incorrect shift";
		return 0;
	}
	int* mass = new int[n + k];
	for (int i = 0; i < n; i++)
	{
		mass[i] = i;
	}

	cout << "Массив до сдвига" << endl ;
	massOutput(n, mass);
	massShift( n, k,mass);
	cout << "Массив после сдвига" << endl;
	massOutput(n, mass);
	
delete[] mass;
}

void massOutput(int n, int mass[])
{
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << endl;
	}
}
void massShift(int n,int k, int mass[])
{
	for (int i = 0; i < n; i++)
	{
		int g = mass[i];
		mass[i] = mass[i + k];
		if (i < k)
		{
			int a = n  + i;
			mass[a] = g;
		}
	}
}