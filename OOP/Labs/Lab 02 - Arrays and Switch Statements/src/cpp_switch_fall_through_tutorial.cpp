#include <iostream>
using namespace std;

int main() {
    int option;
    cout << "Enter an option (1-3): ";
    cin >> option;

    switch(option) {
        case 1:
        case 2:
            cout << "Option 1 or 2 selected." << endl;
            break;
        case 3:
            cout << "Option 3 selected." << endl;
            break;
        default:
            cout << "Invalid option." << endl;
    }

    return 0;
}
