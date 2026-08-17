#include <iostream>
using namespace std;

int maxSubArray(int nums[], int n) {
    int maxSum = nums[0];  // initialize with first element

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int nums[100];  // fixed-size array
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Maximum segment sum = " << maxSubArray(nums, n) << endl;
    return 0;
}
