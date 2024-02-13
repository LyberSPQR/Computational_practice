// 1.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
const int N = 10;

int mass[N];

void massOutput();
void fillingMassIncrease();
void fillingMassDecrease();
void fillingMassRand();
void BubbleSortArray();
void chooseSorting();

int main()
{
	
	setlocale(LC_ALL, "Russian");
	int choice;
	enum Choice { increase = 1, decrease, rand };
	cout << "Выберите способ заполнения массива:" << endl
		<< increase << " - заполнение массива возрастающими числами" << endl
		<< decrease << " - заполнение массива убывающими числами" << endl
		<< rand << " - заполнение массива случайными числами" << endl;
	cin >> choice;
	switch ((Choice)choice)
	{
	case increase:
		fillingMassIncrease();
		break;
	case decrease:
		fillingMassDecrease();
		break;
	case rand:
		fillingMassRand();
		break;
	default:
		cout << "Введено неверное значение" << endl;
		return 0;
	}
	
	massOutput();

	enum ChoiceSort { BubbleSort = 1, chooseSort};
	cout << "Выберите способ сортировки массива:" << endl
		<< BubbleSort << " - сортировка массива Пузырьком" << endl
		<< chooseSort << " - сортировка массива Выбором" << endl;
	cin >> choice;
	switch ((ChoiceSort)choice)
	{
	case BubbleSort:
		BubbleSortArray();
		break;
	case chooseSort:
		chooseSorting();
		break;
	
	default:
		cout << "Введено неверное значение" << endl;
		return 0;
	}

	massOutput();

}

void fillingMassIncrease()
{

	for (int i = 0; i <= N - 1; i++)
	{
		mass[i] = i;
	}
}
void fillingMassDecrease()
{
	int n = N;
	for (int i = 0; i <= N - 1; i++)
	{
		
		mass[i] = n;
		n--;
		
	}
}
void fillingMassRand()
{
	srand(time(NULL));
	for (int i = 0; i <= N - 1; i++)
	{
		
		mass[i] = rand() % 9;
	}
}
void massOutput()
{
	for (int i = 0; i <= N - 1; i++)
	{
		cout << "Array element number " << i << " = " << mass[i] << endl;
	}
}
void BubbleSortArray()
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
	/*int numberСomparisons = (N * N - N) / 2;
	int numberPermutations = (N * N - N) / 4;
	cout << "numberPermutations: " << numberPermutations << endl;
	cout << "numberСomparisons: " << numberСomparisons << endl;*/
	
	
}
void chooseSorting()
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
	/*int numberСomparisons = (N * N - N) / 2;
	cout << "numberСomparisons: " << numberСomparisons << endl;
	double y = 0.577216;
	double numberPermutations = N * (log(N) + y);
	cout << "numberPermutations: " << int(numberPermutations) << endl;*/
}