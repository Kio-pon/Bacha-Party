#include <iostream>
#include <cmath>
using namespace std;

// Exercise 2.1: Simple calculator - Using Switch [25 Points]
// Implement a calculator that performs +, -, *, /, ^ on two integers
// using a switch statement on the operator character.
int main()
{
    int num1, num2;
    char op;
    cout << "Welcome to my calculator" << endl;

    // TODO: prompt for num1 (re-prompt while negative)

    // TODO: prompt for num2 (re-prompt while negative)

    cout << "Enter operator (+, -, *, /, ^): ";
    cin >> op;

    // TODO: switch on op and print the result of the requested operation
    // Handle division by zero for '/' and use pow() for '^'
    switch (op)
    {
    case '+':
        break;
    case '-':
        break;
    case '*':
        break;
    case '/':
        break;
    case '^':
        break;
    default:
        cout << "Error: Invalid operator." << endl;
        break;
    }

    return 0;
}
