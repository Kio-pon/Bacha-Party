#include <iostream>

/* while loop
    - It looks simplified, but it has all the information it needs to run (commented).
    - Note the syntax.
*/

int main()
{
    int user_choice = -1;           // loop variable initialized
    while (user_choice != 0)        // test expression
    {
        std::cout << "Please enter a number = ";
        std::cin >> user_choice;    // expression that updates the loop variable

        std::cout << "user_choice = " << user_choice << std::endl;
    }

    return 0;
}
