#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
    string name;

public:
    Shape(string n) : name(n) {
        cout << "Now creating shape with name: " << name << endl;
    }
};

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(string n, int l, int w) : length(l), Shape(n), width(w) {
        cout << "Now creating rectangle with length " << length << " and width " << width << endl;
    }

};

class Square : public Rectangle {
public:
    Square(string n, int side) : Rectangle(n, side, side) {
        cout << "Now creating square with side " << side << endl;
    }
};

int main() {
    Square square("MySquare", 5);
    return 0;
}
