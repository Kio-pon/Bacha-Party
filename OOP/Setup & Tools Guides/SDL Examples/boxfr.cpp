#include <iostream>
using namespace std;
class Box {
private:
    double length, width, height;
public:
    // Constructor
    Box(double l, double w, double h) : length(l), width(w), height(h) {}
    // Friend function declaration
    friend class Utility;
};

// Friend function definition
class Utility {
    public:
        double calculateVolume(Box b) {
        // Access private members directly
        return b.length * b.width * b.height;
    }
};

int main() {
    Box myBox(3.0, 4.0, 5.0);
    Utility u;
    cout << "Volume of the box: " << u.calculateVolume(myBox) << endl;
    return 0;
}
