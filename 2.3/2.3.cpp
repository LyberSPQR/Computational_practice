// 1.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main()
{

	setlocale(LC_ALL, "ru");
	int choice, size = 50, wordSize = 15;
	char** ArrayPtr = new char* [size];
	char arrayword[100];

	cout << "Введите текст: ";
	cin.getline(arrayword, sizeof(arrayword));

	char stringus[15];
	int  wordAmount = 1, counter = 0;
	stack <const char*> mystack;

	for (int j = 0; j < 15; j++)
	{
		stringus[j] = '\0';
	}

	for (int i = 0; i < size; i++)
		ArrayPtr[i] = new char[10];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			ArrayPtr[i][j] = '\0';
		}
	}

	int j = 0;

	for (int counter = 0; counter < strlen(arrayword); counter++)
	{
		if (arrayword[counter] == ' ')
			wordAmount++;
	}

	cout << "WordAmount = " << wordAmount << endl;

	for (int i = 0; i < wordAmount; i++) // заполнение массива
	{
		while (arrayword[counter] != ' ' && arrayword[counter] != '\0' && arrayword[counter] != ':' && arrayword[counter] != ';' && arrayword[counter] != '!' && arrayword[counter] != '?' && arrayword[counter] != '.' && arrayword[counter] != ',' && arrayword[counter] != '(' && arrayword[counter] != ')' && arrayword[counter] != '-')

		{
			ArrayPtr[i][j] = arrayword[counter];
			j++;
			counter++;
		}
		j = 0;
		counter++;
	}

	for (int i = 0; i < wordAmount; i++) // Output Array
	{
		cout << endl << " Word: ";
		for (int j = 0; ArrayPtr[i][j] != '\0'; j++)
		{
			cout << ArrayPtr[i][j];
		}
		cout << " " << endl;
	}

	for (int i = 0; i < wordAmount; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((int(ArrayPtr[i][j]) >= 65 && int(ArrayPtr[i][j]) <= 90) || (int(ArrayPtr[i][j]) >= 97 && int(ArrayPtr[i][j]) <= 122))
			{
				stringus[j] = ArrayPtr[i][j];
				stringus[j + 1] = '\0';
			}
		}

		char* word = new char[10];
		for (int j = 0; j < 10; j++)
		{
			word[j] = stringus[j];
		}

		mystack.push(word);
	}
	char reversedText[100];
	for (int j = 0; j < 100; j++)
	{
		reversedText[j] = '\0';
	}

	while (!mystack.empty())
	{
		strcat(reversedText, mystack.top());
		strcat(reversedText, " ");
		mystack.pop();
	}

	cout << endl << "newString: " << reversedText << endl;

	for (int i = 0; i < size; i++)
	{
		delete[] ArrayPtr[i];
	}

	delete[] ArrayPtr;
	return 0;
}
