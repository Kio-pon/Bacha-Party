#include <iostream>
using namespace  std;
void func1(int a , int b)
{
    a = a+b;
}
void func2(int* a , int* b)
{
    *a = *a + *b;
}

void func3(int& a , int& b)
{
    a = a + b;
}
int main()
{

    int num = 88 , num2 = 9;
    int* p = &num;
    int& y = *p;  // num 
    func1(num , num2); //pass by value
    cout << "Value of num " << num << " " << y << " " <<*p; // 88 
    // cout << "\nAddress of num " << &num <<" " << &y << " " << p ;
    // cout << "\nAddress of p " << &p;

    func2(&num , &num2); // pass by address (receved by pointers)
    cout << "Value of num " << num << " " << y << " " <<*p; //97
    func3(num , num2); //pass by value (receved by references)
    cout << "Value of num " << num << " " << y << " " <<*p; //106
    double d = 8.2;
    double* pd = &d;
    //sizeof p  and pd? //8 bytes 
    //sizeof y ? 4 bytes



    return 0;
}