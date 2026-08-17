#include <iostream>
using namespace std;

void size_of_array(int arr[5]) {  // looks like an array parameter
    cout << "Size: " << sizeof(arr) << endl;
    // since its an array, you expect the sizeof to be 5*sizeof(int)
    // but its just sizeof(int)
}


int main(){
    // 1. INTRODUCTION

    /*
        There is a parallel data type for each like int char etc
        these are pointers and identified as int* char* etc
        these are not the data, but address to the data itself
    */

    int integer = 43;
    int* integer_pointer = &integer; // the & is a way to extract the address (REFERENCING)

    // How to access the data of a pointer
    cout << integer_pointer << endl;
    cout << *integer_pointer << endl; // (DEREFERENCING)
    cout << *(&integer) << endl;

    // DON'T DO
    // this confuses the compiler and b is assigned an int
    int* a, b;

    cout << a << endl; // pointer
    cout << b << endl; // integer

    // 2. NULL POINTERSnull pointer
    int* x_ptr = NULL; // basically x_ptr = 0;
    int* y_ptr = nullptr; 
    /*
            this is type safe NULL is just 0 an integer literal
            Using null can lead to ambiguity because its not a real pointer type
            nullptr (introduced in c++11) is type-safe

            NULL is usually defined as 0 in C++, but 0 is treated specially by 
            the compiler as a null pointer constant when used in pointer assignments or comparisons. 
            This is a language feature, not just a textual replacement.
    */

    // 3. SIDE NOTE. SHORTCUT FOR NAMING LONG DATATYPE
    const unsigned long long int number = 10;
    const unsigned long long int* ptr_number = &number;

    typedef const unsigned long long int* CULLIPtr;
    using CULLIPtr = const unsigned long long int*;

    CULLIPtr x = &number;

    // 4. EXAMPLE USE OF POINTERS FOR A PERSON STURCTURE
    struct Person{
            string name;
            int age;
            Person* bestie;
    };

    Person Tauqeer;
    Tauqeer.age = 100;
    Tauqeer.name = "Tauqeer";

    Person Karim;
    Karim.age = 200;
    Karim.name = "Karim";

    Tauqeer.bestie = &Karim;
    Karim.bestie = &Tauqeer;
    
    cout << Karim.bestie->name << endl;
    
    /*
        notice this -> sign
        it is syntactic sugar for (*bestie).
        because we first need to dereferecnce the pointer
        and then access its variables using .
        and the sequence needs to be the same, hence the braces
        but its too much so C++ has ->
    */

    // 5. ARRAY POINTER DUALITY
    int arr[5] = {10,20,30,40,50};
    int *p = arr;    // arr decays to int* 

    arr[2] == *(arr + 2); // true → gives 30
    p[2]   == *(p + 2);    // true → gives 30

    /*
        Things to notice:
        1. When I am adding 2 to arr and p, I am not adding two integers
            Its called pointer arithmetics, and it means that we will be moving our pointer from current memory address
            to the 2nd memory block from arr (which rememeber is a pointer to the first element of the array)
    */

    // when this duality doesn't work
    int arr1[3] = {1,2,3};
    int arr2[3];

    // arr2 = arr1; // Not allowed (arrays are not assignable)
    int *p1 = arr1, *p2 = arr2;
    p2 = p1;        // Allowed (pointers are assignable)
}