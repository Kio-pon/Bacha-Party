#include <iostream>
#include <string>
using namespace std;

// ----- Base Class -----
class Shape {
protected:
    string name;
public:
    Shape(string n) {
        name = n;
        cout << "Creating shape: " << name << endl;
    }
};

// ----- Rectangle Class -----
class Rectangle : public Shape {
protected:
    int length;
    int width;
public:
    Rectangle(string n, int l, int w) : Shape(n) {
        length = l;
        width = w;
        cout << "Creating rectangle" << endl;
    }
};

// ----- Square Class -----
class Square : public Rectangle {
public:
    Square(string n, int side) : Rectangle(n, side, side) {
        cout << "Creating square" << endl;
    }

    // Can use Rectangle’s getArea() directly,
    // but we can redefine it for clarity
};

// ----- Main Function -----










