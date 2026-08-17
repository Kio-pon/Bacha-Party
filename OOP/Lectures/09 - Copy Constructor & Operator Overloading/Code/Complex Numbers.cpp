#include <iostream>
using namespace std;

struct ComplexNumber{
    double real;
    double imaginary;

    ComplexNumber() : real(0), imaginary(0) {}
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    void print() {cout << real << " + " << imaginary << "i" << endl;}
};

ComplexNumber add(ComplexNumber a, ComplexNumber b){
    return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
}

ComplexNumber operator+(ComplexNumber a, ComplexNumber b){
    return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
}


// Now you do it for subtract, multiply, divide
// Think about a++ and ++a (rembmer the difference?)
// If you feel the tasks above are easy, then think about << operator

int main(){
    ComplexNumber x(1,2);
    x.print();
    ComplexNumber y(2,1);
    y.print();
    ComplexNumber z = x + y;
    z.print();
}