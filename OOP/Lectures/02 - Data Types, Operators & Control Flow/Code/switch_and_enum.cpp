#include <iostream>
using namespace std;

int main(){
    
    // Define an enum (enumeration) with three named constants.
    // Internally, RED = 0, GREEN = 1, BLUE = 2 (unless you assign custom values).
    enum colours {RED, GREEN, BLUE};

    int in; 
    cout << "Select a number: "; 
    cin >> in;

    /*
        Switch statements work only with integral types (int, char, enum).
        The variable `in` is checked against constant case labels.
    */
    switch (in)
    {
    case 0: 
        cout << "It's RED" << endl;
        break;
    case 1: 
        cout << "It's GREEN" << endl;
        break;
    case 2:
        cout << "It's BLUE" << endl;
        break;
    default:
        cout << "Invalid number" << endl;
        break;
    }

    /*
        Instead of using raw numbers (0, 1, 2), 
        we can use the enum names (RED, GREEN, BLUE).
        The compiler automatically replaces them with their integer values.
    */
    switch (in)
    {
    case RED:   // RED → 0
        cout << "It's RED" << endl;
        break;
    case GREEN: // GREEN → 1
        cout << "It's GREEN" << endl;
        break;
    case BLUE:  // BLUE → 2
        cout << "It's BLUE" << endl;
        break;
    default:
        cout << "Invalid number" << endl;
        break;
    }

    string color; 
    cout << "Select a color (RED, GREEN, BLUE): "; 
    cin >> color;

    /*
        We CANNOT use switch with strings.
        Why?
        - switch requires case labels that are compile-time constants
          (like int, char, or enum values).
        - strings are objects that are compared at runtime,
          so they cannot be used in switch.
        Therefore, we use if-else for string comparisons.
    */
    if (color == "RED")
        cout << "Number is " << RED << endl;
    else if (color == "GREEN")
        cout << "Number is " << GREEN << endl;
    else if (color == "BLUE")
        cout << "Number is " << BLUE << endl;
    else
        cout << "Invalid color" << endl;


    /*
        Important note:
        The "data type" of RED, GREEN, BLUE is colours (the enumeration type you just defined) NOT int.
        However, an unscoped enum (like this one) can implicitly convert to int.
        That’s why you can use RED, GREEN, BLUE directly in a switch or even assign them to an int.

        PS. You might be wondering what is unscoped and scoped enum. For now just think of unscoped enum as a weak type of 
        enum, scoped enum being a more strict enum that we will learn about in future.
    */
    return 0;
}
