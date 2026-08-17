#include<iostream>
#include <cstring>
int my_strlen(char n[])
{
    int len = 0;
    int i = 0;
    while(n[i] != '\0'){
        if(n[i]==' ')
        {
            i++;
        }
        else{
        i++;
        len++;}
    }
    
    return len;

}

int main()
{
    char charArr[]{ "four" };

    /* QUESTION: How many elements does this char array have?

        - 4 + 1 = 5 elements.

        - The '\0' automatically gets appended at the end.
    */

    // Program to confirm the above.

    int len{ sizeof(charArr) / sizeof(charArr[0]) };
    std::cout << "len = " << len << '\n';

    for (int i{ 0 }; i < len; i++)
    {
        std::cout << "character = " << charArr[i] << ", ";
        std::cout << "ASCII = " << static_cast<int>(charArr[i]) << '\n';
    }
    std::cout << '\n';

    std::cin.get();





    // =====================================================================================
    // Alternate initialization - introduce a null char manually.
    char string0[]{ 'f', 'o', 'u', 'r', '\0' };

    // // Leave space for the null character in your array.
    char string1[5]{ "Hello" };     // Comment this for avoiding a compile error.
    char str1[5]{ 'H', 'e', 'l', 'l', 'o' };





    // =====================================================================================
    // // Cannot update a C-style string like this.
    // // This is true for an array of any dtype.
    // // Comment this for avoiding a compile error.
    charArr = "five";


    // =====================================================================================
    // Update individual elements.
    charArr[0] = 's';
    for (int i{ 0 }; i < len; i++)
    {
        std::cout << "character = " << charArr[i] << ", ";
        std::cout << "ASCII = " << static_cast<int>(charArr[i]) << '\n';
    }
    std::cout << '\n';

    std::cin.get();




    // =====================================================================================
    // Interesting behavior with std::cout

    int intArr[]{ 1, 2, 3, 4, 5 };

    // What is the output here?
    std::cout << "intArr = " << intArr << '\n';

    // So what will be the output here?
    std::cout << "charArr = " << charArr << '\n';

    std::cin.get();

    /* NOTE
        - When you use the insertion operator with the following operands,
            - std::cout
            - char* (i.e. a character type address or a character type pointer)

            ... instead of printing the address or the VALUE of the pointer (which would be the address),
                it prints out the data saved at that address.

            After printing, it will move to the next memory address, and print the
                saved data over there.

            It will continue to do so until it encounters the NULL CHARACTER.
                Recall that '\0' marks the end of the string.
                So your entire string is printed.
    */

    // What will be the output below?

    charArr[4] = 'e';       // Overwriting the '\0' of my string.
    std::cout << "charArr = " << charArr << '\n';

    std::cin.get();


    /* NOTE
        - DON'T overwrite the null character of your string.

        - Otherwise std::cout will continue printing data that's not part of your string.

        - And it will continue to do so until it encounters '\0' present somewhere in your memory.
    */


    // What will be the output here?

    char string2[20]{ "seven" };
    std::cout << "string2 = " << string2 << '\n';

    std::cin.get();


    /* NOTE
        - You CAN legally access those other indices.
            - You have reserved 20 elements after all.
    */

    std::cout << "string2 with for loop.\n";
    for (int i{ 0 }; i < 20; i++)
    {
        std::cout << "character = " << string2[i] << ", ";
        std::cout << "ASCII = " << static_cast<int>(string2[i]) << '\n';
    }
    std::cout << '\n';

    std::cin.get();


    std::cout << "string2 with for loop.\n";
    for (int i{ 0 }; string2[i] != '\0'; i++)
    {
        std::cout << "character = " << string2[i] << ", ";
        std::cout << "ASCII = " << static_cast<int>(string2[i]) << '\n';
    }

    std::cin.get();

    // Note the different test expressions in both of the loops above.


    // Btw, you MAY see something cool if you let the loop above run out of bounds.
        // Instead of i<20, you can set it to i<80 or i<100.




    // =====================================================================================
    // How to take input from user in your char array?

    // Declare array large enough to hold 254 characters + null terminator
    char name[255]{};
    char color[255]{};

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your favorite color: ";
    std::cin >> color;

    std::cout << name << '\n' << color << '\n';

    std::cin.get();



    /* PROBLEM WITH THE ABOVE
        - "std::cin >> name"
            will stop reading characters after an "enter" and after a "space".

        - Use the following instead.
    */

    char name2[255]{};
    char color2[255]{};
    std::cout << "UPDATED - Enter your name: ";

    // Only (255 - 1 = ) 254 characters would be read from the user. 
    // The last one would automatically be reserved for the null character.
    // Optional third argument: terminating character.
    std::cin.getline(name2, 255);

    std::cout << "Enter color: ";
    std::cin.getline(color2, 255, '@');

    std::cout << name2 << '\n' << color2 << '\n';




    // =====================================================================================
    // Built-in Functions for char arrays 
    char name[20];
    std::cout<< "Enter your name : ";
    std::cin.ignore();// input buffer --- \r
    
    std::cin.get(name,20);  // 
    std::cout << "Hello " << name << std::endl;
    std::cout << "Length of your name (using my strlen) : " << my_strlen(name) << std::endl;  
    std::cout << "Length of your name (using strlen from cstring header file) : " << strlen(name) <<std::endl;  


    return 0;
}