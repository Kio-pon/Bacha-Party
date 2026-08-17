#include<iostream>

using namespace std;
void  greetings(string str)
{
    cout  << "Hello, " << str;
    return;
    cout << "C++";
    

}
int main()
{

    long long unsigned int a = 42;
    cout << "Value of a = " << a << endl;
    cout << "Address of a = " << &a <<endl;

    



    int arr[5] = {4,3,6,7,1}; // array of 5 int
    //total bytes of arr = 4*5 20 bytes

    for (int i =0 ; i < 5 ; i++) // i++ = i = i+1 , i+= 2 --> i = i +2 
    {
        cout << arr[i]  << " " << &arr[i] << endl;
    }

    cout << sizeof(a) << endl;
    cout << sizeof(arr) << endl;

    greetings("Nadia");
    return 0;


    



  
}