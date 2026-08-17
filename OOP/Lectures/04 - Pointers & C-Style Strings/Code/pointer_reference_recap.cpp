#include <iostream>
using namespace std;

// Pass by value

void swapbyvalue(int x, int y){

    int temp = x;
    x = y;
    y = temp;
    cout << "By value swapping inside function " << x << "..." << y <<endl;

}

// int *p = &x (Pointer operation)
// &b = a (Reference Variable)

void swapbypointers(int *x, int* y){

    cout << x <<endl;
    int temp = *x;
    *x = *y;
    *y = temp;

    cout << "By value swapping inside function " << *x << "..." << *y <<endl;

}

void swapbyreference(int &x, int &y){

    cout << &x << endl;
    cout << x << endl;
    int temp = x;
    x = y;
    y = temp;
    cout << "By value swapping inside function " << x << "..." << y <<endl;

}

// for pass by reference
int main(){

    int a = 5, b = 10;
    swapbyreference(a, b);

    // int temp = a;
    // a = b;
    // b = temp;


    cout << "By value swapping outside function " << a << "..." << b <<endl;

    return 0;
}


// uncomment for pass by pointer
// int main(){

//     int a = 5, b = 10;
//     swapbypointers(&a,&b);

//     // int temp = a;
//     // a = b;
//     // b = temp;


//     cout << "By value swapping outside function " << a << "..." << b <<endl;

//     return 0;
// }

// uncomment for pass by value
// int main(){

//     int a = 5, b = 10;
//     swapbyvalue(a,b);

//     // int temp = a;
//     // a = b;
//     // b = temp;


//     cout << "By value swapping outside function " << a << "..." << b <<endl;

//     return 0;
// }



