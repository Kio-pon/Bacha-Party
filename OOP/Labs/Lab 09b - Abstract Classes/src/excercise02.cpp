#include <iostream>
using namespace std;

// Lab Exercise 1 (Q2): from the NumInterface abstract class (excersice01.cpp),
// derive NumWhole and NumComplex, each implementing display()/increment()
// and an operator+ for their own type.
class NumInterface
{
public:
    NumInterface() {}
    virtual void display() const = 0;
    virtual void increment() = 0;
};

class NumWhole : public NumInterface
{
private:
    unsigned int value;

public:
    NumWhole() : value(0) {}

    NumWhole(unsigned int val) { value = val; }
    int getValue() const { return value; }

    void setvalue(unsigned int val) { value = val; }

    void display() const override
    {
        // TODO: print value
    }
    void increment() override
    {
        // TODO: increment value
    }

    NumWhole operator+(const NumWhole &other) const
    {
        // TODO: return a NumWhole holding the sum of value + other.value
        return NumWhole();
    }
};

class NumComplex : public NumInterface
{
private:
    double real;
    double imag;

public:
    NumComplex() : real(0), imag(0) {}
    NumComplex(double r, double i) : real(r), imag(i) {}

    double getReal() const { return real; }

    double getImag() const { return imag; }
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    void display() const override
    {
        // TODO: print as "(real + imagi)"
    }
    void increment() override
    {
        // TODO: increment both real and imag by 1.0
    }
    NumComplex operator+(const NumComplex &other) const
    {
        // TODO: return a NumComplex holding the component-wise sum
        return NumComplex();
    }
};

// You can compile this file to test the Numbers (const correctness) question
int main()
{
    NumWhole n1(33u), n2(44u);
    n1.display();
    cout << ",";
    n2.display();
    cout << endl; // 33,44 followed by newline
    // displaying const numbers
    NumWhole const n3(55u), n4(66u);

    n3.display();
    cout << ",";
    n4.display();
    cout << endl; // 55,66 followed by newline
    NumWhole n5 = n3 + n4;
    n5.increment();
    n5.display();
    cout << endl; // should display 122, followed by a newline
    NumComplex c1(2, 0),
        c2(4, -5);
    c1.display();
    c2.display();
    cout << endl; //(2+0i)(4-5i) followed by newline
    NumComplex const c3(2, 0), c4(4, -5);
    c3.display();
    c4.display();
    cout << endl; //(2+0i)(4-5i) followed by newline
    NumComplex c5 = c3 + c4;
    c5.increment();
    c5.display();
    cout << endl; //(y-4i) followed by newline
    NumInterface const *p[10] = {&n1, &n2, &n3, &n4, &n5, &c1, &c2, &c3, &c4,
                                  &c5};
    // below display: 33,44,55,66,122,(2+0i),(4-5i),(2+0i),(4-5i),(7-4i),
    for (int i = 0; i < 10; i++)
    {
        p[i]->display();
        cout << ",";
    }
    cout << endl;
    return 0;
}
