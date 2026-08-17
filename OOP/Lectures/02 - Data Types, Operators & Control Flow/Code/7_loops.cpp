#include <iostream>
using namespace std;

int main(){
    int x = 0;
    while(x < 5){           // condition
         cout << x << endl; // body
         x++;               // body
    }
    /*
        the only two required parts are:
        -> condition check
        -> body execution

        so no iterator needed, and something like below is perfectly legal!
            while(true){
                body;
                if(condition) break;
            }
        
        Notice, in this case it is possible that the body is never executed if the condition is not satisfied
        But what if you want a case where the loop body is executed at least once
            ie you want to swap the order of condition checked and body executed....

        do....while loop
    */
    
    int z = 10;
    do{
        cout << z << endl;
        z++;
    }while(z < 10);

    /*
        even if the initializer violates the condition z < 10, we enter the loop body first, ensuring that it is executed 
        at least once, before being checked and loop stopped
    */

    /*
        Look back at the simple while loop we made, it has the following structure and sequence:
        -> iterator (x) initialized - ONLY ONCE
        -> loop begins
        -> condition checked - EVERY TIME AT THE BEGINNING OF LOOP
        -> body executed (cout << ...)
        -> iterator incremented (x++)
        
        Instead of initializing an iterator, checking condition, and incrementing the iterator in 3 different lines of code
        we can combine them into a single line using for loop in the following format:
            for(iterator_intialization; conditional; iterator_increment)
        
        for loop is a syntatic sugar for a while loop, It puts initialization, condition, and increment in one place, 
        but the execution order is identical: initialization runs once, then condition–body–increment repeat in a cycle
    */

    for(int i = 0; i < 10; i++){
        cout << "-----" << endl;
        cout << i << endl;
    }

    /*
        Similar "for i in range(0,10,1)" as used in python but more powerful
        why more powerful? the iterator_initialization and iterator_increment can be ANY VALID C++ expression
        So you can have fun with it.
    */

    for (int i = 0, j = 10; i < j; i++, j--) {
        cout << i << " " << j << endl;
    }
    // Not possible in python


    // just like if statements, if the code block is a single line, you can ignore the braces
    for(int i = 0; i < 10; i++) cout << "Yahoo!" << endl;
    

}