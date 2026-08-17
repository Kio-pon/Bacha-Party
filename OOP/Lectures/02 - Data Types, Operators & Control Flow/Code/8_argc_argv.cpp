/*
    you might come across a weird way main function is defined
        main(int argc, char* argv[])
    this file is a demo to help you understand what this means
    argc stands for "argument count"
    argv stands for "argument vector"
    These are only used when your program is run using the command line/ terminal
    You can think of argv as "list" of statements/ flags passed to your program on terminal
    and agrc as the count of statements/ flags
*/

#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
    }
}

/*
    Now save this file, build it using "g++ file.cpp -o out" (or just click the build button on the upper right corner of
    VS Code). Then open a terminal and go to the folder where "out" is located. And run the command
        "./out -a -b -c -d"
    You will see the commands/ flags you passed using terminal being printed
    You will also see the name of your program, because its always the first element in argv
*/