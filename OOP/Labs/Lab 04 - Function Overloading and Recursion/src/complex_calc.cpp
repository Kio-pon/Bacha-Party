#include <iostream>
using namespace std;

// 3.2 Complex Calculator - Overloaded
// Complex numbers are represented as double[2]: {real, imaginary}.
// Overload add/sub/multiply for (complex, complex) and (complex, real).

double *add(double *complex1, double *complex2)
{
    // TODO: return a new double[2] with the sum of the two complex numbers
    return nullptr;
}

double *add(double *complex1, double realNum)
{
    // TODO: treat realNum as a complex number with zero imaginary part and reuse add()
    return nullptr;
}

double *sub(double *complex1, double *complex2)
{
    // TODO: subtract complex2 from complex1
    return nullptr;
}

double *sub(double *complex1, double realNum)
{
    // TODO: subtract a real number from a complex number
    return nullptr;
}

double *multiply(double *complex1, double *complex2)
{
    // TODO: complex multiplication
    return nullptr;
}

double *multiply(double *complex1, double realNum)
{
    // TODO: multiply a complex number by a real number
    return nullptr;
}

void show(double *complex)
{
    // TODO: print in the form "x + yi" (or "x - yi" when imaginary part is negative)
    delete[] complex;
}

int main()
{
    double *c1 = new double[2];
    double *c2 = new double[2];
    double realNum = 0;

    cout << "Enter Complex 1: ";
    for (int i = 0; i < 2; ++i)
    {
        cin >> c1[i];
    }
    cout << "Enter Complex 2: ";
    for (int i = 0; i < 2; ++i)
    {
        cin >> c2[i];
    }
    cout << "Enter RealNum: ";
    cin >> realNum;

    cout << "c1+c2 : ";
    show(add(c1, c2));

    cout << "c1-c2 : ";
    show(sub(c1, c2));

    cout << "c1*c2 : ";
    show(multiply(c1, c2));

    cout << "c1+d1 : ";
    show(add(c1, realNum));

    cout << "c1-d1 : ";
    show(sub(c1, realNum));

    cout << "c1*d1 : ";
    show(multiply(c1, realNum));

    delete[] c1;
    delete[] c2;
}
