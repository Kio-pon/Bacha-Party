#include <iostream>
using namespace std;

int main() {
    // Step 1: Declare an array of strings (array of char pointers)
    const char* arr[7] = {"Saturday", "Sunday", "Monday", "Tuesday", 
                         "Wednesday", "Thursday", "Friday"};

    // Step 2: Declare a pointer to pointer (double pointer) to hold the array of strings
    const char** ptr = arr;

    // ptr == &arr[0]

    // cout << "ptr address" <<endl << ptr << endl << ptr + 1 << endl << ptr + 2 << endl;

    // cout << "arr address" <<endl << arr << endl << arr + 1 << endl << arr + 2 << endl;

    // cout << "Value at address arr" <<endl << *arr << endl << *(arr + 1) << endl << *(arr + 2) << endl;

    // cout << "Value at address ptr" <<endl << *ptr << endl << *(ptr + 1) << endl << *(ptr + 2) << endl;

    // // Step 3: Access the strings using the double pointer
    // cout << "First string: " << *ptr << endl;        // Prints "Saturday"
    // cout << "Second string: " << *(ptr + 1) << endl; // Prints "Sunday"
    // cout << "Third string: " << *(ptr + 2) << endl;  // Prints "Monday"

    // Step 4: Access individual characters in the string using pointer arithmetic
    cout << "First character of the second string: " << **(ptr) << endl; // Prints 'S'
    cout << "Second character of the first string: " << *(*ptr + 1) << endl; // Prints 'a'

    return 0;
}
