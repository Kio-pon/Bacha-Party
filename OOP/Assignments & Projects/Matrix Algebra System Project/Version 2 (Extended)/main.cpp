#include <iostream>
#include "MatrixAlgebraSystem.hpp"
#include <string>

std::ostream& operator<<(std::ostream&, const Matrix&);  // for printing purposes

//Addition
int** addMatrices(int** A, int** B, int r, int c) {
    int** result = new int*[r];
    for (int i = 0; i < r; ++i) result[i] = new int[c];

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[i][j] = A[i][j] + B[i][j];

    return result;
}

// Subtraction
int** subtractMatrices(int** A, int** B, int r, int c) {
    int** result = new int*[r];
    for (int i = 0; i < r; ++i) result[i] = new int[c];

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[i][j] = A[i][j] - B[i][j];

    return result;
}

// Multiplication
int** multiplyMatrices(int** A, int r1, int c1, int** B, int r2, int c2) {
    if (c1 != r2) throw std::invalid_argument("Matrix dimensions are incompatible for multiplication");

    int** result = new int*[r1];
    for (int i = 0; i < r1; ++i) result[i] = new int[c2]();

    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j)
            for (int k = 0; k < c1; ++k)
                result[i][j] += A[i][k] * B[k][j];

    return result;
}

void printMatrix(int** matrix, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int** createMatrix(int r, int c, const int arr[]) {
    int** matrix = new int*[r];
    for (int i = 0; i < r; ++i) {
        matrix[i] = new int[c];
    }

    int index = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            matrix[i][j] = arr[index++];
        }
    }

    return matrix;
}

int compare(int** Expected, const Matrix& Result, std::string TestCase)
{
    for (int i = 0; i < Result.getRows(); ++i) {
        for (int j = 0; j < Result.getCols(); ++j) {
           if (Result.getElement(i, j) != Expected[i][j]) {
                std::cout << TestCase << " is incorrect ❌" << std::endl;
                return 0;
            }
        }
    }
    std::cout << TestCase << " is correct ✅" << std::endl;
    return 1;
}


int main() {
{
std::cout << "================== 2 x 2 MATRIX TEST ====================" << std::endl;

    int flag;

    int data[] = {42, -82, 19, -6};
    int** Me = createMatrix(2, 2, data);
    int data1[] = {-34, 72, 5, -91};
    int** Se = createMatrix(2, 2, data1);
    int data2[] = {88, 0, 0, -57};
    int** De = createMatrix(2, 2, data2);
    int data3[] = {-42, 0, 67, 9};
    int** Le = createMatrix(2, 2, data3);
    int data4[] = {54, -23, 0, 81};
    int** Ue = createMatrix(2, 2, data4);

    Matrix* M = new Matrix(2, 2);              // a 2x2 matrix
    Matrix* S = new SquareMatrix(2);           // a 2x2 square matrix
    Matrix* D = new DiagonalMatrix(2);         // a 2x2 diagonal matrix
    Matrix* L = new LowerTriangularMatrix(2);  // a 2x2 lower triangular matrix
    Matrix* U = new UpperTriangularMatrix(2);  // a 2x2 upper triangular matrix

    M->setElement(0, 0, 42);
    M->setElement(0, 1, -82);
    M->setElement(1, 0, 19);
    M->setElement(1, 1, -6);

    S->setElement(0, 0, -34);
    S->setElement(0, 1, 72);
    S->setElement(1, 0, 5);
    S->setElement(1, 1, -91);

    D->setElement(0, 0, 88);
    D->setElement(1, 1, -57);

    L->setElement(0, 0, -42);
    L->setElement(1, 0, 67);
    L->setElement(1, 1, 9);

    U->setElement(0, 0, 54);
    U->setElement(0, 1, -23);
    U->setElement(1, 1, 81);

    flag = compare(Me, *M, "Initalizing a Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M = " << std::endl << *M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me, 2, 2);
    }

    flag = compare(Se, *S, "Initalizing a Square Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S = " << std::endl << *S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se, 2, 2);
    }
    
    flag = compare(De, *D, "Initalizing a Diagonal Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D = " << std::endl << *D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De, 2, 2);
    }

    flag = compare(Le, *L, "Initalizing a Lower Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M = " << std::endl << *M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le, 2, 2);
    }
    
    flag = compare(Ue, *U, "Initalizing a Upper Matrix");
        if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U = " << std::endl << *U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue, 2, 2);
    }

    const Matrix M_plus_M = *M + *M;
    int** Me_plus_Me = addMatrices(Me, Me, 2, 2);
    flag = compare(Me_plus_Me, M_plus_M, "M + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + M = " << std::endl << M_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Me, 2, 2);
    }


    const Matrix M_minus_M = *M - *M;
    int** Me_minus_Me = subtractMatrices(Me, Me, 2, 2);
    flag = compare(Me_minus_Me, M_minus_M, "M - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - M = " << std::endl << M_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Me, 2, 2);
    }

    const Matrix M_mult_M = *M * *M;
    int** Me_mult_Me = multiplyMatrices(Me, 2, 2, Me, 2, 2);
    flag = compare(Me_mult_Me, M_mult_M, "M * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * M = " << std::endl << M_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Me, 2, 2);
    }
    
    const Matrix M_plus_S = *M + *S;
    int** Me_plus_Se = addMatrices(Me, Se, 2, 2);
    flag = compare(Me_plus_Se, M_plus_S, "M + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + S = " << std::endl << M_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Se, 2, 2);
    }


    const Matrix M_minus_S = *M - *S;
    int** Me_minus_Se = subtractMatrices(Me, Se, 2, 2);
    flag = compare(Me_minus_Se, M_minus_S, "M - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - S = " << std::endl << M_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Se, 2, 2);
    }

    const Matrix M_mult_S = *M * *S;
    int** Me_mult_Se = multiplyMatrices(Me, 2, 2, Se, 2, 2);
    flag = compare(Me_mult_Se, M_mult_S, "M * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * S = " << std::endl << M_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Se, 2, 2);
    }

    const Matrix M_plus_D = *M + *D;
    int** Me_plus_De = addMatrices(Me, De, 2, 2);
    flag = compare(Me_plus_De, M_plus_D, "M + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + D = " << std::endl << M_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_De, 2, 2);
    }


    const Matrix M_minus_D = *M - *D;
    int** Me_minus_De = subtractMatrices(Me, De, 2, 2);
    flag = compare(Me_minus_De, M_minus_D, "M - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - D = " << std::endl << M_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_De, 2, 2);
    }

    const Matrix M_mult_D = *M * *D;
    int** Me_mult_De = multiplyMatrices(Me, 2, 2, De, 2, 2);
    flag = compare(Me_mult_De, M_mult_D, "M * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * D = " << std::endl << M_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_De, 2, 2);
    }
    
    const Matrix M_plus_L = *M + *L;
    int** Me_plus_Le = addMatrices(Me, Le, 2, 2);
    flag = compare(Me_plus_Le, M_plus_L, "M + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + L = " << std::endl << M_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Le, 2, 2);
    }


    const Matrix M_minus_L = *M - *L;
    int** Me_minus_Le = subtractMatrices(Me, Le, 2, 2);
    flag = compare(Me_minus_Le, M_minus_L, "M - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - L = " << std::endl << M_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Le, 2, 2);
    }

    const Matrix M_mult_L = *M * *L;
    int** Me_mult_Le = multiplyMatrices(Me, 2, 2, Le, 2, 2);
    flag = compare(Me_mult_Le, M_mult_L, "M * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * L = " << std::endl << M_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Le, 2, 2);
    }

    const Matrix M_plus_U = *M + *U;
    int** Me_plus_Ue = addMatrices(Me, Ue, 2, 2);
    flag = compare(Me_plus_Ue, M_plus_U, "M + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + U = " << std::endl << M_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Ue, 2, 2);
    }


    const Matrix M_minus_U = *M - *U;
    int** Me_minus_Ue = subtractMatrices(Me, Ue, 2, 2);
    flag = compare(Me_minus_Ue, M_minus_U, "M - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - U = " << std::endl << M_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Ue, 2, 2);
    }

    const Matrix M_mult_U = *M * *U;
    int** Me_mult_Ue = multiplyMatrices(Me, 2, 2, Ue, 2, 2);
    flag = compare(Me_mult_Ue, M_mult_U, "M * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * U = " << std::endl << M_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Ue, 2, 2);
    }

    const Matrix S_plus_M = *S + *M;
    int** Se_plus_Me = addMatrices(Se, Me, 2, 2);
    flag = compare(Se_plus_Me, S_plus_M, "S + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + M = " << std::endl << S_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Me, 2, 2);
    }


    const Matrix S_minus_M = *S - *M;
    int** Se_minus_Me = subtractMatrices(Se, Me, 2, 2);
    flag = compare(Se_minus_Me, S_minus_M, "S - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - M = " << std::endl << S_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Me, 2, 2);
    }

    const Matrix S_mult_M = *S * *M;
    int** Se_mult_Me = multiplyMatrices(Se, 2, 2, Me, 2, 2);
    flag = compare(Se_mult_Me, S_mult_M, "S * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * M = " << std::endl << S_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Me, 2, 2);
    }


    const Matrix S_plus_S = *S + *S;
    int** Se_plus_Se = addMatrices(Se, Se, 2, 2);
    flag = compare(Se_plus_Se, S_plus_S, "S + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + S = " << std::endl << S_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Se, 2, 2);
    }


    const Matrix S_minus_S = *S - *S;
    int** Se_minus_Se = subtractMatrices(Se, Se, 2, 2);
    flag = compare(Se_minus_Se, S_minus_S, "S - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - S = " << std::endl << S_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Se, 2, 2);
    }

    const Matrix S_mult_S = *S * *S;
    int** Se_mult_Se = multiplyMatrices(Se, 2, 2, Se, 2, 2);
    flag = compare(Se_mult_Se, S_mult_S, "S * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * S = " << std::endl << S_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Se, 2, 2);
    }

    const Matrix S_plus_D = *S + *D;
    int** Se_plus_De = addMatrices(Se, De, 2, 2);
    flag = compare(Se_plus_De, S_plus_D, "S + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + D = " << std::endl << S_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_De, 2, 2);
    }


    const Matrix S_minus_D = *S - *D;
    int** Se_minus_De = subtractMatrices(Se, De, 2, 2);
    flag = compare(Se_minus_De, S_minus_D, "S - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - D = " << std::endl << S_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_De, 2, 2);
    }

    const Matrix S_mult_D = *S * *D;
    int** Se_mult_De = multiplyMatrices(Se, 2, 2, De, 2, 2);
    flag = compare(Se_mult_De, S_mult_D, "S * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * D = " << std::endl << S_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_De, 2, 2);
    }   

    const Matrix S_plus_L = *S + *L;
    int** Se_plus_Le = addMatrices(Se, Le, 2, 2);
    flag = compare(Se_plus_Le, S_plus_L, "S + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + L = " << std::endl << S_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Le, 2, 2);
    }


    const Matrix S_minus_L = *S - *L;
    int** Se_minus_Le = subtractMatrices(Se, Le, 2, 2);
    flag = compare(Se_minus_Le, S_minus_L, "S - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - L = " << std::endl << S_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Le, 2, 2);
    }

    const Matrix S_mult_L = *S * *L;
    int** Se_mult_Le = multiplyMatrices(Se, 2, 2, Le, 2, 2);
    flag = compare(Se_mult_Le, S_mult_L, "S * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * L = " << std::endl << S_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Le, 2, 2);
    }  

    const Matrix S_plus_U = *S + *U;
    int** Se_plus_Ue = addMatrices(Se, Ue, 2, 2);
    flag = compare(Se_plus_Ue, S_plus_U, "S + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + U = " << std::endl << S_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Ue, 2, 2);
    }


    const Matrix S_minus_U = *S - *U;
    int** Se_minus_Ue = subtractMatrices(Se, Ue, 2, 2);
    flag = compare(Se_minus_Ue, S_minus_U, "S - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - U = " << std::endl << S_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Ue, 2, 2);
    }

    const Matrix S_mult_U = *S * *U;
    int** Se_mult_Ue = multiplyMatrices(Se, 2, 2, Ue, 2, 2);
    flag = compare(Se_mult_Ue, S_mult_U, "S * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * U = " << std::endl << S_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Ue, 2, 2);
    }  

    const Matrix D_plus_M = *D + *M;
    int** De_plus_Me = addMatrices(De, Me, 2, 2);
    flag = compare(De_plus_Me, D_plus_M, "D + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + M = " << std::endl << D_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Me, 2, 2);
    }


    const Matrix D_minus_M = *D - *M;
    int** De_minus_Me = subtractMatrices(De, Me, 2, 2);
    flag = compare(De_minus_Me, D_minus_M, "D - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - M = " << std::endl << D_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Me, 2, 2);
    }

    const Matrix D_mult_M = *D * *M;
    int** De_mult_Me = multiplyMatrices(De, 2, 2, Me, 2, 2);
    flag = compare(De_mult_Me, D_mult_M, "D * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * M = " << std::endl << D_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Me, 2, 2);
    }  

    const Matrix D_plus_S = *D + *S;
    int** De_plus_Se = addMatrices(De, Se, 2, 2);
    flag = compare(De_plus_Se, D_plus_S, "D + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + S = " << std::endl << D_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Se, 2, 2);
    }


    const Matrix D_minus_S = *D - *S;
    int** De_minus_Se = subtractMatrices(De, Se, 2, 2);
    flag = compare(De_minus_Se, D_minus_S, "D - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - S = " << std::endl << D_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Se, 2, 2);
    }

    const Matrix D_mult_S = *D * *S;
    int** De_mult_Se = multiplyMatrices(De, 2, 2, Se, 2, 2);
    flag = compare(De_mult_Se, D_mult_S, "D * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * S = " << std::endl << D_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Se, 2, 2);
    }  

    const Matrix D_plus_D = *D + *D;
    int** De_plus_De = addMatrices(De, De, 2, 2);
    flag = compare(De_plus_De, D_plus_D, "D + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + D = " << std::endl << D_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_De, 2, 2);
    }


    const Matrix D_minus_D = *D - *D;
    int** De_minus_De = subtractMatrices(De, De, 2, 2);
    flag = compare(De_minus_De, D_minus_D, "D - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - D = " << std::endl << D_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_De, 2, 2);
    }

    const Matrix D_mult_D = *D * *D;
    int** De_mult_De = multiplyMatrices(De, 2, 2, De, 2, 2);
    flag = compare(De_mult_De, D_mult_D, "D * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * D = " << std::endl << D_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_De, 2, 2);
    }  

    const Matrix D_plus_L = *D + *L;
    int** De_plus_Le = addMatrices(De, Le, 2, 2);
    flag = compare(De_plus_Le, D_plus_L, "D + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + L = " << std::endl << D_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Le, 2, 2);
    }


    const Matrix D_minus_L = *D - *L;
    int** De_minus_Le = subtractMatrices(De, Le, 2, 2);
    flag = compare(De_minus_Le, D_minus_L, "D - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - L = " << std::endl << D_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Le, 2, 2);
    }

    const Matrix D_mult_L = *D * *L;
    int** De_mult_Le = multiplyMatrices(De, 2, 2, Le, 2, 2);
    flag = compare(De_mult_Le, D_mult_L, "D * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * L = " << std::endl << D_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Le, 2, 2);
    }  

    const Matrix D_plus_U = *D + *U;
    int** De_plus_Ue = addMatrices(De, Ue, 2, 2);
    flag = compare(De_plus_Ue, D_plus_U, "D + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + U = " << std::endl << D_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Ue, 2, 2);
    }


    const Matrix D_minus_U = *D - *U;
    int** De_minus_Ue = subtractMatrices(De, Ue, 2, 2);
    flag = compare(De_minus_Ue, D_minus_U, "D - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - U = " << std::endl << D_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Ue, 2, 2);
    }

    const Matrix D_mult_U = *D * *U;
    int** De_mult_Ue = multiplyMatrices(De, 2, 2, Ue, 2, 2);
    flag = compare(De_mult_Ue, D_mult_U, "D * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * U = " << std::endl << D_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Ue, 2, 2);
    }  

    const Matrix L_plus_M = *L + *M;
    int** Le_plus_Me = addMatrices(Le, Me, 2, 2);
    flag = compare(Le_plus_Me, L_plus_M, "L + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + M = " << std::endl << L_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Me, 2, 2);
    }


    const Matrix L_minus_M = *L - *M;
    int** Le_minus_Me = subtractMatrices(Le, Me, 2, 2);
    flag = compare(Le_minus_Me, L_minus_M, "L - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - M = " << std::endl << L_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Me, 2, 2);
    }

    const Matrix L_mult_M = *L * *M;
    int** Le_mult_Me = multiplyMatrices(Le, 2, 2, Me, 2, 2);
    flag = compare(Le_mult_Me, L_mult_M, "L * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * M = " << std::endl << L_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Me, 2, 2);
    } 

    const Matrix L_plus_S = *L + *S;
    int** Le_plus_Se = addMatrices(Le, Se, 2, 2);
    flag = compare(Le_plus_Se, L_plus_S, "L + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + S = " << std::endl << L_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Se, 2, 2);
    }


    const Matrix L_minus_S = *L - *S;
    int** Le_minus_Se = subtractMatrices(Le, Se, 2, 2);
    flag = compare(Le_minus_Se, L_minus_S, "L - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - S = " << std::endl << L_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Se, 2, 2);
    }

    const Matrix L_mult_S = *L * *S;
    int** Le_mult_Se = multiplyMatrices(Le, 2, 2, Se, 2, 2);
    flag = compare(Le_mult_Se, L_mult_S, "L * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * S = " << std::endl << L_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Se, 2, 2);
    } 

    const Matrix L_plus_D = *L + *D;
    int** Le_plus_De = addMatrices(Le, De, 2, 2);
    flag = compare(Le_plus_De, L_plus_D, "L + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + D = " << std::endl << L_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_De, 2, 2);
    }


    const Matrix L_minus_D = *L - *D;
    int** Le_minus_De = subtractMatrices(Le, De, 2, 2);
    flag = compare(Le_minus_De, L_minus_D, "L - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - D = " << std::endl << L_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_De, 2, 2);
    }

    const Matrix L_mult_D = *L * *D;
    int** Le_mult_De = multiplyMatrices(Le, 2, 2, De, 2, 2);
    flag = compare(Le_mult_De, L_mult_D, "L * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * D = " << std::endl << L_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_De, 2, 2);
    } 

    const Matrix L_plus_L = *L + *L;
    int** Le_plus_Le = addMatrices(Le, Le, 2, 2);
    flag = compare(Le_plus_Le, L_plus_L, "L + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + L = " << std::endl << L_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Le, 2, 2);
    }


    const Matrix L_minus_L = *L - *L;
    int** Le_minus_Le = subtractMatrices(Le, Le, 2, 2);
    flag = compare(Le_minus_Le, L_minus_L, "L - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - L = " << std::endl << L_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Le, 2, 2);
    }

    const Matrix L_mult_L = *L * *L;
    int** Le_mult_Le = multiplyMatrices(Le, 2, 2, Le, 2, 2);
    flag = compare(Le_mult_Le, L_mult_L, "L * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * L = " << std::endl << L_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Le, 2, 2);
    } 

    const Matrix L_plus_U = *L + *U;
    int** Le_plus_Ue = addMatrices(Le, Ue, 2, 2);
    flag = compare(Le_plus_Ue, L_plus_U, "L + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + U = " << std::endl << L_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Ue, 2, 2);
    }


    const Matrix L_minus_U = *L - *U;
    int** Le_minus_Ue = subtractMatrices(Le, Ue, 2, 2);
    flag = compare(Le_minus_Ue, L_minus_U, "L - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - U = " << std::endl << L_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Ue, 2, 2);
    }

    const Matrix L_mult_U = *L * *U;
    int** Le_mult_Ue = multiplyMatrices(Le, 2, 2, Ue, 2, 2);
    flag = compare(Le_mult_Ue, L_mult_U, "L * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * U = " << std::endl << L_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Ue, 2, 2);
    } 

    const Matrix U_plus_M = *U + *M;
    int** Ue_plus_Me = addMatrices(Ue, Me, 2, 2);
    flag = compare(Ue_plus_Me, U_plus_M, "U + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + M = " << std::endl << U_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Me, 2, 2);
    }


    const Matrix U_minus_M = *U - *M;
    int** Ue_minus_Me = subtractMatrices(Ue, Me, 2, 2);
    flag = compare(Ue_minus_Me, U_minus_M, "U - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - M = " << std::endl << U_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Me, 2, 2);
    }

    const Matrix U_mult_M = *U * *M;
    int** Ue_mult_Me = multiplyMatrices(Ue, 2, 2, Me, 2, 2);
    flag = compare(Ue_mult_Me, U_mult_M, "U * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * M = " << std::endl << U_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Me, 2, 2);
    } 

    const Matrix U_plus_S = *U + *S;
    int** Ue_plus_Se = addMatrices(Ue, Se, 2, 2);
    flag = compare(Ue_plus_Se, U_plus_S, "U + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + S = " << std::endl << U_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Se, 2, 2);
    }


    const Matrix U_minus_S = *U - *S;
    int** Ue_minus_Se = subtractMatrices(Ue, Se, 2, 2);
    flag = compare(Ue_minus_Se, U_minus_S, "U - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - S = " << std::endl << U_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Se, 2, 2);
    }

    const Matrix U_mult_S = *U * *S;
    int** Ue_mult_Se = multiplyMatrices(Ue, 2, 2, Se, 2, 2);
    flag = compare(Ue_mult_Se, U_mult_S, "U * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * S = " << std::endl << U_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Se, 2, 2);
    } 

    const Matrix U_plus_D = *U + *D;
    int** Ue_plus_De = addMatrices(Ue, De, 2, 2);
    flag = compare(Ue_plus_De, U_plus_D, "U + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + D = " << std::endl << U_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_De, 2, 2);
    }


    const Matrix U_minus_D = *U - *D;
    int** Ue_minus_De = subtractMatrices(Ue, De, 2, 2);
    flag = compare(Ue_minus_De, U_minus_D, "U - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - D = " << std::endl << U_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_De, 2, 2);
    }

    const Matrix U_mult_D = *U * *D;
    int** Ue_mult_De = multiplyMatrices(Ue, 2, 2, De, 2, 2);
    flag = compare(Ue_mult_De, U_mult_D, "U * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * D = " << std::endl << U_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_De, 2, 2);
    }

    const Matrix U_plus_L = *U + *L;
    int** Ue_plus_Le = addMatrices(Ue, Le, 2, 2);
    flag = compare(Ue_plus_Le, U_plus_L, "U + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + L = " << std::endl << U_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Le, 2, 2);
    }


    const Matrix U_minus_L = *U - *L;
    int** Ue_minus_Le = subtractMatrices(Ue, Le, 2, 2);
    flag = compare(Ue_minus_Le, U_minus_L, "U - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - L = " << std::endl << U_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Le, 2, 2);
    }

    const Matrix U_mult_L = *U * *L;
    int** Ue_mult_Le = multiplyMatrices(Ue, 2, 2, Le, 2, 2);
    flag = compare(Ue_mult_Le, U_mult_L, "U * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * L = " << std::endl << U_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Le, 2, 2);
    } 

    const Matrix U_plus_U = *U + *U;
    int** Ue_plus_Ue = addMatrices(Ue, Ue, 2, 2);
    flag = compare(Ue_plus_Ue, U_plus_U, "U + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + U = " << std::endl << U_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Ue, 2, 2);
    }


    const Matrix U_minus_U = *U - *U;
    int** Ue_minus_Ue = subtractMatrices(Ue, Ue, 2, 2);
    flag = compare(Ue_minus_Ue, U_minus_U, "U - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - U = " << std::endl << U_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Ue, 2, 2);
    }

    const Matrix U_mult_U = *U * *U;
    int** Ue_mult_Ue = multiplyMatrices(Ue, 2, 2, Ue, 2, 2);
    flag = compare(Ue_mult_Ue, U_mult_U, "U * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * U = " << std::endl << U_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Ue, 2, 2);
    } 
}
{
std::cout << "================== 5 x 5 MATRIX TEST ====================" << std::endl;
    int flag;

    int data[] = {17, -32, 4, 49, -7, -15, 23, 0, 38, -28, 12, -41, 5, 27, -3, 44, -19, 8, -46, 31, -12, 39, -1, 24, -34};
    int** Me = createMatrix(5, 5, data);
    int data1[] = {-22, 13, 47, -9, 6, -38, 29, -4, 32, -13, 45, 1, -27, 18, -33, 7, 50, -21, 14, -48, 9, -5, 42, -26, 11};
    int** Se = createMatrix(5, 5, data1);
    int data2[] = {27, 0, 0, 0, 0, 0, -14, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, -47, 0, 0, 0, 0, 0, 19};
    int** De = createMatrix(5, 5, data2);
    int data3[] = {-8, 0, 0, 0, 0, 34, -21, 0, 0, 0, 12, 47, -3, 0, 0, 25, -19, 6, -45, 0, 41, 10, -27, 18, 9};
    int** Le = createMatrix(5, 5, data3);
    int data4[] = {32, -11, 4, -39, 22, 0, -7, 48, -30, 13, 0, 0, -2, 28, -46, 0, 0, 0, 17, 5, 0, 0, 0, 0, -25};
    int** Ue = createMatrix(5, 5, data4);

    Matrix* M = new Matrix(5, 5);              // a 5x5 matrix
    Matrix* S = new SquareMatrix(5);           // a 5x5 square matrix
    Matrix* D = new DiagonalMatrix(5);         // a 5x5 diagonal matrix
    Matrix* L = new LowerTriangularMatrix(5);  // a 5x5 lower triangular matrix
    Matrix* U = new UpperTriangularMatrix(5);  // a 5x5 upper triangular matrix


    int index = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            M->setElement(r, c, data[index++]);
        }
    }

    index = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            S->setElement(r, c, data1[index++]);
        }
    }

    D->setElement(0, 0, 27);
    D->setElement(1, 1, -14);
    D->setElement(2, 2, 3);
    D->setElement(3, 3, -47);
    D->setElement(4, 4, 19);    

    L->setElement(0, 0, -8);

    L->setElement(1, 0, 34);
    L->setElement(1, 1, -21);

    L->setElement(2, 0, 12);
    L->setElement(2, 1, 47);
    L->setElement(2, 2, -3);

    L->setElement(3, 0, 25);
    L->setElement(3, 1, -19);
    L->setElement(3, 2, 6);
    L->setElement(3, 3, -45);

    L->setElement(4, 0, 41);
    L->setElement(4, 1, 10);
    L->setElement(4, 2, -27);
    L->setElement(4, 3, 18);
    L->setElement(4, 4, 9);

    // Row 0
    U->setElement(0, 0, 32);
    U->setElement(0, 1, -11);
    U->setElement(0, 2, 4);
    U->setElement(0, 3, -39);
    U->setElement(0, 4, 22);

    // Row 1
    U->setElement(1, 1, -7);
    U->setElement(1, 2, 48);
    U->setElement(1, 3, -30);
    U->setElement(1, 4, 13);

    // Row 2
    U->setElement(2, 2, -2);
    U->setElement(2, 3, 28);
    U->setElement(2, 4, -46);

    // Row 3
    U->setElement(3, 3, 17);
    U->setElement(3, 4, 5);

    // Row 4
    U->setElement(4, 4, -25);


    flag = compare(Me, *M, "Initalizing a Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M = " << std::endl << *M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me, 5, 5);
    }

    flag = compare(Se, *S, "Initalizing a Square Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S = " << std::endl << *S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se, 5, 5);
    }
    
    flag = compare(De, *D, "Initalizing a Diagonal Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D = " << std::endl << *D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De, 5, 5);
    }

    flag = compare(Le, *L, "Initalizing a Lower Matrix");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M = " << std::endl << *M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le, 5, 5);
    }
    
    flag = compare(Ue, *U, "Initalizing a Upper Matrix");
        if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U = " << std::endl << *U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue, 5, 5);
    }

    const Matrix M_plus_M = *M + *M;
    int** Me_plus_Me = addMatrices(Me, Me, 5, 5);
    flag = compare(Me_plus_Me, M_plus_M, "M + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + M = " << std::endl << M_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Me, 5, 5);
    }


    const Matrix M_minus_M = *M - *M;
    int** Me_minus_Me = subtractMatrices(Me, Me, 5, 5);
    flag = compare(Me_minus_Me, M_minus_M, "M - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - M = " << std::endl << M_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Me, 5, 5);
    }

    const Matrix M_mult_M = *M * *M;
    int** Me_mult_Me = multiplyMatrices(Me, 5, 5, Me, 5, 5);
    flag = compare(Me_mult_Me, M_mult_M, "M * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * M = " << std::endl << M_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Me, 5, 5);
    }
    
    const Matrix M_plus_S = *M + *S;
    int** Me_plus_Se = addMatrices(Me, Se, 5, 5);
    flag = compare(Me_plus_Se, M_plus_S, "M + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + S = " << std::endl << M_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Se, 5, 5);
    }


    const Matrix M_minus_S = *M - *S;
    int** Me_minus_Se = subtractMatrices(Me, Se, 5, 5);
    flag = compare(Me_minus_Se, M_minus_S, "M - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - S = " << std::endl << M_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Se, 5, 5);
    }

    const Matrix M_mult_S = *M * *S;
    int** Me_mult_Se = multiplyMatrices(Me, 5, 5, Se, 5, 5);
    flag = compare(Me_mult_Se, M_mult_S, "M * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * S = " << std::endl << M_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Se, 5, 5);
    }

    const Matrix M_plus_D = *M + *D;
    int** Me_plus_De = addMatrices(Me, De, 5, 5);
    flag = compare(Me_plus_De, M_plus_D, "M + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + D = " << std::endl << M_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_De, 5, 5);
    }


    const Matrix M_minus_D = *M - *D;
    int** Me_minus_De = subtractMatrices(Me, De, 5, 5);
    flag = compare(Me_minus_De, M_minus_D, "M - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - D = " << std::endl << M_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_De, 5, 5);
    }

    const Matrix M_mult_D = *M * *D;
    int** Me_mult_De = multiplyMatrices(Me, 5, 5, De, 5, 5);
    flag = compare(Me_mult_De, M_mult_D, "M * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * D = " << std::endl << M_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_De, 5, 5);
    }
    
    const Matrix M_plus_L = *M + *L;
    int** Me_plus_Le = addMatrices(Me, Le, 5, 5);
    flag = compare(Me_plus_Le, M_plus_L, "M + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + L = " << std::endl << M_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Le, 5, 5);
    }


    const Matrix M_minus_L = *M - *L;
    int** Me_minus_Le = subtractMatrices(Me, Le, 5, 5);
    flag = compare(Me_minus_Le, M_minus_L, "M - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - L = " << std::endl << M_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Le, 5, 5);
    }

    const Matrix M_mult_L = *M * *L;
    int** Me_mult_Le = multiplyMatrices(Me, 5, 5, Le, 5, 5);
    flag = compare(Me_mult_Le, M_mult_L, "M * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * L = " << std::endl << M_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Le, 5, 5);
    }

    const Matrix M_plus_U = *M + *U;
    int** Me_plus_Ue = addMatrices(Me, Ue, 5, 5);
    flag = compare(Me_plus_Ue, M_plus_U, "M + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + U = " << std::endl << M_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Ue, 5, 5);
    }


    const Matrix M_minus_U = *M - *U;
    int** Me_minus_Ue = subtractMatrices(Me, Ue, 5, 5);
    flag = compare(Me_minus_Ue, M_minus_U, "M - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - U = " << std::endl << M_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Ue, 5, 5);
    }

    const Matrix M_mult_U = *M * *U;
    int** Me_mult_Ue = multiplyMatrices(Me, 5, 5, Ue, 5, 5);
    flag = compare(Me_mult_Ue, M_mult_U, "M * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * U = " << std::endl << M_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Ue, 5, 5);
    }

    const Matrix S_plus_M = *S + *M;
    int** Se_plus_Me = addMatrices(Se, Me, 5, 5);
    flag = compare(Se_plus_Me, S_plus_M, "S + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + M = " << std::endl << S_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Me, 5, 5);
    }


    const Matrix S_minus_M = *S - *M;
    int** Se_minus_Me = subtractMatrices(Se, Me, 5, 5);
    flag = compare(Se_minus_Me, S_minus_M, "S - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - M = " << std::endl << S_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Me, 5, 5);
    }

    const Matrix S_mult_M = *S * *M;
    int** Se_mult_Me = multiplyMatrices(Se, 5, 5, Me, 5, 5);
    flag = compare(Se_mult_Me, S_mult_M, "S * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * M = " << std::endl << S_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Me, 5, 5);
    }


    const Matrix S_plus_S = *S + *S;
    int** Se_plus_Se = addMatrices(Se, Se, 5, 5);
    flag = compare(Se_plus_Se, S_plus_S, "S + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + S = " << std::endl << S_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Se, 5, 5);
    }


    const Matrix S_minus_S = *S - *S;
    int** Se_minus_Se = subtractMatrices(Se, Se, 5, 5);
    flag = compare(Se_minus_Se, S_minus_S, "S - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - S = " << std::endl << S_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Se, 5, 5);
    }

    const Matrix S_mult_S = *S * *S;
    int** Se_mult_Se = multiplyMatrices(Se, 5, 5, Se, 5, 5);
    flag = compare(Se_mult_Se, S_mult_S, "S * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * S = " << std::endl << S_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Se, 5, 5);
    }

    const Matrix S_plus_D = *S + *D;
    int** Se_plus_De = addMatrices(Se, De, 5, 5);
    flag = compare(Se_plus_De, S_plus_D, "S + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + D = " << std::endl << S_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_De, 5, 5);
    }


    const Matrix S_minus_D = *S - *D;
    int** Se_minus_De = subtractMatrices(Se, De, 5, 5);
    flag = compare(Se_minus_De, S_minus_D, "S - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - D = " << std::endl << S_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_De, 5, 5);
    }

    const Matrix S_mult_D = *S * *D;
    int** Se_mult_De = multiplyMatrices(Se, 5, 5, De, 5, 5);
    flag = compare(Se_mult_De, S_mult_D, "S * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * D = " << std::endl << S_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_De, 5, 5);
    }   

    const Matrix S_plus_L = *S + *L;
    int** Se_plus_Le = addMatrices(Se, Le, 5, 5);
    flag = compare(Se_plus_Le, S_plus_L, "S + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + L = " << std::endl << S_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Le, 5, 5);
    }


    const Matrix S_minus_L = *S - *L;
    int** Se_minus_Le = subtractMatrices(Se, Le, 5, 5);
    flag = compare(Se_minus_Le, S_minus_L, "S - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - L = " << std::endl << S_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Le, 5, 5);
    }

    const Matrix S_mult_L = *S * *L;
    int** Se_mult_Le = multiplyMatrices(Se, 5, 5, Le, 5, 5);
    flag = compare(Se_mult_Le, S_mult_L, "S * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * L = " << std::endl << S_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Le, 5, 5);
    }  

    const Matrix S_plus_U = *S + *U;
    int** Se_plus_Ue = addMatrices(Se, Ue, 5, 5);
    flag = compare(Se_plus_Ue, S_plus_U, "S + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S + U = " << std::endl << S_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_plus_Ue, 5, 5);
    }


    const Matrix S_minus_U = *S - *U;
    int** Se_minus_Ue = subtractMatrices(Se, Ue, 5, 5);
    flag = compare(Se_minus_Ue, S_minus_U, "S - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S - U = " << std::endl << S_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_minus_Ue, 5, 5);
    }

    const Matrix S_mult_U = *S * *U;
    int** Se_mult_Ue = multiplyMatrices(Se, 5, 5, Ue, 5, 5);
    flag = compare(Se_mult_Ue, S_mult_U, "S * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "S * U = " << std::endl << S_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Se_mult_Ue, 5, 5);
    }  

    const Matrix D_plus_M = *D + *M;
    int** De_plus_Me = addMatrices(De, Me, 5, 5);
    flag = compare(De_plus_Me, D_plus_M, "D + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + M = " << std::endl << D_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Me, 5, 5);
    }


    const Matrix D_minus_M = *D - *M;
    int** De_minus_Me = subtractMatrices(De, Me, 5, 5);
    flag = compare(De_minus_Me, D_minus_M, "D - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - M = " << std::endl << D_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Me, 5, 5);
    }

    const Matrix D_mult_M = *D * *M;
    int** De_mult_Me = multiplyMatrices(De, 5, 5, Me, 5, 5);
    flag = compare(De_mult_Me, D_mult_M, "D * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * M = " << std::endl << D_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Me, 5, 5);
    }  

    const Matrix D_plus_S = *D + *S;
    int** De_plus_Se = addMatrices(De, Se, 5, 5);
    flag = compare(De_plus_Se, D_plus_S, "D + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + S = " << std::endl << D_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Se, 5, 5);
    }


    const Matrix D_minus_S = *D - *S;
    int** De_minus_Se = subtractMatrices(De, Se, 5, 5);
    flag = compare(De_minus_Se, D_minus_S, "D - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - S = " << std::endl << D_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Se, 5, 5);
    }

    const Matrix D_mult_S = *D * *S;
    int** De_mult_Se = multiplyMatrices(De, 5, 5, Se, 5, 5);
    flag = compare(De_mult_Se, D_mult_S, "D * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * S = " << std::endl << D_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Se, 5, 5);
    }  

    const Matrix D_plus_D = *D + *D;
    int** De_plus_De = addMatrices(De, De, 5, 5);
    flag = compare(De_plus_De, D_plus_D, "D + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + D = " << std::endl << D_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_De, 5, 5);
    }


    const Matrix D_minus_D = *D - *D;
    int** De_minus_De = subtractMatrices(De, De, 5, 5);
    flag = compare(De_minus_De, D_minus_D, "D - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - D = " << std::endl << D_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_De, 5, 5);
    }

    const Matrix D_mult_D = *D * *D;
    int** De_mult_De = multiplyMatrices(De, 5, 5, De, 5, 5);
    flag = compare(De_mult_De, D_mult_D, "D * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * D = " << std::endl << D_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_De, 5, 5);
    }  

    const Matrix D_plus_L = *D + *L;
    int** De_plus_Le = addMatrices(De, Le, 5, 5);
    flag = compare(De_plus_Le, D_plus_L, "D + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + L = " << std::endl << D_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Le, 5, 5);
    }


    const Matrix D_minus_L = *D - *L;
    int** De_minus_Le = subtractMatrices(De, Le, 5, 5);
    flag = compare(De_minus_Le, D_minus_L, "D - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - L = " << std::endl << D_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Le, 5, 5);
    }

    const Matrix D_mult_L = *D * *L;
    int** De_mult_Le = multiplyMatrices(De, 5, 5, Le, 5, 5);
    flag = compare(De_mult_Le, D_mult_L, "D * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * L = " << std::endl << D_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Le, 5, 5);
    }  

    const Matrix D_plus_U = *D + *U;
    int** De_plus_Ue = addMatrices(De, Ue, 5, 5);
    flag = compare(De_plus_Ue, D_plus_U, "D + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D + U = " << std::endl << D_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_plus_Ue, 5, 5);
    }


    const Matrix D_minus_U = *D - *U;
    int** De_minus_Ue = subtractMatrices(De, Ue, 5, 5);
    flag = compare(De_minus_Ue, D_minus_U, "D - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D - U = " << std::endl << D_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_minus_Ue, 5, 5);
    }

    const Matrix D_mult_U = *D * *U;
    int** De_mult_Ue = multiplyMatrices(De, 5, 5, Ue, 5, 5);
    flag = compare(De_mult_Ue, D_mult_U, "D * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "D * U = " << std::endl << D_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(De_mult_Ue, 5, 5);
    }  

    const Matrix L_plus_M = *L + *M;
    int** Le_plus_Me = addMatrices(Le, Me, 5, 5);
    flag = compare(Le_plus_Me, L_plus_M, "L + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + M = " << std::endl << L_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Me, 5, 5);
    }


    const Matrix L_minus_M = *L - *M;
    int** Le_minus_Me = subtractMatrices(Le, Me, 5, 5);
    flag = compare(Le_minus_Me, L_minus_M, "L - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - M = " << std::endl << L_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Me, 5, 5);
    }

    const Matrix L_mult_M = *L * *M;
    int** Le_mult_Me = multiplyMatrices(Le, 5, 5, Me, 5, 5);
    flag = compare(Le_mult_Me, L_mult_M, "L * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * M = " << std::endl << L_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Me, 5, 5);
    } 

    const Matrix L_plus_S = *L + *S;
    int** Le_plus_Se = addMatrices(Le, Se, 5, 5);
    flag = compare(Le_plus_Se, L_plus_S, "L + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + S = " << std::endl << L_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Se, 5, 5);
    }


    const Matrix L_minus_S = *L - *S;
    int** Le_minus_Se = subtractMatrices(Le, Se, 5, 5);
    flag = compare(Le_minus_Se, L_minus_S, "L - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - S = " << std::endl << L_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Se, 5, 5);
    }

    const Matrix L_mult_S = *L * *S;
    int** Le_mult_Se = multiplyMatrices(Le, 5, 5, Se, 5, 5);
    flag = compare(Le_mult_Se, L_mult_S, "L * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * S = " << std::endl << L_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Se, 5, 5);
    } 

    const Matrix L_plus_D = *L + *D;
    int** Le_plus_De = addMatrices(Le, De, 5, 5);
    flag = compare(Le_plus_De, L_plus_D, "L + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + D = " << std::endl << L_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_De, 5, 5);
    }


    const Matrix L_minus_D = *L - *D;
    int** Le_minus_De = subtractMatrices(Le, De, 5, 5);
    flag = compare(Le_minus_De, L_minus_D, "L - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - D = " << std::endl << L_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_De, 5, 5);
    }

    const Matrix L_mult_D = *L * *D;
    int** Le_mult_De = multiplyMatrices(Le, 5, 5, De, 5, 5);
    flag = compare(Le_mult_De, L_mult_D, "L * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * D = " << std::endl << L_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_De, 5, 5);
    } 

    const Matrix L_plus_L = *L + *L;
    int** Le_plus_Le = addMatrices(Le, Le, 5, 5);
    flag = compare(Le_plus_Le, L_plus_L, "L + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + L = " << std::endl << L_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Le, 5, 5);
    }


    const Matrix L_minus_L = *L - *L;
    int** Le_minus_Le = subtractMatrices(Le, Le, 5, 5);
    flag = compare(Le_minus_Le, L_minus_L, "L - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - L = " << std::endl << L_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Le, 5, 5);
    }

    const Matrix L_mult_L = *L * *L;
    int** Le_mult_Le = multiplyMatrices(Le, 5, 5, Le, 5, 5);
    flag = compare(Le_mult_Le, L_mult_L, "L * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * L = " << std::endl << L_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Le, 5, 5);
    } 

    const Matrix L_plus_U = *L + *U;
    int** Le_plus_Ue = addMatrices(Le, Ue, 5, 5);
    flag = compare(Le_plus_Ue, L_plus_U, "L + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L + U = " << std::endl << L_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_plus_Ue, 5, 5);
    }


    const Matrix L_minus_U = *L - *U;
    int** Le_minus_Ue = subtractMatrices(Le, Ue, 5, 5);
    flag = compare(Le_minus_Ue, L_minus_U, "L - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L - U = " << std::endl << L_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_minus_Ue, 5, 5);
    }

    const Matrix L_mult_U = *L * *U;
    int** Le_mult_Ue = multiplyMatrices(Le, 5, 5, Ue, 5, 5);
    flag = compare(Le_mult_Ue, L_mult_U, "L * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "L * U = " << std::endl << L_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Le_mult_Ue, 5, 5);
    } 

    const Matrix U_plus_M = *U + *M;
    int** Ue_plus_Me = addMatrices(Ue, Me, 5, 5);
    flag = compare(Ue_plus_Me, U_plus_M, "U + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + M = " << std::endl << U_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Me, 5, 5);
    }


    const Matrix U_minus_M = *U - *M;
    int** Ue_minus_Me = subtractMatrices(Ue, Me, 5, 5);
    flag = compare(Ue_minus_Me, U_minus_M, "U - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - M = " << std::endl << U_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Me, 5, 5);
    }

    const Matrix U_mult_M = *U * *M;
    int** Ue_mult_Me = multiplyMatrices(Ue, 5, 5, Me, 5, 5);
    flag = compare(Ue_mult_Me, U_mult_M, "U * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * M = " << std::endl << U_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Me, 5, 5);
    } 

    const Matrix U_plus_S = *U + *S;
    int** Ue_plus_Se = addMatrices(Ue, Se, 5, 5);
    flag = compare(Ue_plus_Se, U_plus_S, "U + S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + S = " << std::endl << U_plus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Se, 5, 5);
    }


    const Matrix U_minus_S = *U - *S;
    int** Ue_minus_Se = subtractMatrices(Ue, Se, 5, 5);
    flag = compare(Ue_minus_Se, U_minus_S, "U - S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - S = " << std::endl << U_minus_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Se, 5, 5);
    }

    const Matrix U_mult_S = *U * *S;
    int** Ue_mult_Se = multiplyMatrices(Ue, 5, 5, Se, 5, 5);
    flag = compare(Ue_mult_Se, U_mult_S, "U * S");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * S = " << std::endl << U_mult_S << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Se, 5, 5);
    } 

    const Matrix U_plus_D = *U + *D;
    int** Ue_plus_De = addMatrices(Ue, De, 5, 5);
    flag = compare(Ue_plus_De, U_plus_D, "U + D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + D = " << std::endl << U_plus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_De, 5, 5);
    }


    const Matrix U_minus_D = *U - *D;
    int** Ue_minus_De = subtractMatrices(Ue, De, 5, 5);
    flag = compare(Ue_minus_De, U_minus_D, "U - D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - D = " << std::endl << U_minus_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_De, 5, 5);
    }

    const Matrix U_mult_D = *U * *D;
    int** Ue_mult_De = multiplyMatrices(Ue, 5, 5, De, 5, 5);
    flag = compare(Ue_mult_De, U_mult_D, "U * D");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * D = " << std::endl << U_mult_D << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_De, 5, 5);
    }

    const Matrix U_plus_L = *U + *L;
    int** Ue_plus_Le = addMatrices(Ue, Le, 5, 5);
    flag = compare(Ue_plus_Le, U_plus_L, "U + L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + L = " << std::endl << U_plus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Le, 5, 5);
    }


    const Matrix U_minus_L = *U - *L;
    int** Ue_minus_Le = subtractMatrices(Ue, Le, 5, 5);
    flag = compare(Ue_minus_Le, U_minus_L, "U - L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - L = " << std::endl << U_minus_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Le, 5, 5);
    }

    const Matrix U_mult_L = *U * *L;
    int** Ue_mult_Le = multiplyMatrices(Ue, 5, 5, Le, 5, 5);
    flag = compare(Ue_mult_Le, U_mult_L, "U * L");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * L = " << std::endl << U_mult_L << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Le, 5, 5);
    } 

    const Matrix U_plus_U = *U + *U;
    int** Ue_plus_Ue = addMatrices(Ue, Ue, 5, 5);
    flag = compare(Ue_plus_Ue, U_plus_U, "U + U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U + U = " << std::endl << U_plus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_plus_Ue, 5, 5);
    }


    const Matrix U_minus_U = *U - *U;
    int** Ue_minus_Ue = subtractMatrices(Ue, Ue, 5, 5);
    flag = compare(Ue_minus_Ue, U_minus_U, "U - U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U - U = " << std::endl << U_minus_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_minus_Ue, 5, 5);
    }

    const Matrix U_mult_U = *U * *U;
    int** Ue_mult_Ue = multiplyMatrices(Ue, 5, 5, Ue, 5, 5);
    flag = compare(Ue_mult_Ue, U_mult_U, "U * U");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "U * U = " << std::endl << U_mult_U << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Ue_mult_Ue, 5, 5);
    } 
}
{
std::cout << "================== VARIABLE SIZE TEST ==================" << std::endl;  
    int data[] = {-12, 37, 0, -44, 19, 8};
    int** Me_1 = createMatrix(2, 3, data);

    int data1[] = {23, -6, 41, -32, 7, 0, -18, 29, -11, 14, -47, 36, 5, -3, 48};
    int** Me_2 = createMatrix(3, 5, data1);

    int data2[] = {32, -7, -9, 10, 5, 48};
    int** Me_3 = createMatrix(2, 3, data2);

    Matrix* M_1 = new Matrix(2, 3);
    Matrix* M_2 = new Matrix(3, 5);
    Matrix* M_3 = new Matrix(2, 3);

    int index = 0;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            M_1->setElement(r, c, data[index++]);
        }
    }

    index = 0;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 5; c++) {
            M_2->setElement(r, c, data1[index++]);
        }
    }

    index = 0;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            M_3->setElement(r, c, data2[index++]);
        }
    }

    int flag;
    const Matrix M_plus_M = *M_1 + *M_3;
    int** Me_plus_Me = addMatrices(Me_1, Me_3, 2, 3);
    flag = compare(Me_plus_Me, M_plus_M, "M + M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M + M = " << std::endl << M_plus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_plus_Me, 2, 3);
    }


    const Matrix M_minus_M = *M_1 - *M_3;
    int** Me_minus_Me = subtractMatrices(Me_1, Me_3, 2, 3);
    flag = compare(Me_minus_Me, M_minus_M, "M - M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M - M = " << std::endl << M_minus_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_minus_Me, 5, 5);
    }

    const Matrix M_mult_M = *M_1 * *M_2;
    int** Me_mult_Me = multiplyMatrices(Me_1, 2, 3, Me_2, 3, 5);
    flag = compare(Me_mult_Me, M_mult_M, "M * M");
    if (flag == 0){
        std::cout << "Got: " << std::endl;
        std::cout << "M * M = " << std::endl << M_mult_M << std::endl;
        std::cout << "Expected: " << std::endl;
        printMatrix(Me_mult_Me, 5, 5);
    }
}
{
std::cout << "================== COMPARISION TESTS ===================" << std::endl;
    Matrix* M = new Matrix(2, 2);              // a 2x2 matrix
    Matrix* S = new SquareMatrix(2);           // a 2x2 square matrix
    Matrix* D = new DiagonalMatrix(2);         // a 2x2 diagonal matrix
    Matrix* L = new LowerTriangularMatrix(2);  // a 2x2 lower triangular matrix
    Matrix* U = new UpperTriangularMatrix(2);  // a 2x2 upper triangular matrix

    Matrix* M_Same = new Matrix(2, 2);              // a 2x2 matrix
    Matrix* S_Same = new SquareMatrix(2);           // a 2x2 square matrix
    Matrix* D_Same = new DiagonalMatrix(2);         // a 2x2 diagonal matrix
    Matrix* L_Same = new LowerTriangularMatrix(2);  // a 2x2 lower triangular matrix
    Matrix* U_Same = new UpperTriangularMatrix(2);  // a 2x2 upper triangular matrix

    Matrix* M_Diff = new Matrix(2, 2);              // a 2x2 matrix
    Matrix* S_Diff = new SquareMatrix(2);           // a 2x2 square matrix
    Matrix* D_Diff = new DiagonalMatrix(2);         // a 2x2 diagonal matrix
    Matrix* L_Diff = new LowerTriangularMatrix(2);  // a 2x2 lower triangular matrix
    Matrix* U_Diff = new UpperTriangularMatrix(2);  // a 2x2 upper triangular matrix

    M->setElement(0, 0, 42);
    M->setElement(0, 1, -82);
    M->setElement(1, 0, 19);
    M->setElement(1, 1, -6);

    S->setElement(0, 0, -34);
    S->setElement(0, 1, 72);
    S->setElement(1, 0, 5);
    S->setElement(1, 1, -91);

    D->setElement(0, 0, 88);
    D->setElement(1, 1, -57);

    L->setElement(0, 0, -42);
    L->setElement(1, 0, 67);
    L->setElement(1, 1, 9);

    U->setElement(0, 0, 54);
    U->setElement(0, 1, -23);
    U->setElement(1, 1, 81);

    M_Same->setElement(0, 0, 42);
    M_Same->setElement(0, 1, -82);
    M_Same->setElement(1, 0, 19);
    M_Same->setElement(1, 1, -6);

    S_Same->setElement(0, 0, -34);
    S_Same->setElement(0, 1, 72);
    S_Same->setElement(1, 0, 5);
    S_Same->setElement(1, 1, -91);

    D_Same->setElement(0, 0, 88);
    D_Same->setElement(1, 1, -57);

    L_Same->setElement(0, 0, -42);
    L_Same->setElement(1, 0, 67);
    L_Same->setElement(1, 1, 9);

    U_Same->setElement(0, 0, 54);
    U_Same->setElement(0, 1, -23);
    U_Same->setElement(1, 1, 81);

    M_Diff->setElement(0, 0, 12);
    M_Diff->setElement(0, 1, -34);
    M_Diff->setElement(1, 0, 20);
    M_Diff->setElement(1, 1, -5);

    S_Diff->setElement(0, 0, -50);
    S_Diff->setElement(0, 1, 12);
    S_Diff->setElement(1, 0, 52);
    S_Diff->setElement(1, 1, -12);

    D_Diff->setElement(0, 0, 12);
    D_Diff->setElement(1, 1, -10);

    L_Diff->setElement(0, 0, -40);
    L_Diff->setElement(1, 0, 19);
    L_Diff->setElement(1, 1, 29);

    U_Diff->setElement(0, 0, 84);
    U_Diff->setElement(0, 1, -20);
    U_Diff->setElement(1, 1, 23);

    if (M == M){
        std::cout << "M == M ✅ " << std::endl;  
    }
    else{
        std::cout << "M == M ❌ " << std::endl;
    }

    if (S == S){
        std::cout << "S == S ✅ " << std::endl;  
    }
    else{
        std::cout << "S == S ❌ " << std::endl;
    }


    if (D == D){
        std::cout << "D == D ✅ " << std::endl;  
    }
    else{
        std::cout << "D == D ❌ " << std::endl;
    }


    if (L == L){
        std::cout << "L == L ✅ " << std::endl;  
    }
    else{
        std::cout << "L == L ❌ " << std::endl;
    }


    if (U == U){
        std::cout << "U == U ✅ " << std::endl;  
    }
    else{
        std::cout << "U == U ❌ " << std::endl;
    }

    if (M == M_Same){
        std::cout << "M == M_Same ✅ " << std::endl;  
    }
    else{
        std::cout << "M == M_Same ❌ " << std::endl;
    }

    if (S == S_Same){
        std::cout << "S == S_Same ✅ " << std::endl;  
    }
    else{
        std::cout << "S == S_Same ❌ " << std::endl;
    }


    if (D == D_Same){
        std::cout << "D == D_Same ✅ " << std::endl;  
    }
    else{
        std::cout << "D == D_Same ❌ " << std::endl;
    }


    if (L == L_Same){
        std::cout << "L == L_Same ✅ " << std::endl;  
    }
    else{
        std::cout << "L == L_Same ❌ " << std::endl;
    }


    if (U == U_Same){
        std::cout << "U == U_Same ✅ " << std::endl;  
    }
    else{
        std::cout << "U == U_Same ❌ " << std::endl;
    }


    if (M == M_Diff){
        std::cout << "M == M_Diff ❌ " << std::endl;  
    }
    else{
        std::cout << "M == M_Diff ✅ " << std::endl;
    }

    if (S == S_Diff){
        std::cout << "S == S_Diff ❌ " << std::endl;  
    }
    else{
        std::cout << "S == S_Diff ✅ " << std::endl;
    }

    if (D == D_Diff){
        std::cout << "D == D_Diff ❌ " << std::endl;  
    }
    else{
        std::cout << "D == D_Diff ✅ " << std::endl;
    }

    if (L == L_Diff){
        std::cout << "L == L_Diff ❌ " << std::endl;  
    }
    else{
        std::cout << "L == L_Diff ✅ " << std::endl;
    }

    if (U == U_Diff){
        std::cout << "U == U_Diff ❌ " << std::endl;  
    }
    else{
        std::cout << "U == U_Diff ✅ " << std::endl;
    }

}
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Matrix& M) {
    const char open_bracket  = '|';
    const char close_bracket = '|';

    for (int i = 0; i < M.getRows(); ++i) {
        os << open_bracket << ' ';
        for (int j = 0; j < M.getCols(); ++j) {
            os.width(4);
            os << M.getElement(i, j) << " ";
        }
        os << close_bracket;
        os << std::endl;
    }

    return os;
}
