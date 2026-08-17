#include <iostream>
using namespace std;

class Time {
public:
    Time() : hours(0), minutes(0) {}
    Time(int h, int m) : hours(h), minutes(m) {}

    int get_hours() const { return hours; }
    int get_minutes() const { return minutes; }

    void display() const {
        cout << hours << "h " << minutes << "m" << endl;
    }

private:
    int hours;
    int minutes;
};

// -------- Operator Overloads --------

// Add two Times → return new Time
Time operator+(Time a, Time b) {
    int h = a.get_hours() + b.get_hours();
    int m = a.get_minutes() + b.get_minutes();

    if (m >= 60) {       // simple normalization
        h += m / 60;
        m = m % 60;
    }

    return Time(h, m);
}

// Difference between two Times in minutes
int operator-(Time a, Time b) {
    return (a.get_hours() * 60 + a.get_minutes()) -
           (b.get_hours() * 60 + b.get_minutes());
}

// Equality
bool operator==(Time a, Time b) {
    return (a - b) == 0;
}

// Inequality
bool operator!=(Time a, Time b) {
    return !(a == b);
}

// Less than
bool operator<(Time a, Time b) {
    return (a - b) < 0;
}

// Greater than
bool operator>(Time a, Time b) {
    return (a - b) > 0;
}

// Less than or equal
bool operator<=(Time a, Time b) {
    return (a - b) <= 0;
}

// Greater than or equal
bool operator>=(Time a, Time b) {
    return (a - b) >= 0;
}

// -------- Demo --------
int main() {
    Time t1(2, 50);
    Time t2(1, 30);
    Time t3(2, 50);

    cout << "t1: "; t1.display();
    cout << "t2: "; t2.display();
    cout << "t3: "; t3.display();

    // Addition
    Time sum = t1 + t2;
    cout << "t1 + t2 = "; sum.display();

    // Difference in minutes
    cout << "t1 - t2 = " << (t1 - t2) << " minutes" << endl;

    // Comparisons
    cout << "t1 == t2? " << (t1 == t2) << endl;
    cout << "t1 == t3? " << (t1 == t3) << endl;
    cout << "t1 != t2? " << (t1 != t2) << endl;
    cout << "t1 <  t2? " << (t1 < t2)  << endl;
    cout << "t1 >  t2? " << (t1 > t2)  << endl;
    cout << "t1 <= t3? " << (t1 <= t3) << endl;
    cout << "t1 >= t2? " << (t1 >= t2) << endl;

    return 0;
}




