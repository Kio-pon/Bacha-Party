#include <iostream>
#include <limits>

using namespace std;

int main(){
    int x;
    cout << "X: "; cin >> x;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int y;
    cout << "Y: "; cin >> y;
}