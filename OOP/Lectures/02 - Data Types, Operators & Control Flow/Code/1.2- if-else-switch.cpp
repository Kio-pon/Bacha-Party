#include <iostream>

// ==========================================================
// CHARACTER SELECT SCREEN - USING if/else
// ==========================================================
int main() {

    // Sample menu
    int user_choice = -1;

    /* NOTE
        1- the use of a single std::cout.
        2- the following is a single statement.
        3- alternatively, you can use multiple std::cout (i.e. multiple statements).
    */
    std::cout << "Select a character type. Press: " << std::endl
        << "1 - Fighter" << std::endl
        << "2 - Mage" << std::endl
        << "3 - Support" << std::endl
        << "4 - Tank" << std::endl
        << "5 - Carry" << std::endl
        << std::endl;

    std::cin >> user_choice;

    if (user_choice == 1)
    {
        std::cout << "Fighter selected." << std::endl;
    }
    else if (user_choice == 2)
    {
        std::cout << "Mage selected." << std::endl;
    }
    else if (user_choice == 3)
    {
        std::cout << "Support selected." << std::endl;
    }
    else if (user_choice == 4)
    {
        std::cout << "Tank selected." << std::endl;
    }
    else if (user_choice == 5)
    {
        std::cout << "Carry selected." << std::endl;
    }
    else
    {
        std::cout << "Wrong input." << std::endl;
    }

    // You can use all if's as well, but then every condition will be checked - redundant work.

    // NOTES
    // 1- Add the relational comparison in parentheses.
    // 2- We can skip braces for single statements. Braces necessary for multiple statements though.
    // 3- No statements between an if and an else-if.

    // Note that the code is quite verbose. We can make it more concise and efficient.

    return 0;
}


// ==========================================================
// CHARACTER SELECT SCREEN - USING switch
// ==========================================================

// int main () {

//     // Sample menu
//     int user_choice = -1;

//     std::cout << "Select a character type. Press: " << std::endl
//          << "1 - Fighter" << std::endl
//          << "2 - Mage" << std::endl
//          << "3 - Support" << std::endl
//          << "4 - Tank" << std::endl
//          << "5 - Carry" << std::endl
//          << std::endl;

//     std::cin >> user_choice;

//     switch (user_choice) 
//     {
//         // case 'q':
//         // case 'Q':
//         case 1: std::cout << "Fighter selected." << std::endl; 
//                 break;

//         // case 'w':
//         case 2: std::cout << "Mage selected." << std::endl;
//                 break;

//         // case 'e':
//         case 3: std::cout << "Support selected." << std::endl;
//                 break;

//         // case 'r':
//         case 4: std::cout << "Tank selected." << std::endl;
//                 break;

//         // case 't':
//         case 5: std::cout << "Carry selected." << std::endl;
//                 break;

//         // default: std::cout << "Invalid choice. Exiting..." << std::endl;
//     }

//     std::cout << "Last value of user_choice = " << user_choice << std::endl;
//     std::cout << "Out of switch()." << std::endl;

//     /* Note:
//         - Formatting using whitespaces is flexible.
//         - Concise, clear.
//         - Importance of break statements.
//         - You can have multiple statements in a single case and you don't have to worry about braces. 
//         - The ordering of the cases can be however you like.
//         - The "default" keyword does not need to be at the end of all the cases. 
//             You can have it right at the top, or somewhere in between the cases, and it will still work as you'd expect.
//         - Multiple cases doing the same thing. 
//         - switch() can only check ==
//         - Data type of the switch variable should match with the data types you've used in the cases.
//         - Your switch variable can only be compared with, 
//                 a- constants (e.g. case 3) 
//                 b- expressions whose output is constant (e.g. case 7*3-9)
//                 c- constant variables (e.g. const int x = 5, case x)
//         - You can't use floating point numbers for comparison in switch.
//         - You can utilize the way switch works to your advantage.
//             For example you can skip out on break statements in certain cases so that you can generate a particular output.
//             Note that once a case gets matched, switch continues to print everything up until the end of switch unless it encounters a break. 
//     */

//     return 0;
// }

// ==============================================================================
// STRINGS DON'T WORK WITH switch STATEMENT.
// ==============================================================================
// #include <string>
// int main () {

//         std::string user_choice {"Fighter"};
//         std::cout << user_choice;

//         const std::string option1 {"Fighter"};
//         const std::string option2 {"Mage"};

//         switch (user_choice) {
//                 case option1: std::cout << "Fighter selected.";
//                                 break;

//                 case option2: std::cout << "Mage selected.";
//                                 break;

//                 // default is optional. Good practice to add it.
//         }


//         return 0;
// }
// ==============================================================================
