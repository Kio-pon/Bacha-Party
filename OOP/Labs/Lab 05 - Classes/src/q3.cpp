#include <iostream>

using namespace std;

// Q3. Complex number class with add/subtract/multiply, each overloaded for
// (Complex, Complex) and (Complex, double).
class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0)
    {
        // TODO: initialize real and imag
    }

    Complex add(Complex &complex2)
    {
        // TODO: add two complex numbers
        return Complex();
    }
    Complex subtract(Complex &complex2)
    {
        // TODO: subtract complex2 from this
        return Complex();
    }

    Complex add(double num)
    {
        // TODO: add a real number to this complex number
        return Complex();
    }
    Complex subtract(double num)
    {
        // TODO: subtract a real number from this complex number
        return Complex();
    }

    Complex multiply(Complex &complex2)
    {
        // TODO: complex multiplication
        return Complex();
    }
    Complex multiply(double num)
    {
        // TODO: multiply this complex number by a real number
        return Complex();
    }

    void show()
    {
        if (imag < 0)
        {
            cout << real << " - " << -imag << "i" << endl;
        }
        else
        {
            cout << real << " + " << imag << "i" << endl;
        }
    }
};

int main()
{
    double real, imag;
    cin >> real >> imag;
    Complex c1 = Complex(real, imag);
    cin >> real >> imag;
    Complex c2 = Complex(real, imag);
    double d1;
    cin >> d1;
    Complex result;
    // showing the numbers :
    cout << "c1: ";
    c1.show();
    cout << "c2: ";
    c2.show();
    cout << "d1: " << d1 << endl;
    // Check the opertions where both operands are complex
    result = c1.add(c2);
    cout << "c1+c2: ";
    result.show();
    result = c1.subtract(c2);
    cout << "c1 -c2: ";
    result.show();
    result = c1.multiply(c2);
    cout << "c1*c2: ";
    result.show();
    // Check the opertions where one operator is complex , other is double
    result = c1.add(d1);
    cout << "c1+d1: ";
    result.show();
    result = c1.subtract(d1);
    cout << "c1 -d1: ";
    result.show();
    result = c1.multiply(d1);
    cout << "c1*d1: ";
    result.show();
    return 0;
}
