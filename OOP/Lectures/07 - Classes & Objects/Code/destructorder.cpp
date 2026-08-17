#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called." << std::endl;
    }
    ~Base() {
        std::cout << "Base destructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor called." << std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor called." << std::endl;
    }
};

int main() {
    Derived d; // Creating an object of Derived class
    return 0;
}
