// Ways to pass arrays to functions

#include <iostream>


void passValue(int someNum) // value is a copy of the argument
{
    someNum = 99;
}


void passArray(int arr[], int len) // prime is the actual array
{
    arr[0] = 11; // so changing it here will change the original argument!
    arr[1] = 7;
    arr[2] = 5;
    arr[3] = 3;
    arr[4] = 2;
}


int main()
{
    // PASSING A SINGLE VARIABLE - copy created.

    int val{ 1 };
    std::cout << "before passValue(): " << val << '\n';

    passValue(val);
    std::cout << "after passValue(): " << val << '\n';

    // Pausing
    std::cin.get();




    // PASSING AN ARRAY - the array itself is passed. 

    int prime[5]{ 2, 3, 5, 7, 11 };

    std::cout << "before passArray(): ";
    for (int i{ 0 }; i < 5; i++)
    {
        std::cout << prime[i] << ' ';
    }
    std::cout << std::endl;

    passArray(prime, 5);

    std::cout << "after passArray(): ";
    for (int i{ 0 }; i < 5; i++)
    {
        std::cout << prime[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}


// // If you want to ensure a function does not modify the array, you can make the array const.
// // even though prime is the actual array, within this function it should be treated as a constant
// void passArray(const int prime[], int len)
// {
//     // so each of these lines will cause a compile error!
//     prime[0] = 11;
//     prime[1] = 7;
//     prime[2] = 5;
//     prime[3] = 3;
//     prime[4] = 2;
// }