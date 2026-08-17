#include <iostream>
#include <cmath>
using namespace std;

// Exercise 4 [25 points]: computeStatistics takes an array of integers and its
// size, computes mean/median/mode and returns them via pointers, plus a bool
// (mode_cheak) indicating whether a mode actually exists (count > 1).

void sorting(int *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1])
            {
                // Swap if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ComputeStatistics(int *arr, int n, double *mean, double *mode, double *median, bool *mode_cheak)
{
    sorting(arr, n);

    // TODO: compute *mean

    // TODO: compute *median from the sorted array (average the two middle
    // values if n is even, otherwise take the middle value)

    // TODO: compute *mode (most frequent value); if no value repeats,
    // set *mode_cheak = false
}

int main()
{
    int n;
    cout << "Enter number of values: ";
    cin >> n;
    int *arr = new int[n];
    double mean, mode, median;
    bool mode_check = true;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ":";
        cin >> *(arr + i);
    }

    ComputeStatistics(arr, n, &mean, &mode, &median, &mode_check);
    bool modec = false, meanc = false, medianc = false;
    for (int i = 0; i < n; i++)
    {

        if (mode == arr[i])
            modec = true;
        if (mean == arr[i])
            meanc = true;
        if (median == arr[i])
            medianc = true;
    }
    cout << endl
         << "Mean: " << mean << (meanc ? " (Present)" : " (Not Present)");
    cout << endl
         << "Median: " << median << (medianc ? " (Present)" : " (Not Present)");

    if (mode_check)
        cout << endl
             << "Mode: " << mode << (modec ? " (Present)" : " (Not Present)");
    else
        cout << endl
             << "Mode: " << " None  (Not Present)";
    delete[] arr;
    return 0;
}
