// A simple C++ program to teach basics: variable declaration, printing, input, comments, and conditions
#include <iostream>  // Required for input and output
using namespace std; // To avoid writing std:: repeatedly

int main()
{
    // --- COMMENTS ---
    // Single-line comment starts with //
    /* Multi-line comments look like this
       They can span multiple lines */

    // --- PRINTING ---
    cout << "Hello, World!" << endl; // Prints text to the screen

    // --- VARIABLES ---
    int age = 20;        // Integer variable
    double height = 5.9; // Decimal number
    char grade = 'A';    // Single character

    // Print variables
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Grade: " << grade << endl;

    // --- TAKING INPUT ---
    int userAge;

    cout << "Enter your age: ";
    cin >> userAge; // Takes integer input

    cout << "\nYou are " << userAge << " years old." << endl;

    // --- IF / ELSE STATEMENTS ---
    if (userAge < 18)
    {
        cout << "You are a minor." << endl;
    }
    else if (userAge >= 18 && userAge < 60)
    {
        cout << "You are an adult." << endl;
    }
    else
    {
        cout << "You are a senior citizen." << endl;
    }

    return 0; // End of program
}
