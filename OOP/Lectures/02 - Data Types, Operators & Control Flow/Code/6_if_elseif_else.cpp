#include <iostream>
using namespace std;

int main(){
    /*
        Lets see the basic structre of an if statement in C++
        if(conditional){
            code block;
        }
        else if (conditional) {
            code block;
        } else {
            code block
        }

        Important things to know:
        1. conditional must result in a boolean (Something with a truth value) or at least an expression
            convertible to bool (like int)
        2. its "else if" in C++ not "elif" like python
        3. "else" does not require a conditional
    */

    bool isThisCLassBoring = false;
    bool isCppBoring = true;

    string answer;
    if (isThisCLassBoring || isCppBoring /*== true*/){
        answer = "Yes";
    }
    else{
        answer = "No";
    }
    // Did you notice, in case of boolean variables, there is no need to use == operator to check their value

    // In simpler cases when the code block is just a single line, we can just ignore the braces
    if (isThisCLassBoring || isCppBoring /*== true*/) answer = "Yes";
    else answer = "No";
    cout << "Is the experience boring? " << answer << endl;

    // You can do the conditional in multiple lines
    if(isThisCLassBoring
       || isCppBoring) answer = "Yes";          // || operator is at the BEGINNING of the second line - legal
    else answer = "No";

    if(isThisCLassBoring ||                     // || operator is at the END of the first line - also legal
       isCppBoring) answer = "Yes";
    else answer = "No";

    /*
        Are you tired of using the complete if else code block for simple tasks?
        If so, let me introduce the ternary operator ?: (dun dun dunnnnnn)
        the format = <condition_to_be_checked>?<output_if_true>:<output_if_false>
        essentially a compact if else statment
    */
    cout << "Is the experience boring? " << (isThisCLassBoring || isCppBoring?"Yes":"No") << endl;
}