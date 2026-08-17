#include <iostream>

/*
This program takes a sentence input from the user using std::cin.getline().
It then manually calculates the length of the sentence (without using any
built-in functions) and checks whether the first and last characters of the
sentence are the same. Finally, it prints the result to the user.
*/

int main() {
    char sentence[100];

    std::cout << "Enter a sentence: ";
    std::cin.getline(sentence, 100);

    // Find the length manually
    int length = 0;
    while (sentence[length] != '\0') {
        ++length;
    }

    // Check if first and last character are the same
    if (length > 0 && sentence[0] == sentence[length - 1]) {
        std::cout
            << "The first and last character of your sentence are the same!"
            << std::endl;
    } else {
        std::cout << "The first and last character are different." << std::endl;
    }

    return 0;
}
