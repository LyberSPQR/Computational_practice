// 2.2 
// Выполнить задание, используя динамическое выделение памяти для двумерного массива, двумя способами :
// описывая двумерный массив как одномерный, с расчётом смещения элемента массива по линейной формуле;
// описывая двумерный массив как указатель на массив указателей.
// 7. Вывести номера столбцов, все элементы, которых четны. 

#include <iostream>
using namespace std;
void fillingArray(int rows, int columns, int Array[]);
void Array1Output(int rows, int columns, int Array[]);
void findingColumns(int rows, int columns, int Array[]);

int main()
{
	setlocale(LC_ALL, "ru");
	int choice, size;

	cout << "1 - в виде одномерного массива" << endl << "2 - в виде указателя на массив указателей " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		int* Array;
		int  rows, columns;
		
		cout << "Введите количество строк" << endl;
		cin >> rows;
		cout << "Введите количество столбцов" << endl;
		cin >> columns;
		Array = new int[rows * columns];
		
		fillingArray(rows, columns, Array);
		Array1Output(rows, columns, Array);
		findingColumns(rows, columns, Array);

		delete[] Array; // Dynamic Array Deleting
		break;
	}

	case 2:
	{
		int** ArrayPtr;

		int rows, columns,counter = 0;

		cout << "Введите количество строк" << endl;
		cin >> rows;
		cout << "Введите количество столбцов" << endl;
		cin >> columns;

		ArrayPtr = new int* [rows];

		for (int i = 0; i < rows; i++)
			ArrayPtr[i] = new int[columns];

		for (int i = 0; i < rows; i++) // заполнение массива
		{
			for (int j = 0; j < columns; j++)
			{
				cin >> ArrayPtr[i][j];
			}
		}
		cout << endl;
		for (int i = 0; i < rows; i++) // Output Array
		{
			for (int j = 0; j < columns; j++)
			{
				cout << ArrayPtr[i][j] << "  ";
			}
			cout << endl << endl;
		}
	
		for (int j = 0; j < columns; j++) // finding and outputing columns
		{
			for (int i = 0; i < rows; i++)
			{
				if (ArrayPtr[i][j] % 2 == 0)
					counter++;
			}
			if (counter == rows)
				cout << "Номер столбца с чётными элементами: " << j + 1 << endl;
			counter = 0;
		}
		for (int i = 0; i < rows; i++) // Dynamic Array Deleting
			delete[] ArrayPtr[i];
		delete[] ArrayPtr;
		break;
	}
	default:
		cout << "Введено некорректное значение" << endl;
		return 0;
	}
}

void fillingArray(int rows, int columns, int Array[])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> Array[i * columns + j];
		}
	}
	cout << endl << endl;
}
void Array1Output(int rows, int columns, int Array[])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << Array[i * columns + j] << "  ";
		}
		cout << endl << endl;
	}
}
void findingColumns(int rows, int columns, int Array[])
{
	int counter = 0;
	for (int j = 0; j < columns; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			if (Array[i * columns + j] % 2 == 0)
				counter++;
		}
		if (counter == rows)
			cout << "Номер столбца с чётными элементами: " << j + 1 << endl;
		counter = 0;
	}
}