#include <iostream>

// NOTE: Please save your code (also), compile, and then run the executable to reflect any changes. 

int main () {

    // Example from book with different variable names.
    int caitlyn = 44; //assignment statement
    int viktor = 12; //assignment statement

    std::cout << "(caitlyn == viktor): "    << (caitlyn == viktor)  << std::endl;               //false
    std::cout << "(viktor <= 12): "         << (viktor <= 12)       << std::endl;               //true
    std::cout << "(caitlyn > viktor): "     << (caitlyn > viktor)   << std::endl;               //true
    std::cout << "(caitlyn >= 44): "        << (caitlyn >= 44)      << std::endl;               //true
    std::cout << "(viktor != 12): "         << (viktor != 12)       << std::endl;               //false
    std::cout << "(7 < viktor): "           << (7 < viktor)         << std::endl << std::endl;  //true
    
    // ============================================================================================
    // Representation of true and false in C++
    // -------------------------------------------

    // Works with both int and bool.
    int draven = 0, annie = -54, riven = 32, f = false, t = true;

    std::cout << "draven: " << draven << std::endl;     //false (by definition)
    std::cout << "riven: " << riven << std::endl;       //true (since it’s not 0)
    std::cout << "annie: " << annie << std::endl;       //true (since it's not 0)
    std::cout << "f: " << f << std::endl;
    std::cout << "t: " << t << std::endl << std::endl;

    if (draven) {
        std::cout << "I'm Draven" << std::endl;
    }
    else {
        std::cout << "Draven got skipped.\n";
    }

    if (annie) {
        std::cout << "I'm Annie" << std::endl;
    }

    if (riven) {
        std::cout << "I'm Riven" << std::endl;
    }

    return 0;
}
