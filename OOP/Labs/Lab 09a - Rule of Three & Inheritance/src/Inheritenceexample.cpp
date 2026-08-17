#include <iostream>
using namespace std;
class Animal {
public:
    virtual void sound() { cout << "Some sound" << endl; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Woof!" << endl; }
};

class Cat : public Animal {
public:
    void sound() override { cout << "Meow!" << endl; }
};


int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    a1->sound(); // Woof!
    a2->sound(); // Meow!
}
