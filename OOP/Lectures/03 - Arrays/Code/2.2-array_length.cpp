// =================================================
// PART 1 of 2: DETERMINE ARRAY LENGTH
// =================================================
#include <iostream>

int main()
{
    int arr[]{ 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };

    /*
        Will print the following:
        (length of the array * size of one element)
    */
    std::cout << "Memory occupied by arr[] = "
        << sizeof(arr)
        << std::endl;


    // Pausing...
    std::cin.get();




    // Based on this observation, we can determine the length of an array as follows.

    std::cout << "Number of elements in arr[] = "
        << sizeof(arr) / sizeof(arr[0])
        << std::endl;

    return 0;
}




// =================================================
// PART 2 of 2: LIMITATION OF THE ABOVE TECHNIQUE
// =================================================

#include <iostream>

void printArray(int an_array[]/*, int len*/)
{
    /* NOTE

        - Arrays don't have a length attribute associated with them.

        - In other words, you cannot do something like,

            an_array.length()

        - So how would you determine the array length?
    */

    std::cout << "Within printArray() \n"
        << sizeof(an_array) / sizeof(an_array[0])
        << std::endl;

    for (int i = 0; i < sizeof(an_array) / sizeof(an_array[0]); ++i)
    {
        std::cout << an_array[i] << ' ';
    }
    std::cout << '\n';

    /*
        The above doesn't work because an array decays into a pointer when you pass
        it to a function.

        We will talk more about this after we learn what pointers are.
    */
}


int main()
{
    int arr[]{ 1, 1, 2, 3, 5, 8, 13, 21 };

    std::cout << "Within main() \n"
        << sizeof(arr) / sizeof(arr[0])
        << std::endl;
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    std::cin.get();

    printArray(arr/*, sizeArr*/);

    return 0;
}


/* NOTE:
    - Based on the above demo, we saw the array's address getting passed to the function (more on this later).

    - As such, sizeof() doesn't work in the way you would expect it to.

    - So when working with arrays and passing it to a function, also pass its length to that function.

    - You should determine the array length using the sizeof() technique in the SAME SCOPE in which the array was created.
*/

