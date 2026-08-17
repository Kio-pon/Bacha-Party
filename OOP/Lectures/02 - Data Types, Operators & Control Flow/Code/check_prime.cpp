#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    bool isPrime = true;

    if (n <= 1) {
        isPrime = false;  // 0 and 1 are not prime
    } else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isPrime = false;
                break; // No need to check further
            }
        }
    }

    if (isPrime) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}