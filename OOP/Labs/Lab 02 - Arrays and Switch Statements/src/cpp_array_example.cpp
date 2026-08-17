// File: array_example.cpp
#include <iostream>
using namespace std;

int main() {
    // Example of 1D array in C++ without using loops
    int marks[5] = {90, 85, 70, 88, 76};

    // Accessing elements directly
    cout << "First mark: " << marks[0] << endl;
    cout << "Third mark: " << marks[2] << endl;

    // Modifying an element
    marks[2] = 75;
    cout << "Updated third mark: " << marks[2] << endl;

    return 0;
}
