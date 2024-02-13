//7. Определить, какую наибольшую степень числа 7 можно вычислить, пользуясь типом signed short.
#include <iostream>
using namespace std;
void findingMaxNumber(int specifiedNumber, int & maxNumber);
void findingMaxDegree(int number, int maxNumber, int specifiedNumber, int& degree);

int main()
{
    int specifiedNumber = 7, number = 0, degree = 0, maxNumber = 0, maxDeg = 0;

    findingMaxNumber(specifiedNumber, maxNumber);
    findingMaxDegree(number,maxNumber, specifiedNumber, maxDeg);

    int num = pow(specifiedNumber, maxDeg - 1);
    cout << "Max degree within the limit: " << maxDeg - 1 << endl;
    cout << "Number whith this degree: " << num << endl;
    cout << "maxNumber: " << maxNumber << endl;
}

void findingMaxNumber(int specifiedNumber, int & maxNumber)
{
    int number = 0, degree = 0;
    int bytes = sizeof(short int);
    int bits = bytes * 8;
    maxNumber = pow(2, bits) / 2 - 1;
}
void findingMaxDegree(int number, int maxNumber, int specifiedNumber, int & degree)
{
    while (number <= maxNumber)
    {
        degree++;
        number = pow(specifiedNumber, degree);
    }
}