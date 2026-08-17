#include <iostream>
using namespace std;

#define ROW 3
#define COL 3

// how to take array input (1d, 2d,...)
int random_function_1(int arr[/*ROW*/]);
int random_function_2(int arr[/*ROW*/][COL]);
int random_function_3(int arr[/*ROW*/][ROW][COL]);

/*
    Important things to notice
    1. To indicate to a function that the argument passed is a list, we use square brackets[]
    2. In case a function's argument is a 1D array, don't need to specify its size
    4. In case a function's argument is 2D or more, we MUST specify all but the first dimenstion
*/

int main(){
    const int SIZE = 3;                 // notice the const

    // Ways to initialize array
    int arr0[] = {1,2,3};               // Size deduced
    int arr1[SIZE];                     
    /*
        1. Use constants when initializing, NOT MUTABLE VARIABLES
        2. Since the array was not initialized, all the values are garbage values
    */
    int arr2[]{1,2,3};                  // Size deduced, no need for "=" sign 
    int arr3[3]{1,2,3};
    int arr4[3] = {};                   // {0, 0, 0}
    int arr5[3]{};                      // {0, 0, 0}

    //Now the weird ones
    int arr6[5]{1,2,3};                 // {1,2,3,0,0}
    int arr7[2][3] = {{1, 2}, {3}};     // {{1,2,0},{3,0,0}}
    int arr8[2][3] = {1, 2, 3, 4};      // {{1,2,3}, {4,0,0}}
      
    // Variable Length Arrays
    int x; 
    cout << "length: "; 
    cin >> x;
    int array_2[x];
    for(auto z : array_2){
        cout << z << endl;
    }
    /*
        Some compilers (like GCC, Clang) allow VLAs as an extension, so it might work there.
        GCC (g++), Clang borrowed it from C99. 
        But it's non-portable and will fail in strict C++ environments
        Will not work on MSVC (Mircrosoft Visual C++)
        NOT ALLOWED IN THIS COURSE EVEN IF G++ IS EXECUTING IT
    */

    // Use nested loops for reaching individual elements of a 2d array
    cout << "----------" << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++) {cout << arr8[i][j] << endl;}
        cout << "," << endl;;
    }

    // A special for loop for arrays - range based loop
    for(int x:arr3) cout << x << endl;
    /*
        follows the patter of python for loops "for item in list"
        here auto x, is an individual iterated item from the array "arr3"
        we can make this even more general
    */

    for(auto x:arr3) cout << x << endl;
    /*
        Why auto? auto tells the compiler to deduce the data type of the item x itself,
        and since this item does not exists outside of this loop, we are not interested in specifying its datatype ourselves
        so we tell compiler to do it itself
    */

    // C++ string
    string first_name = "Tauqeer";
    string last_name = "Saleem";
    string full_name = first_name + " " + last_name;
    cout << full_name << endl;

    /*
        Will something like cout << "Tauqeer " + "Saleem" << endl; work?
        This will not work becuase we are tyring to concatenante C style string literals, not the C++ strings object, 
        which understand that '+' operator means concatenate the strings 
    */
    
    // Strings can be treated as array:
    for(auto x:first_name) cout << x << endl;
}