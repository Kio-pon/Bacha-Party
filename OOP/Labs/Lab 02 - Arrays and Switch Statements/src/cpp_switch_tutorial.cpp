#include <iostream>
using namespace std;

int main() {
    char grade;
    cout << "Enter your grade (A, B, C, D, F): ";
    cin >> grade;
    

    switch(grade) {
        case 'A':
            cout << "Excellent!" << endl;
            break;
        case 'B':
            cout << "Good job!" << endl;
            break;
        case 'C':
            cout << "Fair performance." << endl;
            break;
        case 'D':
            cout << "Needs improvement." << endl;
            break;
        case 'F':
            cout << "Failed." << endl;
            break;
        default:
            cout << "Invalid grade." << endl;
    }

    return 0;
}

