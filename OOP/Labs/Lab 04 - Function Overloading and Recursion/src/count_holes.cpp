#include <iostream>
using namespace std;

// 3.3 Holes in a Number/Alphabet - Overloading + Recursion
// countHoles(int) sums the hole-count of each digit; countHoles(char*) sums
// the hole-count of each uppercase letter. Recursion only, no loops.
// Digit holes: 0,4,6,9 -> 1; 8 -> 2; others -> 0
// Letter holes: A,D,O,P,Q,R -> 1; B -> 2; others -> 0

int countHoles(int value)
{
    // TODO: recursively sum the hole count of each digit of value
    return 0;
}

int countHoles(char *input)
{
    // TODO: recursively sum the hole count of each character of the C-string
    return 0;
}

int main()
{
    char choice;
    cout << "Enter (d) if your input is a number and (s) if your input is a string: ";
    cin >> choice;
    if (choice == 'd')
    {
        int input;
        cout << "Enter your input: ";
        cin >> input;
        cout << countHoles(input) << " holes";
    }
    else if (choice == 's')
    {
        char input[100];
        cout << "Enter your input: ";
        cin.ignore();
        cin.getline(input, 100);
        cout << countHoles(input) << " holes";
    }
    else
        cout << "Invalid Input";
}
