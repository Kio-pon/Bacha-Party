/*
    This code demonstrates how the C++ preprocessor expands macros    
    As we learned #define peforms textual resubstitution, what does that mean?
    In the following case when the preprocessor sees #define VALUE 1, 
        The preprocessor replaces every occurrence of the identifier (VALUE) with the replacement text (1)
    
    We can actually see this happen by going to the terminal and running the following code
        g++ -E -P <input_file_name>.cpp -o <output_file_name>.ii
        replace <input_file_name> with whatever file you want to use (in this case preprocessor_demo)
        Explanation of the flags:
            -E tells g++  to stop after preprocessor
            -P omits markliners (don't worry we haven't learned what this is, just assume this makes code readable)
*/

#define VALUE 1

int main(){
    return VALUE;
}
