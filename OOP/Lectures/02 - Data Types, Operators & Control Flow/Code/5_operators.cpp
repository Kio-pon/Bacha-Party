/*
    A note on operators.
        we have already used some operators
        Logical:
        !  -> NOT logical operator
        || -> OR logical operator
        && -> AND logical operator

        Arithemetic:
        +  -> adds
        -  -> subtracts
        /  -> divides
        *  -> multiplies
        %  -> mod (returns the reminder)
        << -> insertion operator (in iostream)
        >> -> extraction operator (in iostream)

        Relational:
        < or >   -> smaller/ greater than
        <= or >= -> smaller/ greater than or equal to
        =        -> assignment operator
        ==       -> equality

        Bitwise:
        You won't see them in this course, so I will not go in their details


        Important note: Except logical operators, all other LISTED OPERATORS ABOVE can be repurposed to be used in a different way 
            for different classes!
            For example look at the following code:
                
                string fname = "Tauqeer";
                string lname = "Saleem";
                cout << fname + lname << endl;
            
            Does the + sign mean add the two strings, like adding integers? or concatenate the two strings? 
            Clearly its the later in case of strings

            This is called operator overloading, and we will learn this in future. For now just remember that these symbols
            can mean different things for different data types 
*/

#include <iostream>
using namespace std;

int main(){
    // Increment operator
    int a = 1;
    cout << ++a << endl; // pre increment - the console prints 2
    cout << a++ << endl; // post increment - the console STILL prints 2 and then increments
    cout << a << endl;   // Now we see that the variable is incremented and the output should be 3

    // since C++ (orignally called C with Classes) is the next version of C programing language
    // someone had the bright idea to call C with Classes, C++
}