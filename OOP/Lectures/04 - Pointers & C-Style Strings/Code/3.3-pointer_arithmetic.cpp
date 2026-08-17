// pointer arithmetic
#include <iostream>

int main()
{
    int value = 7 ;
    int* ptr = &value ;

    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';
    std::cout << ptr + 4 << '\n';

    return 0;
}

// ======================================================================

#include <iostream>

int main()
{
    int array[] = { 9, 7, 5, 3, 1 };

    std::cout << &array[1] << '\n'; // print memory address of array element 1
    std::cout << array + 1 << '\n'; // print memory address of array pointer + 1

    std::cout << array[1] << '\n'; // prints 7
    std::cout << *(array + 1) << '\n'; // prints 7 (note the parenthesis required here)

    return 0;
}

// ======================================================================

#include<iostream>

int main()
{
    int array[]{ 9, 7, 5, 3, 1 };

    int len{ sizeof(array) / sizeof(array[0]) };


    // Alternative 1
    for (int i = 0 ; i < len; i++)
    {
        std::cout << *(array + i) << ' ';
    }
    std::cout << '\n';


    // Alternative 2
    for (int* ptr = array ; ptr < (array + len); ptr++)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';


    /* NOTE
        - Generally, you don't need to use pointers to loop this way.

        - Array notation (indexing) is easier to use, and less error-prone.

        - However, this demonstrates the concepts that we have talked about quite well.
    */


    return 0;
}
