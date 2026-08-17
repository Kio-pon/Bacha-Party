/*
    nothing super complicated happening here
    just defining variables with different datatypes
*/

#include <iostream>     // this is for cout
#include <iomanip>      // if you haven't realized iomanip = io + manipulation. This library is all about manipulating iostream
#include <cmath>        // we will use it for fabs function (fabs = floating point + absolute function)
using namespace std;    // good in small code, but if you have a huge project, not idea to do this.

int main(){
    // 1. Boolean
    bool isThisClassBoring = false;
    bool isCppBoring = true;
    cout << isThisClassBoring << endl;
    cout << (isThisClassBoring || isCppBoring) << endl; // the symbol "||" is a logical operator called OR
    cout << (isThisClassBoring && isCppBoring) << endl; // the symbol "&&" is a logical operator called AND
    /*
        notice the output is acutally an integer, cout is defined to print true as 1 and false as 0
    */
    
    // 2. Characters
    char symbol = 'X';
    cout << symbol << endl;

    // 3. Integers (int, short, long, long long)
    int age;
    cout << age << endl;
    /*
        notice this outputs a garbage value, not just 0 or any other default value
        Why? Short answer, a variable in C++ corresponds to a region of memory reserved for storing its value 
            (on the stack, heap, or in static storage depending on where it’s declared). That memory block might 
            have any data already present there, so you get garbage values

        You will see people call it Undefined Behavior (UB for short)
    */

    short int age_human_1 = 0;
    int short age_human_2{};
    short ageHuman = 0;

    /*
        notice both "short int" and "int short" are allowed
        even better, we can skip the "int" completlty 
        notice for age_human_2, instead of " = 0" I have used {}. This is basically initializing it to 0
            why this works, will make sense in the array's part
    */

    short nuclear_gandhi = 32767 + 1;                   //32767 is the upperlimit for a short int
    cout << "overflow: `" << nuclear_gandhi << endl;
    // if we push a datatype beyond its intended range, we get an overflow error

    long int cosmic_age = 834939L;
    cout << cosmic_age << endl;

    /*
        when we have to use really big numbers (which won't fit in the range of int) we can use long int
        as mentioned earlier we can use either "long int" or "int long" or just "long"
        also notice the "L" at the end of our long number! That just tells the compiler that this literal number is a long
    */

    unsigned long long int unthinkable_number = 943759378598435LL;
    cout << unthinkable_number << endl;

    /*
        1. long long is to make sure that we are acutally using the bigger data type, becuase on some systems, long = int
        2. Notice the LL at the end of the literal number? 
        4. unsigned forces the number to be non negative.
            This means that the long long number instead of having a range of -9e18 to 9e18, will have a range of 0 to ~18e18         
    */

    // 4. float and double
    float  PI_float  = 3.14159265358929;
    double PI_double = 3.14159265358929;
    
    cout << PI_float << endl;
    cout << PI_double <<endl;

    /*
        Notice the precision of both double and float seems to be the same even though we said 
        these two data types have different precisions. The problem is cout has a default precision
        
        We can change that using something called manipulator chain (found in <iomanip>)
    */

    cout << fixed << setprecision(15);  // manipulator chain ("fixed" forces cout to not use scientific notations)
    cout << PI_float << endl;
    cout << PI_double << endl;

    /*
        Now we encounter a new problem. Beyond its precision, the float cannot represent more digits correctly, 
        so you see rounding artifacts, which leads us to......
    */
    
    // floating point problem
    double a = 0.1;
    double b = 0.2;
    double sum = a + b;

    cout << "a + b = " << sum << endl;

    if (sum == 0.3) {
        cout << "Equal to 0.3" << endl;
    } else {
        cout << "Not equal to 0.3" << endl;
    }

    /*
        0.1 and 0.2 cannot be represented exactly in binary floating-point format.
        Internally, 0.1 ≈ 0.10000000000000000555...
        0.2 ≈ 0.2000000000000000111...
        Adding them gives 0.3000000000000000444...

        So instead of using equality we have to use a precision range to see if two numbers
        are close enough for us to say that they are equal
        ie if our desired output is 0.3 and we get 0.300000000000001 or 0.299999999999998, we say its alright
            but if we get 0.3001 or 0.290001, that is too big of a difference for us to say they are "close enough"
            in mathematical terms, we will be looking at the absolute difference between our desired output (0.3 in this case)
            and the acutal output 
    */

    // fabs - floating point absolute value
    if (fabs(sum - 0.3) < 1e-9 /*1e-9 is the precision tolerance that we are ready to accept*/){
        cout << "Equal to 0.3" << endl;
    } else {
        cout << "Not equal to 0.3" << endl;
    }

    /*
        There is something called long double (just like long int)
        if there is long double, is there short double? NO, because we don't need it, 
            instead we have float which is basically short double

    */
}