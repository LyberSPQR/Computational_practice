// 1.4 Обеспечить перегрузку и шаблоны необходимых функций для выполнения задания с типами элементов массивов char, int, float, double.

#include <iostream>
using namespace std;

const int N = 10;
template<typename T> void massOutput(T mass[N]);
template<typename T> void BubbleSortArray(T mass[N]);
template<typename T> void chooseSorting(T mass[N]);
template<typename T> void fillingMassRand(T mass[N]);

int main()
{
	setlocale(LC_ALL, "Russian");

	enum ChoiceSort { BubbleSort = 1, chooseSort };
	cout << "Выберите способ сортировки массива:" << endl
		<< BubbleSort << " - сортировка массива Пузырьком" << endl
		<< chooseSort << " - сортировка массива Выбором" << endl;
	int choice;
	cin >> choice;

	int choiceFilling;
	enum ChoiceFill { inte = 1, doubl, chr, flot };
	cout << "Выберите тип элементов для заполнения массива:" << endl
		<< inte << " - заполнение массива int" << endl
		<< doubl << " - заполнение массива double" << endl
		<< chr << " - заполнение массива char" << endl
		<< flot << " - заполнение массива float" << endl;

	cin >> choiceFilling;
	switch ((ChoiceFill)choiceFilling)
	{
	case inte:
	{
		int mass[N];
		fillingMassRand(mass);
		cout << "Массив" << endl;
		massOutput(mass);
		if (choice == 1)
		{
			BubbleSortArray(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
		if (choice == 2)
		{
			chooseSorting(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
	}
	break;
	case doubl:
	{
		double mass[N];
		fillingMassRand(mass);
		cout << "Массив" << endl;
		massOutput(mass);

		if (choice == 1)
		{
			BubbleSortArray(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
		if (choice == 2)
		{
			chooseSorting(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
	}
	break;
	case chr:
	{
		char mass[N];
		fillingMassRand(mass);
		cout << "Массив" << endl;
		massOutput(mass);

		if (choice == 1)
		{
			BubbleSortArray(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
		if (choice == 2)
		{
			chooseSorting(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
	}
	break;
	case flot:
	{
		float mass[N];
		fillingMassRand(mass);
		cout << "Массив" << endl;
		massOutput(mass);

		if (choice == 1)
		{
			BubbleSortArray(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
		if (choice == 2)
		{
			chooseSorting(mass);
			cout << "Массив после сортировки" << endl;
			massOutput(mass);
		}
	}
	break;
	default:
	{
		cout << "Введено неверное значение" << endl;
		return 0;
	}

	}
}

template<typename T> void fillingMassRand(T mass[N])
{
	srand(time(NULL));
	for (int i = 0; i <= N - 1; i++)
	{
		mass[i] = rand() % 9 + 97;
	}
}

 void massOutput(int mass[N])
{
	for (int i = 0; i <= N - 1; i++)
	{
		cout << "Array element number " << i << " = " << mass[i] << endl;
	}
}

template<typename T> void BubbleSortArray(T mass[N])
{
	int counterBubble = 0;
	for (int j = N - 1; j >= 0; j--)
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (mass[i] > mass[i + 1])
			{

				int x = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = x;
			}
		}
	}
}

template<typename T> void chooseSorting(T mass[N])
{
	for (int i = 0; i < N - 1; i++)
	{
		int min = mass[i];
		int index_min = i;

		for (int j = i + 1; j < N; j++)
			if (mass[j] < min)
			{
				min = mass[j];
				index_min = j;
			}

		mass[index_min] = mass[i];
		mass[i] = min;
	}
}