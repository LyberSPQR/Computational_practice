//7. Определить, какую наибольшую степень числа 7 можно вычислить, пользуясь типом signed short.
#include <iostream>
using namespace std;
int findingMaxNumber(int specifiedNumber);
int findingMaxDegree(int number, int maxNumber, int specifiedNumber);
void findingMaxNumberPtr(int specifiedNumber, int* ptr1);
void findingMaxDegreePtr(int number, int maxNumber, int specifiedNumber, int* degree);
void findingMaxNumberRef(int specifiedNumber, int& maxNumber);
void findingMaxDegreeRef(int number, int maxNumber, int specifiedNumber, int& degree);

int main()
{
    int specifiedNumber = 7, number = 0, degree = 0, maxNumber = 0, maxDeg = 0, p = 0, v = 0;
    setlocale(LC_ALL, "Russian");
    int choice;
    int* ptr = &p;
    int* ptr1 = &v;
    int num = 0, numPtr = 0, numRef = 0;
    enum Choice { ret = 1, pointer, ref };
    cout << "Выберите способ выполнения программы:" << endl
        << ret << " - через return" << endl
        << pointer << " - через указатели" << endl
        << ref << " - через ссылки" << endl;
    cin >> choice;
    switch ((Choice)choice)
    {
    case ret:
    {
        maxNumber = findingMaxNumber(specifiedNumber);
        degree = findingMaxDegree(number, maxNumber, specifiedNumber);

        int num = pow(specifiedNumber, degree - 1);
        cout << "Max degree within the limit: " << degree - 1 << endl;
        cout << "Number whith this degree: " << num;
    }
        break;
    case pointer:
    {
        findingMaxNumberPtr(specifiedNumber, ptr1);
        findingMaxDegreePtr(number, *ptr1, specifiedNumber, ptr);

        int numPtr = pow(specifiedNumber, *ptr - 1);
        cout << "Max degree within the limit: " << *ptr - 1 << endl;
        cout << "Number whith this degree: " << numPtr;
    }
        break;
    case ref: 
    {
        findingMaxNumberRef(specifiedNumber, maxNumber);
        findingMaxDegreeRef(number, maxNumber, specifiedNumber, maxDeg);

        int numRef = pow(specifiedNumber, maxDeg - 1);
        cout << "Max degree within the limit: " << maxDeg - 1 << endl;
        cout << "Number whith this degree: " << numRef << endl;
        cout << "maxNumber: " << maxNumber << endl;
    }
        break;
    default:
    {
        cout << "Введено неверное значение" << endl;
        return 0;
    }
    }
}

int findingMaxNumber(int specifiedNumber)
{
    int number = 0, degree = 0;
    int bytes = sizeof(short int);
    int bits = bytes * 8;
    int maxNumber = pow(2, bits) / 2 - 1;
    cout << "maxNumber: " << maxNumber << endl;
    return maxNumber;
}
int findingMaxDegree(int number, int maxNumber, int specifiedNumber)
{
    int degree = 0;
    while (number <= maxNumber)
    {
        degree++;
        number = pow(specifiedNumber, degree);
    }
    return degree;
}
void findingMaxNumberRef(int specifiedNumber, int& maxNumber)
{
    int number = 0, degree = 0;
    int bytes = sizeof(short int);
    int bits = bytes * 8;
    maxNumber = pow(2, bits) / 2 - 1;
}
void findingMaxDegreeRef(int number, int maxNumber, int specifiedNumber, int& degree)
{
    while (number <= maxNumber)
    {
        degree++;
        number = pow(specifiedNumber, degree);
    }
}
void findingMaxNumberPtr(int specifiedNumber, int* maxNumber)
{
    int number = 0, degree = 0;
    int bytes = sizeof(short int);
    int bits = bytes * 8;
    *maxNumber = pow(2, bits) / 2 - 1;
    cout << "maxNumber: " << *maxNumber << endl;
}
void findingMaxDegreePtr(int number, int maxNumber, int specifiedNumber, int* degree)
{

    while (number <= maxNumber)
    {
        *degree = *degree + 1;
        number = pow(specifiedNumber, *degree);
    }
}