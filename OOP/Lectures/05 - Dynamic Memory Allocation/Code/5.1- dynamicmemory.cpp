#include <iostream>
using namespace  std;
int main()
{
    
    int* ptrI = new int(34);// find 1*4 = 4 bytes in heap and return the address to ptrI
    int* p = ptrI; // pointing to the same int in heap 

    *ptrI += 1;
    cout << *p <<" " << p<<  endl; //35
    delete ptrI; // releasing the memory
    p = nullptr;
    ptrI = nullptr;
    //======================================
    if(p != nullptr)
         cout << *p <<" " << p<<  endl; // 35
    else    
        cout << "Null pointer\n";


        //Dynamic array  

        int* p_arr = new int[5]{33,5564,222,56,33}; 
     // find 5*4 = 20 bytes in heap and return the address to p_arr

    // print the array in heap pointed by p_arr
        for(int i =0 ; i < 5 ; i++)
        {
                *(p_arr +i)  = 100; // write operation on each element in array pointed by p_arr
                cout << "Value at Address " <<  (p_arr + i) <<" is : " << *(p_arr +i) << endl;
        }
        // releasing the memory
        delete[] p_arr;
        p_arr = nullptr;
//     //static array  - automatic allocation in stack
        int arr[5] = {43,54,334,24,443}; //arrays are  dedicated pointers
    //Array notation   --> pointer notation
//     // arr[0]       --> *(arr+0)   
//     // arr[1]       --> *(arr +1) 
//     // arr[2]       --> *(arr +2) 
//     // arr = arr+2;  // arrays dedicated pointers
                // error : we cannot change the address/reference of array pointer
//     // arr = &d; 

    
    



    return 0 ;
}