// pointer arithmetic
#include <iostream>
using namespace  std;
int main()
{
    //nullptr , dangling pointers , reference variable
    int x = 0 ;

    int* p = nullptr;  // 0 , nullptr , NULL
    if(p)
        cout << *p << endl;
    else
        cout << "Null Pointer\n";
    //dangling pointer???
     //==================
    int y = 888; // in main()
    {
        int yy = 99;// scope of y -- within this block 
        // y is a local variable in  block
        p = &yy;
        cout << "Value of yy : "<< yy << "Address of yy : "<< &yy << endl;
        cout << "Value of yy : "<< *p << "Address of yy : "<< p << endl;
        //p = nullptr;  
        //no need to use delete statement with p since automatic memory allocation done by the program
    } 
        //cout << yy;
      cout << "Value of yy : "<< *p << "Address of yy : "<< p << endl;
        // p is a dangling pointer 
        // solution : uncomment the line number 23

    
    



    return 0;
}