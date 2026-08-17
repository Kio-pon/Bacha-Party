#include<iostream>

int main()
{
    int x= 5 ;

    // Pointer is initialized to point at x    
    int* ptr = &x ;
    std::cout << *ptr << '\n';

    int y = 6 ;

    // Pointer now points to y - you can change what the pointer points to after it's created.
    ptr = &y;
    std::cout << *ptr << '\n';


    // Pausing...
    std::cin.get();




    // Changing values of variables through pointers

    // How can I change the value of y through ptr?

    *ptr = 17;
    std::cout << "y = " << y << '\n';
    std::cout << "*ptr = " << *ptr << '\n';


    std::cin.get();


    //Size of a pointer


    char alph = 'a' ;
    int number{ 6 };
    double floating_num{ 98.6 };

    char* c_ptr{ &alph };
    int* i_ptr{ &number };
    double* d_ptr{ &floating_num };

    std::cout << "sizeof(c_ptr) = " << sizeof(c_ptr) << '\n';
    std::cout << "sizeof(i_ptr) = " << sizeof(i_ptr) << '\n';
    std::cout << "sizeof(d_ptr) = " << sizeof(d_ptr) << '\n';

    return 0;
}
