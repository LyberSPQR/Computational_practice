// 2.3
// Разбить текст на слова и записать их новую строку в обратном порядке,
// используя связанную динамическую структуру данных – стек.
// Выполнить задание для введенной строки символов.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

struct Node           
{
	char word[20];

	Node* p;
};

void  push2(Node*&, char dn[]);
void pop2(Node*& top);

int main()
{
	Node* top = NULL;
	setlocale(LC_ALL, "ru");
	const int size = 50;
	int choice, num = 0, cntr = 2, letterCounter = 0;
	char** ArrayPtr = new char* [size];
	char arrayword[100];

	cout << "Введите текст: ";
	cin.getline(arrayword, sizeof(arrayword));

	char stringus[size];
	int  wordAmount = 1, counter = 0;

	for (int j = 0; j < size; j++)
	{
		stringus[j] = '\0';
	}

	for (int i = 0; i < size; i++)
		ArrayPtr[i] = new char[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ArrayPtr[i][j] = '\0';
		}
	}

	int j = 0;

	int StrlenArray = strlen(arrayword);
	if (arrayword[StrlenArray - 1] == '.' || arrayword[StrlenArray - 1] == '!' || arrayword[StrlenArray - 1] == '?')
		wordAmount--;
	for (int counter = 0; counter < StrlenArray; counter++)
	{
		if (arrayword[counter] == ' ' || arrayword[counter] == '\0' || arrayword[counter] == ':' || arrayword[counter] == ';' || arrayword[counter] == '!' || arrayword[counter] == '?' || arrayword[counter] == '.' || arrayword[counter] == ',' || arrayword[counter] == '(' || arrayword[counter] == ')' || arrayword[counter] == '-')
		{
			wordAmount++;
			if (arrayword[counter + 1] == ' ' || arrayword[counter + 1] == ':' || arrayword[counter + 1] == ';' || arrayword[counter + 1] == '!' || arrayword[counter + 1] == '?' || arrayword[counter + 1] == '.' || arrayword[counter + 1] == ',' || arrayword[counter + 1] == '(' || arrayword[counter + 1] == ')' || arrayword[counter + 1] == '-')
			{
				counter++;
			}
		}
		
	}

	cout << "WordAmount = " << wordAmount << endl;

	for (int i = 0; i < wordAmount; i++) // заполнение массива
	{
		while (arrayword[counter] != ' ' && arrayword[counter] != '\0' && arrayword[counter] != ':' && arrayword[counter] != ';' && arrayword[counter] != '!' && arrayword[counter] != '?' && arrayword[counter] != '.' && arrayword[counter] != ',' && arrayword[counter] != '(' && arrayword[counter] != ')' && arrayword[counter] != '-')
		{
			ArrayPtr[i][j] = arrayword[counter];
			j++;
			if ( arrayword[counter + 1] == ':' || arrayword[counter + 1] == ';' || arrayword[counter + 1] == '!' || arrayword[counter + 1] == '?' || arrayword[counter + 1] == '.' || arrayword[counter + 1] == ',' || arrayword[counter + 1] == '(' || arrayword[counter + 1] == ')' || arrayword[counter + 1] == '-')
				counter++;
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
		char* word = new char[size];

		for (int j = 0; j < size; j++)
		{
			if ((int(ArrayPtr[i][j]) >= 65 && int(ArrayPtr[i][j]) <= 90) || (int(ArrayPtr[i][j]) >= 97 && int(ArrayPtr[i][j]) <= 122))
			{
				stringus[j] = ArrayPtr[i][j];
				stringus[j + 1] = '\0';
			}
		}

		for (int j = 0; j < size; j++)
		{
			word[j] = stringus[j];
		}

		push2(top, word);
	}

	char ReversedText[100];
	for (int j = 0; j < 100; j++)
	{
		ReversedText[j] = '\0';
	}

	while (top != NULL)
	{
		strcat(ReversedText, top->word);
		strcat(ReversedText, " ");
		pop2(top);
	}

	cout << endl << "ReversedText: " << ReversedText << endl;

	for (int i = 0; i < size; i++)
	{
		delete[] ArrayPtr[i];
	}

	delete[] ArrayPtr;

	return 0;
}

void push2(Node*& top, char dn[])	// функция занесения элемента в вершину стека
{                  //    top – указатель начала стека
	Node* pv = new Node; // выделение памяти для элемента стека
	for (int i = 0; i < 20; i++)
	{
		pv->word[i] = dn[i]; //*(pv).word[i]
	}
	pv->p = top;     // связываем новый элемент с предыдущим 
	top = pv;        // меняем адрес начала стека
}

void pop2(Node*& top)
{                   //    top – указатель начала стека
	Node* pv = top;
	top = top->p;          // меняем адрес начала стека
	delete pv;             // освобождение памяти
}
