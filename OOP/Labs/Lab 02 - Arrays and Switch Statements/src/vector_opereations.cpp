#include <iostream>
using namespace std;

// Exercise 2.3: Vector operations [25 Points]
// Implement addition, subtraction and comparison of two integer vectors.

void print_vector(int vector[], int size)
{
    // TODO: print the elements of the vector separated by a space
}

void input_vector(int vector[], int size)
{
    // TODO: read `size` integers into the vector
}

void add_vectors(int vector1[], int vector2[], int result[], int size)
{
    // TODO: element-wise addition into result
}

void subtract_vectors(int vector1[], int vector2[], int result[], int size)
{
    // TODO: element-wise subtraction into result
}

// Function to compare two vectors and return true if they are equal
bool compare_vectors(int vector1[], int vector2[], int size)
{
    // TODO: return true if all elements match, false otherwise
    return false;
}

int main()
{
    int n;
    char operation;

    cin >> n;

    int vector1[n];
    int vector2[n];
    int result[n];

    input_vector(vector1, n);

    input_vector(vector2, n);

    cin >> operation;

    switch (operation)
    {
    case '+':
        add_vectors(vector1, vector2, result, n);
        print_vector(result, n);
        break;
    case '-':
        subtract_vectors(vector1, vector2, result, n);
        print_vector(result, n);
        break;
    case '=':
        if (compare_vectors(vector1, vector2, n))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
        break;
    default:
        cout << "Invalid operation" << endl;
        break;
    }

    return 0;
}
