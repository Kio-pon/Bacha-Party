#include <iostream>
using namespace std;

int main(){
    char symbol = 'X';
    cout << symbol + 1 << endl;
    // did the implicit conversion of char into int
    
    float avg_weight = 33.1;
    short count = 22;
    double total_weight = avg_weight * count;
    cout << total_weight << endl;

    /*
        count (short) → promoted to int → then implicitly converted to float for multiplication → result (float) 
            → promoted to double when stored
    */

    // Here we see some explicit conversions
    int x = 5;
    int y = 2;
    cout << x/y << endl;                        // the output here is 2
    cout << (double)x /y << endl;               // we are explicitly converting x into a double, which forces an implicit conversion of y into float
    cout << static_cast<double>(x)/y << endl;   // we are explicitly converting x into a double, which forces an implicit conversion of y into float
    cout << static_cast<double>(x/y) << endl;   // x/y is evaluated to be 2, and then it is converted into double, we have already lost the decimal part

    /*
        Why use static_cast instead of (double)?
        - (double)x is a C-style cast: it can perform many kinds of conversions, some unsafe.
        - static_cast<double>(x) is explicit: only allows safe, well-defined conversions.
        - Compiler will block dangerous conversions with static_cast, but not with (double).
        - Easier to search for in large codebases.
    */
}