#include<iostream>
using namespace std;
//operator overloading
// 2 + 5 = 7
//"abc" + "def" = abcdef
//"abc" + 2 = "abc2"
class Complex
{
        double real ;
        double imag ;

    public: 
        Complex(double r =0 , double i =0  );
        void show();
        Complex operator - (Complex obj)    // Complex subtract (Complex obj);
        {
                return Complex (real - obj.real ,imag - obj.imag );
        }
        Complex operator + (Complex obj)
        {
            Complex sum ;
            sum.real = real + obj.real;
            sum.imag = imag + obj.imag;
            return sum;
        }
 
};

Complex::Complex(double r, double i )
        {
            real = r ; imag = i;    }
void Complex::show()
        {
            cout << real << " + " << imag << "i\n";
        }



int main()
{   
    Complex c1(5,3), c2(6,9) , c3(2,5);
    Complex res = c1 + c2 - c3; // 11 + 12i // c1.add(c2) // c1.+(c2)
    res.show();
    res = c1 - c2;
    res.show();
 
    return 0 ;
}