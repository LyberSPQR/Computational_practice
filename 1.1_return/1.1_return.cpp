﻿//7. Определить, какую наибольшую степень числа 7 можно вычислить, пользуясь типом signed short.
#include <iostream>
using namespace std;
int findingMaxNumber(int specifiedNumber);
int findingMaxDegree(int number, int maxNumber, int specifiedNumber);


int main()
{
    int specifiedNumber = 7, number = 0, degree = 0, maxNumber = 0;

    maxNumber = findingMaxNumber(specifiedNumber);
    degree = findingMaxDegree(number, maxNumber, specifiedNumber);

   int num = pow(specifiedNumber, degree - 1);
    cout << "Max degree within the limit: " << degree - 1 << endl;
   cout << "Number whith this degree: " << num;
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