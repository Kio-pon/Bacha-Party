#include <iostream>

/*
This program demonstrates the use of arrays and pointers in C++. It takes 5
integers as input from the user, stores them in an array, and then prints the
numbers using a pointer to traverse the array.
*/

int main() {
    int  numbers[5];     // Array to store 5 integers
    int *ptr = numbers;  // Pointer pointing to the first element of the array

    // Take input from the user
    std::cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> numbers[i];
    }

    // Print the array elements using the pointer
    std::cout << "The numbers you entered are: ";
    for (int i = 0; i < 5; ++i) {
        // Access array elements using pointer arithmetic
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
