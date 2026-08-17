// first file
#include <iostream>
#include <limits> // for numeric_limits
#include <cstring>

using namespace std;

int main(){
    /*
        C string is a primitive implementation of strings in C.
        It only exists in C++ for backwards implementation with C.

        It is just an array of strings.
        But remember since it an array, and there are no VALs C++, we need a fixed length.
        Fixed length can be a maximum size of string.
    */

    const int MAX = 100;
    char str_1[MAX];
    cout << "Input 0: " << endl; 
    cin >> str_1;
    cout << "Your C-String 1: " << str_1 << endl;

    /*
        How do you take input with spaces in it?
        cin >> str_1; by default takes in input until the first whitespace or enter.

        So we do:
            cin.getline(input_var, length);
    */
    
    char str_2[MAX + 1];
    cout << "Input 1: " << endl;
    cin.getline(str_2, MAX);
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Your C-String 2: " << str_2 << endl;

    /*
        Notice that cin will not work for the second time, without cin.ignore() [Experiment yourself]

        Now we introduce the concept of buffer:
        A buffer is just a chunk of memory that sits between you (the program) and some slower input/output device 
        (like the keyboard, console, or file).
        Think of it as a "waiting room" where data is stored temporarily before being read or written.

        If you don't manage your buffer, there will be left-over characters in it, that will mess up with your cin

        THIS IS IMPORTATN: put the ignore right after getline!!!!

        cin.ignore(n, delim)

            n: Maximum number of characters to discard.

            delim: The character that will stop the ignoring (it gets removed too).

        numeric_limits<streamsize>::max()

            This gives the maximum value that a streamsize (the type used by streams for counting characters) can hold.

            It’s essentially “a ridiculously huge number,” much larger than any real input.

            So, this says: ignore everything until you hit the delimiter.

        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

            "Flush the input buffer up to and including the next newline, no matter how many characters are there."
    
    */

    char str_3[5 + 1];
    cout << "Input 2: " << endl;
    cin.getline(str_3, 5 + 1);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Your C-String 3: " << str_3 << endl;

    /*
        Notice, we have been doing char str[MAX + 1], and then cin.getline(str, MAX)
        Also why MAX + 1 when initializing, and why MAX when taking input?

        It is for the \0 = terminating zero called the null character
            When initializing we want one extra charater for \0 (apart from our input which we say is going to be of size MAX)
            Whne taking input, we don't need to specify \0, so we take input of MAX
    */


    /*
        Can intialize strings like any array
    */

    char str_4[] = "Hello World!";

    /*
        Lets copy one C-string into another using for loop;

        Things to notice:
        1. The stop condition is basically looking for the null char '\0
        2. Every step we are assigning the next character as '\0'. Why?
            Because that way when we end the loop, we will make sure the last charater is the null '\0'
    */


    /*
        Lets dicuss some functions:
        1. strcat()
        2. strcmp()
        3. strcpy()
        4. strlen()
    */
    char copy_str[MAX];
    for(int i = 0; str_4[i] != '\0'; i++){
        copy_str[i] = str_4[i];
        copy_str[i + 1] = '\0';
    }

    cout << copy_str << endl;

    char dest[100];
    strcpy(dest, str_4);   // Copies including '\0'

    char str_5[100] = "Hello ";
    char str_6[100] = "Hello ";
    strcat(str_5, str_6);  // str_5 now holds "Hello World"

    if (strcmp("abc", "abd") < 0) cout << "abc < abd";

    cout << strlen("Hello");  // Prints 5
}