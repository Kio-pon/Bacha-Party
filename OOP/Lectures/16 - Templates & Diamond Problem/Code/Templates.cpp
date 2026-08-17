#include <iostream>
#include <vector>

// Meta programming, making the compiler write code for you

/*
    Types of templates (at least the ones we are interested in)
    1. Function templates
    2. Class templates
    3. Non-type template parameters (NTTP)
    4. Variadic templates
*/

/*
    Lets say you want an absolute value function (returns postive)
    You can do something like:

    int ABS(int x){
        return (x>0)? x : -x;
    }

    but this only works for int, what about float and double.
    You can either overload this function for all of those data types
    Or use function templates
*/

template <class T> 
T ABS(T x){
    return (x > 0)? x : -x;
}

// The same idea applied to a print line function
template <typename T> 
void println(T x){
    std::cout << x << std::endl;
}

/*
    But what if the user wants an undetermined number of inputs for the println fucntion
    Just like python's print function
    That's when we use variadic template
    This allows to take in arbritary number of inputs
*/
template <typename... Args>
void println(Args... args) {
    (std::cout << ... << args) << "\n"; // fold expression (C++17)
}


/*
    We can implement it differently
    Base case: no arguments - just a end line statement
    
    void println() {
        std::cout << std::endl;
    }

    Recursive template: one or more arguments
    
    template <typename T, typename... Args>
    void println(T first, Args... rest) {
        std::cout << first << " ";
        println(rest...);
    }

    We split all of the arguments into two parts
    - one single argument called first
    - and the rest
    We print "frist" and then call the same function again on rest
    It will keep calling itself recursively untill there are no arguments left
    Then it will revert to base case

*/

/*
    The same concepts applied to classes make class templates
    But this time around notice some other changes
    1 - there are multiple template parameters (class T, int N)
    2 - one of the template parameters is not a generic typename or class, its a primitive int
    3 - This primitive is then used to construct the class Array with a size N
        This is non-type template parameter
*/

template <class T, int N>
class Array{
    private:
        T arr[N];
    public:
        int getSize() const {return N;}
};

// Generic Stack
template <typename T>
class Stack {
    std::vector<T> data;
public:
    void push(const T& v) {data.push_back(v); }
    T pop() {
        T v = data.back();
        data.pop_back();
        return v;
    }
};

/*
    The idea of non-type template parameters applied here to make a matrix of custom size
*/ 
template <size_t R, size_t C>
struct Matrix {
    double m[R][C];
};

int main(){
    println(1);
    println(1.1);
    println('a');
    println("lol");
    Array<int, 3> X;
    println("The size of X is ", X.getSize(), ", multi-line works");
    
}