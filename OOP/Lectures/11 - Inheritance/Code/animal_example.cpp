#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void speak() const{ //virtual functions allows us polymorphic behavior
        cout << "Some generic animal sound" <<endl;
    }
};


class Dog: public Animal{
    public:
    void speak() const override{ //virtual functions allows us polymorphic behavior
        cout << "Woof Woof!" <<endl;
    }

    void hello(){
        cout <<"Hello, I say woof woof"<<endl;
    }
};

class Cat: public Animal{
    private:
    // double arr[3];
    public:
    void speak() const override{ //virtual functions allows us polymorphic behavior
        cout << "Meow Meow!" <<endl;
    }
};


int main(){

    Animal* zoo[2];

    // Animal* a = &Dog();
    // Animal zoo[2];
    zoo[0] = new Animal();
    zoo[1] = new Dog();
    zoo[2] = new Cat();

    // zoo[1] -> hello();

    // static_cast<Dog*>(zoo[1])->hello();

    // static_cast<double>(a)

    // zoo[0] =  Animal();
    // zoo[1] =  Dog();
    // zoo[2] =  Cat();


    for (int i=0; i<3; i++){
        zoo[i]-> speak();
    }

    // Clean up
    for (int i=0; i<3; i++){
        delete zoo[i];
    }

}