#include <iostream>
#include <cstring>

using namespace std;

// Exercise 2 [25 points]: sorts an array of strings using pointers.
// Practices arrays of characters, pointer arithmetic, and string comparison.
void sorting(char **arr, int n)
{
    // TODO: bubble sort (or similar) the array of C-strings using strcmp,
    // swapping the char* pointers rather than the string contents
}

int main()
{
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    cin.ignore();
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[100];
        cin.getline(arr[i], 100);
    }
    sorting(arr, n);
    cout << endl
         << "Sorted array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
