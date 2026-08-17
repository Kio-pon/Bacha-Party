#include <iostream>
using namespace std;

// 3.4 Fibonacci (i): recursive fib(n) that returns the nth Fibonacci number
// (sequence starts 1, 1, 2, 3, 5, ...). fib(-1) should report how many times
// fib() was called (using a static counter).
long long fib(long long n)
{
    // TODO: implement recursively, counting calls via a static counter,
    // and returning that count when n < 0
    return 0;
}

int main()
{
    long long n;
    cout << "Enter the number of term you want to find: ";
    cin >> n;
    cout << "Fibonacci is : " << fib(n) << endl;
    cout << "The function was called " << fib(-1) << " times";
}
