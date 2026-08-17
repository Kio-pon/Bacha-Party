#include <iostream>

/* The do-while Loop
    1- It guarantees the execution of the loop body at least once.
    2- The test expression is now at the end.
    3- Note the syntax.
*/

int main()
{
    long dividend = 1, divisor = 1;
    char user_choice = 'n';

    // this loop won't run even once, because the test expression fails.
    while (user_choice != 'n')
    {
        std::cout << "This won't work\n";
    }

    do
    {
        std::cout << "Enter dividend: ";
        std::cin >> dividend;

        std::cout << "Enter divisor: ";
        std::cin >> divisor;

        std::cout << "Quotient is " << dividend / divisor;
        std::cout << ", remainder is " << dividend % divisor;

        std::cout << "\nDo another? (y/n): ";
        std::cin >> user_choice;

    } while (user_choice != 'n');


    /* NOTE:
        1- See that there is a ; at the end of while. This was not the case with the normal while loop.
        2- Also, even in for loop, there is no ; at the end of the loop or after "for( ; ; )"
            If you write something like for(...; ...; ...);, this shows that the loop has no body.
    */

    // =================================================================
    // The following won't work. Variable scope problem.
    // do {
    //     int fox = 5;
    //     fox++;
    //     std::cout << fox << std::endl;
    // } while (fox <= 7);

    return 0;
}


