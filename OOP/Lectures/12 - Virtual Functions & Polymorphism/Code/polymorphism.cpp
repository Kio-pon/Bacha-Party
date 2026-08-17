#include <iostream>
using namespace std;

// at the root of this hierarchy is Animal type
class Animal {
private:
    int age;
public:
    Animal() : age(0) {cout << "Generic Animal Constructor" << endl;}
    Animal(int a) : age(a) {cout << "Generic Animal Constructor" << endl;}

    // pure virtual function, making this an abstract class
    virtual void speak() const {};

    // this can be a non-virtual function, as we don't need to override this again and again
    void ageMe() {cout << ++age << endl;}

    // not pure virtual functions, because if we do, then we will have to define both for chichuawa and lab
    virtual void MeProtek() const {}
    virtual void EatPoopRepeat() const {};

    virtual ~Animal() {cout << "Generic Animal Destructor" << endl;}
};

// we do not override speak here, so this is also abstract
class Dog : public Animal{
private:
    int speed;
public:
    Dog() : Animal(), speed(0) {cout << "A dog has been born" << endl;}
    Dog(int a, int s) : Animal(a), speed(s) {cout << "A dog has been born" << endl;}

    ~Dog() {cout << "We regret to inform you that the dog has passed away!" << endl;}
};

class Demon{
public:
    Demon() {cout << "A demon has been born with the demon number: " << ++demonNum << endl;};
    ~Demon() {cout << "A demon has died with the demon number: " << demonNum-- << endl;};
private:
    inline static int demonNum = 0;
};

class Angel{
public:
    Angel() {cout << "An Angel has been born with the demon number: " << ++AngelNum << endl;};
    ~Angel() {cout << "An Angel has died with the demon number: " << AngelNum-- << endl;};
private:
    inline static int AngelNum = 0;
};


class Labrador : public Angel, public Dog{
private:
    string name;    
public:
    Labrador() : Dog(), Angel(), name("kutta") {cout << "A Labrador has been born" << endl;}
    Labrador(int a, int s, const string& n) : Dog(a, s), Angel(), name(n) {cout << "A Labrador has been born" << endl;}
    
    // overriding the pure virtual function, making it a non abstract class
    virtual void speak() const override {cout << "Baw Wao" << endl;} // overriding
    
    // overriding the virtual function, making possible polymorphism
    void MeProtek() const override {cout << "I play, I rest, but above all I protek" << endl;}
    
    ~Labrador() {cout << "We regret to inform you that " << name <<  " has passed away!" << endl;}
};

class Chihuahua : public Demon, public Dog{
private:
    string name;    
public:
    Chihuahua() : Dog(), Demon(), name("kutta") {cout << "A Chihuahua has been born" << endl;}
    Chihuahua(int a, int s, const string& n) : Dog(a, s), Demon(), name(n) {cout << "A Chihuahua has been born" << endl;}
    
    // overriding the pure virtual function, making it a non abstract class
    void speak() const override {cout << "wev wev" << endl;} // overriding
    
    // overriding the virtual function, making possible polymorphism
    void EatPoopRepeat() const override {cout << "I ate, I pooped, now I rest" << endl;}
    
    ~Chihuahua() {cout << "We regret to inform you that " << name <<  " has passed away!" << endl;}
};

/*
    Suppose we have an algorithm that manipulates a Vehicle object. 
    Because a car is a special kind of vehicle, we can supply a Car object to such an algorithm, and it will work correctly. 
    This is an example of the substitution principle that states that you can always use a derived-class object when a base-class object is expected. 
*/

void noise(const Animal& animal){
    animal.speak();
}

int main(){
    cout << "Check" << endl;
    Chihuahua kutta(3, 10, "maxie");
    kutta.EatPoopRepeat();
    noise(kutta);
    kutta.ageMe();

    cout << "Check 0" << endl;
    // Demo - Slicing Problem
    Labrador achaKutta(3, 10, "Mr. Brown");
    Animal x = kutta;
    Animal y = achaKutta;
    Animal arr1[]{kutta, achaKutta};

    cout << "Check 1" << endl;
    arr1[0].speak(); //<- sliced

    // Solution - Use Pointers
    Animal* ptr1 = &kutta;
    Animal* ptr2 = &achaKutta;
    Animal* arr2[]{ptr1, ptr2};
    
    cout << "Check 2" << endl;
    arr2[0]->speak();

    cout << "Check 3" << endl;
    // What if I want more?
    arr2[1]->MeProtek(); // dynamically dispatched to Chihuahua::EatPoopRepeat()

    Animal* ptr = new Chihuahua();
    ptr->EatPoopRepeat();   // dynamically dispatched to Chihuahua::EatPoopRepeat()


    return 0;
}