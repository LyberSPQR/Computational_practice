//7. Определить, какую наибольшую степень числа 7 можно вычислить, пользуясь типом signed short.
#include <iostream>
using namespace std;
void findingMaxNumber(int specifiedNumber, int* ptr1);
void findingMaxDegree(int number, int maxNumber, int specifiedNumber, int* degree);

int main()
{
    int specifiedNumber = 7, number = 0, degree = 0, maxNumber = 0, p = 0,v = 0;
    int* ptr = &p;
    int* ptr1 = &v;

    findingMaxNumber(specifiedNumber,ptr1);
    findingMaxDegree(number, *ptr1, specifiedNumber, ptr);

    int num = pow(specifiedNumber, *ptr - 1);
    cout << "Max degree within the limit: " << *ptr - 1 << endl;
    cout << "Number whith this degree: " << num;
}

void findingMaxNumber(int specifiedNumber, int* maxNumber)
{
    int number = 0, degree = 0;
    int bytes = sizeof(short int);
    int bits = bytes * 8;
     *maxNumber = pow(2, bits) / 2 - 1;
    cout << "maxNumber: " << *maxNumber << endl;
}
void findingMaxDegree(int number, int maxNumber, int specifiedNumber, int* degree)
{
    
    while (number <= maxNumber)
    {
        *degree = *degree + 1;
        number = pow(specifiedNumber, *degree);
    } 
}