#include <iostream>
#include <cmath>
using namespace std;

// Exercise 3 [25 points]: reads n integers and prints the minimum, maximum,
// average and standard deviation.
// Hint: use pointers to iterate through the array instead of square brackets, e.g., *(arr+i).
int main()
{
    int n;
    cout << "Enter number of values: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ":";
        cin >> *(arr + i);
    }

    // TODO: compute minimum and maximum using pointer arithmetic

    // TODO: compute the average (mean)

    // TODO: compute the standard deviation

    // TODO: print Minimum / Maximum / Average / Standard Deviation

    delete[] arr;
    return 0;
}
