#include <iostream>

class Distance {
    private:
        int feet;
        double inches;
    public:
        Distance(int f = 0, double i = 0.0) : feet(f), inches(i) {}
        bool operator==(const Distance &other) const {
            return (this->feet == other.feet) && (this->inches == other.inches);
        }

        bool operator==(int value) const {
            return this->feet == value;
        }

        bool operator!=(const Distance &other) const {
            return !(*this == other);
        }
        friend std::ostream& operator <<(std::ostream &out, const Distance &other);
        friend std::istream& operator >>(std::istream &in, Distance &other);
    };

std::ostream& operator <<(std::ostream &out, const Distance &other) {
    out << other.feet << " feet, " << other.inches << " inches";
    return out;
}

std::istream& operator >>(std::istream &in, Distance &other) {
    in >> other.feet >> other.inches;
    return in;
}

int main() {
    Distance d1(10, 5.5);
    Distance d2(10, 5.5);
    Distance d3(11, 5.5);
    Distance *d5 = new Distance(10, 5.5);

    std::cout << "d1 == d2: " << (d1 == d2) << std::endl; // Should print 1 (true)
    std::cout << "d1 != d3: " << (d1 != d3) << std::endl; // Should print 1 (true)

    (std::cout << d1) << std::endl;
    Distance d4;
    std::cin >> d4;
    std::cout << "You entered: " << d4 << std::endl;


    Distance d6 = d1;
    Distance d7(d2);
}