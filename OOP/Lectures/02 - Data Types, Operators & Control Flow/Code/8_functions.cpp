/*
    Some importatnt things to know about variable scope in C++ 
        a. Global scope = accessable by everyone
        b. Functional scope = accessable only in a function
        c. Block scope = accessable only in a block (for example in an for loop block, 
            the iterator variable i is not accessable outside of the loop) 
            IMPORTANT: Block scope is not in python, if you define a variable within loop, 
            it is also availble outside of the loop and it is called loop variable leak in python
*/

#include <iostream>
using namespace std;

const int x = 10; //global scope, everyone cna access it

int adder(int a, int b); 
/*
    This is called a declaration - telling compiler that it should not panic if it sees a function called "adder"
    The actual implementation (called defintion) of this function may be after the main function or in the case of
    big projects might be in a seprate file.

    In declarations and definitions the "inputs" like int a and int b are called arguments of a function.
    When we are acutally call a funtion and pass some values to it, these inputs are called parameters
    Something that won't acutally impact your coding, but its the C++ lingo
*/

int main(){
    // Important! You cannot define a function within another function
    // so no function defintions here!
    for(
        int i = 10, j = 0;
        i > 5;
        i--, j++
    )
    {
        int out = adder(i, j); //i and j are this function's parameters
        /*
            the variable out has block scope (only defiend in withing the two squigly braces around it)
            Experiment in python, there is no such thing as block scope!
            i and j are also defined within this block (block scope)
        */
        cout << "added " << i << " and " << j << " to get " << out << endl;
    }
            
}

int adder(int a, int b){
    int temp = a + b; // functional scope (temp is only accesible here in this function)
    return temp;
}

/*
    This now is the defintion of the function "added"
    Notice you need to specify the compiler the return type of function in both defintion and declaration
    "int" at the beginning is the return type
*/

// what if what you do has no return (like simply printing a line)
void random_function(){
    cout << "lol" << endl;
} 

// void tells compiler not to expect a return from this function