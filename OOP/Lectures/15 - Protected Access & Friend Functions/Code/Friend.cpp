#include <iostream>
using namespace std;

class INT{
    private:
        int data;
    public:
        INT() : data(0) {}
        INT(int x) : data(x) {}

        friend ostream& operator<<(ostream& out, const INT& s);
        friend istream& operator>>(istream& in, INT& s);

        // Pre-increment: ++x
        INT& operator++() {
            ++data;          // increment first
            return *this;    // return updated object by reference
        }

        // Post-increment: x++
        INT operator++(int) {
            INT temp = *this;    // save current state
            ++data;              // increment
            return temp;         // return old state
        }

        INT operator+(const INT& other){
            return INT(this->data + other.data);
        }
};

ostream& operator<<(ostream& out, const INT& s) {
    out << s.data;
    return out;
}

istream& operator>>(istream& in, INT& s) {
    in >> s.data;  // Reads a single word
    // getline(in, s.data); // Reads an entire line
    return in;
}

int main(){
    INT A;
    INT B(1);
    INT C(2);
    INT D(3);

    cout << A << B << endl;
    operator<<(cout, C);
    cout << endl;
    cout << ++A << endl; // pre increment
    cout << B++ << endl; // post increment - returns old value

    operator<<(operator<<(cout, C.operator++()), "\n");
    cout << ++(++D) << endl;
    (D.operator++()).operator++();
    cout << D + C << endl;
    cout << D.operator+(C) << endl;
    cout << (D++)++ << endl;
    cout << D << endl;

}