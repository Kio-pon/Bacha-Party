#include <iostream>
using namespace std;
class Box {
private:
    double length, width;
public:
    // Constructor
    Box(double l, double w) : length(l), width(w) {}
    // Friend function declaration
    friend class Drawer;
};

// Friend function definition
class Drawer {
    public:
        void draw(Box b) {
        // Access private members directly
        for(int i = 0; i < b.width; i++)
            cout << "*";
        cout << endl;

        for(int i = 0; i < b.length - 2; i++) {
            for(int j = 0; j < b.width; j++) {
                if(j == 0 || j == b.width - 1) 
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < b.width; i++)
            cout << "*";
        cout << endl;
        }
};

int main() {
    Box myBox(10, 8);
    Drawer d;
    d.draw(myBox);
    return 0;
}
