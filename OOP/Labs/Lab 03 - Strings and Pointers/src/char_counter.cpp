#include <iostream>
using namespace std;

// Exercise 1 [25 points]: takes a string and a character from the user,
// then prints the number of times the character occurs in the string.
// Hint: use a C-style string (array of characters) and iterate through it using a loop.
int find_freq(char *str, char ch)
{
    // TODO: count and return the occurrences of ch in str
    return 0;
}

int main()
{
    char input[100], ch;
    cout << "Enter a string: ";
    cin.getline(input, 100);
    cout << "Enter a character to search: ";
    cin >> ch;
    cout << "There are " << find_freq(input, ch) << " (" << ch << ")s in your string.";

    return 0;
}
