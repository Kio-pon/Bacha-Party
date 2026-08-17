#include <iostream>
using namespace std;

void exchange(int, int);   // pass by value
void exchange(int*, int*); // pass by pointer
void exchange(int&, int&); // pass by reference


int main(){

    // 1. FUNCTIONS - pass by value, pass by reference, pass by pointer

    /*
        talk about alias after disucsison pass by value, pass by reference
    */

    int a_variable = 10;
    int &alias_variable = a_variable; // same variable different name (alias)
    // in the above can, there is no way I can define but not initialize, it will throw error.


    // referencing is not pointer, and we can see how referencing is different compared to 
    int a_var = 10, b_var = 20;

    int &r = a_var;   // r is now an alias for a
    r = b_var;            // does not "reseat" — assigns value of b to a
                      // now a == 20, r still refers to a

    int *p_ = &a_var;  // pointer to a
    p_ = &b_var;       // reseated to point to b

}

void exchange(int x, int y){
    int temp = x;
    x = y;
    y = temp; 
}

void exchange(int* x, int* y){
    int* temp = x;
    x = y;
    y = temp; 
}

void exchange(int& x, int& y){
    int temp = x;
    x = y;
    y = temp; 
}