#include <iostream>
using namespace std;

// Pay attention to how double m[][4] is valid here
void printMatrix(double m[][4], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // double matrix[][4]; // NOT VALID
    double matrix[][4] = {
        {1.1, 2.2, 3.3, 4.4},
        {5.5, 6.6, 7.7, 8.8},
        {9.9, 10.1, 11.2, 12.3}
    };

    printMatrix(matrix, 3);
    return 0;
}