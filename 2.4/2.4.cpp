// 2.4
// Разбить текст на слова и записать их новую строку,
// используя связанную динамическую структуру данных – очередь.
// Выполнить задание для введенной строки символов.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>

using namespace std;

struct Node  // описание элемента очереди
{
	char word[20];
	Node* p;   // указатель на следующий элемент очереди
};

void   first2(Node*&, char wordus[]);
void   add2(Node*& end, char wordus[]);
void   vyvod_ochered(Node* top);

void    del2(Node*& top);

int main()
{
	Node* top = NULL, * end;

	setlocale(LC_ALL, "ru");
	const int size = 50;
	int  num = 0, cntr = 2, queueCouner = 0, progCounter = 0, letterCounter = 0;
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

		for (int j = 0; word[j] != '\0'; j++)
		{
			num = j;
		}

		int wordLong = strlen(word);
		char wordus[] = { 'x','y','z' };

		for (int j = num; j >= num - 3; j--)
		{
			if (word[j] == wordus[cntr])
			{
				cntr--;
				letterCounter++;
			}
		}
		cntr = 2;

		if (letterCounter == 3)
		{
			progCounter++;
			if (queueCouner == 0)
			{
				first2(top, word);
				end = top;
			}

			if (queueCouner > 0)
			{
				add2(end, word);
			}
			queueCouner++;
		}
		letterCounter = 0;
	}

	if (progCounter < 1)
	{
		cout << "No such words";
		return 0;
	}

	char newString[100];
	for (int j = 0; j < 100; j++)
	{
		newString[j] = '\0';
	}

	while (top)
	{
		strcat(newString, top->word);
		strcat(newString, " ");
		del2(top);
	}

	cout << endl << "newString: " << newString << endl;

	for (int i = 0; i < size; i++)
	{
		delete[] ArrayPtr[i];
	}
	delete[] ArrayPtr;

	return 0;
}

// функция занесения первого элемента в очередь
void first2(Node*& top, char wordus[])
{
	top = new Node;        //  выделение памяти
	for (int i = 0; i < 20; i++)
	{
		top->word[i] = wordus[i];
	}
	top->p = NULL;
}
// функция занесения элемента в конец очереди
// end - адрес последнего элемента очереди
void add2(Node*& end, char wordus[])
{
	Node* pv = new Node;      //  выделение памяти
	for (int i = 0; i < 20; i++)
	{
		pv->word[i] = wordus[i];
	}
	pv->p = NULL;
	// связываем с предыдущим элементом очереди
	end->p = pv;
	end = pv;           //  меняем адрес последнего элемента
}

void del2(Node*& top)	// функция удаления элемента из начала очереди
{               //    top - указатель начала очереди
	Node* pv;  //  функция аналогична функции для стека
	pv = top;
	top = top->p;      // меняем адрес начала очереди
	delete pv;         // освобождение памяти
}
