/* 
    We continue with the demo and this time focus on another preprocessor directive #include
    As the name suggest #inlcude just includes another file in our code
    This other file is called a "header"
    A header typically contains declarations (and sometimes definitions such as inline/template code), 
        but rarely full function definitions of standard library functions. <REMEMBER DECLARATION VS DEFINITION FROM LEC 2?>
    
    You can actually see this by going to the terminal and running the following code
        g++ -E -P <input_file_name>.cpp -o <output_file_name>.ii

    You will notice a simple 3 line code turned into a thousand line monstrosity.
    The preprocessor replaced the line "#include <iostream>" with the actual header file called iostream
        Notice there will almost no function definition in the output, only declarations
        Then you might ask, 
            1. where are these functions implemeted (aka where are they defined)?
            2. How does the compiler know what these functions do if they are not even defined in the header?

    ANSWER: C++ Standard Library. Everytime you run a C++ file with a header like <iostream>, the linker links your code
        with the C++ Standard Library (by default) and that is where the implementation of iostream is present

    What is a linker? You can find it in the ppt shared.
*/

#include <iostream> // expands to thousands of line of declarations


int main(){
    std::cout << "Hello World!" << std::endl;
}