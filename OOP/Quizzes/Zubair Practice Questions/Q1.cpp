#include <iostream>
using namespace std;

int rowSum(int mat[100][100], int N, int r) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
        sum += mat[r][j];
    }
    return sum;
}

int colSum(int mat[100][100], int N, int c) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += mat[i][c];
    }
    return sum;
}

int diagSum(int mat[100][100], int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += mat[i][i];
    }
    return sum;
}

int main() {
    int N;
    cout << "Enter matrix size N: ";
    cin >> N;

    int mat[100][100];  // fixed size array

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    int r, c;
    cout << "Enter row number (0-based): ";
    cin >> r;
    cout << "Enter column number (0-based): ";
    cin >> c;

    cout << "Row sum = " << rowSum(mat, N, r) << endl;
    cout << "Column sum = " << colSum(mat, N, c) << endl;
    cout << "Diagonal sum = " << diagSum(mat, N) << endl;

    return 0;
}
