#include <iostream>

using namespace std;

class Square {
    private:
        float side;
    public:
        Square(float x) : side(x)
        {}
        ~Square() {
            cout << "Calling the destructor for Square with side" << side << endl;
        }
        Square(Square& s) {
            side = s.side;
            cout << "Copy constructor invoked" << endl;
        }
        
        Square& operator=(const Square& other) {
            int s = other.side;
            cout << "Inside the copy assignment operator" << endl;
            (*this).side = other.side;
            //OR
            //this->side = side;
            return *this;
        }

        float get_area() {
            return side*side;
        }
        float get_perimeter() {
            return 4*side;
        }
        void print() {
            cout << "Square: side " << side << " units, perimeter " << get_perimeter() << ", area " << get_area() << endl;
        }
        
        //Overload addition operator
        Square operator+(Square s2) {
            /*
            float new_side = side + s2.side;
            Square s3(new_side);
            return s3;
            */
            return Square(side + s2.side);
        }

        friend ostream& operator<<(ostream& out, Square s);
};

ostream& operator<<(ostream& out, Square s) {
    out << "Square: side " << s.side << " units, perimeter " << s.get_perimeter() << ", area " << s.get_area() << endl;
    return out;
}
    
int main() {
    Square s5(5);
    //Square s6(s5);
    Square s6 = s5;
    s5 = s6;
    s5.print();
    s6.print();

    /*
    Square s1(5.5f), s2(4);
    s1.print();
    s2.print();
    Square s3 = s1 + s2;
    s3.print();
    Square s4 = s1 + s3;
    cout << s4 << endl;
    */
    return 0;
}