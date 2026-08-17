#include <iostream>

class Rect {
private:

    float length, height;

public:

    Rect() = default;                      // Default constructor
    Rect(float l, float h);                // Parameterized constructor
    Rect  operator+(const Rect& r) const;  // Overload + operator
    float area() const;                    // Calculate area
    void  show() const;                    // Display length and height
};

Rect::Rect(float l, float h) : length(l), height(h) {}

Rect Rect::operator+(const Rect& r) const {
    Rect tmp;
    tmp.length = length + r.length;
    tmp.height = height + r.height;
    return tmp;
}

float Rect::area() const { return length * height; }

void Rect::show() const {
    std::cout << "L:" << length << " H:" << height << std::endl;
}

int main() {
    Rect r1(10.0f, 20.0f), r2(30.0f, 40.0f), r3;
    r3 = r1 + r2;  // Equivalent to r3 = r1.operator+(r2);
    r3.show();

    return 0;
}