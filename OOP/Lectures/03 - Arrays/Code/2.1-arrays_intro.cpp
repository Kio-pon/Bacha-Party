#include<iostream>

int main()
{
    // ========================================================
    // CREATING AN ARRAY
    // READING VALUES AND UPDATING THEM
    // ========================================================

    // Declaration (avoid doing this)
    int arr1[8];

    // Proof that values are not initialized.
    for (int i{ 0 }; i < 8; ++i)
    {
        std::cout << arr1[i] << ' ';
    }
    std::cout << std::endl;


    // Pausing...
    std::cin.get();


    // Initialization
    int arr2[4]{ -1, 0, 1, 2 };

    // Let the compiler figure the array's length.
    int arr3[]{ -1, 6, 6, 0, 1, 2 };

    // All elements are initialized to 0.
    int arr4[8]{};

    for (int i{ 0 }; i < 8; i++)
    {
        std::cout << arr4[i] << ' ';
    }
    std::cout << std::endl;

    // Pausing...
    std::cin.get();


    /*
        First element = 5
        Other elements are equal to 0.
    */
    int arr5[8]{ 5 };

    for (int i{ 0 }; i < 8; i++)
    {
        std::cout << arr5[i] << ' ';
    }
    std::cout << std::endl;

    // Pausing...
    std::cin.get();




    // const variables can be used to set array length.
    const int const_len{ 7 };
    int primes[const_len]{ 2, 3, 5, 7, 11, 13, 17 };

    // Normal variables, however, cannot be used to set length.
    int norm_len{ 7 };
    // std::cout << "Enter length = ";
    // std::cin >> norm_len;
    int norm_arr[norm_len]{};




    // Accessing elements by indexing.
    // First element is at index = 0.
    // Last element is at index = (n - 1).
    std::cout << "arr2[0] = " << arr2[0] << std::endl;
    std::cout << "arr2[1] = " << arr2[1] << std::endl;
    std::cout << "arr2[2] = " << arr2[2] << std::endl;
    std::cout << "arr2[3] = " << arr2[3] << std::endl;
    std::cout << std::endl;




    // Printing out arrays - use loops.
    for (int i{ 0 }; i < 4; i++)
    {
        std::cout << arr2[i] << ' ';
    }
    std::cout << std::endl;

    /*
        CAUTION!
        Following prints out the ADDRESS of the first element of the array.
    */
    std::cout << "Address of arr2[0] = " << arr2 << std::endl;


    // Pausing...
    std::cin.get();




    // Update individual values of each element in the array.
    arr2[1] = 100;

    // Printing out the array
    for (int i{ 0 }; i < 4; i++)
    {
        std::cout << arr2[i] << ' ';
    }
    std::cout << std::endl;


    std::cin.get();




    // ========================================================
    // INDEXING AN ARRAY OUT OF BOUNDS
    // ========================================================    

    double constants[]{ 3.142, 3.0E8, -273.15, 100.0, 0.0 };

    // Don't do this.
    std::cout << constants[5] << std::endl;
    std::cout << constants[-1] << std::endl;

    /*
        NOTE
        ----
        - You should only use the memory that you have allocated.

        - Going out of bounds means you're accessing memory that you're NOT ALLOWED to use.

        - Compiler may or may not create warnings/errors.
            - So YOU have to be vigilant.

        - Going out of bounds, can,
            - result in undefined behavior.
            - cause your program to crash.
            - modify variables in other parts of your program.
    */

    return 0;
}