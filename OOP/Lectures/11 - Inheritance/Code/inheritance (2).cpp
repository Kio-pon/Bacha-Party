#include <iostream>
using namespace std;

// at the root of this hierarchy is Animal type
class Animal{
private:
    int age;
public:
    Animal() : age(0) {cout << "Generic Animal Constructor" << endl;}
    Animal(int a) : age(a) {cout << "Generic Animal Constructor" << endl;}
    void speak() const {cout << "Generic Animal Voice" << endl;}
    void ageMe() {cout << ++age << endl;}
    ~Animal() {cout << "Generic Animal Destructor" << endl;}
};

class Dog : public Animal{
private:
    int speed;
public:
    Dog() : Animal(), speed(0) {cout << "A dog has been born" << endl;}
    Dog(int a, int s) : Animal(a), speed(s) {cout << "A dog has been born" << endl;}
    void speak() const {cout << "Woff Woff" << endl;} // overriding
    ~Dog() {cout << "We regret to inform you that the dog has passed away!" << endl;}
};

class Demon{
public:
    Demon() {cout << "A demon has been born with the demon number: " << ++demonNum << endl;};
    ~Demon() {cout << "A demon has died with the demon number: " << demonNum-- << endl;};
private:
    //inline static int demonNum = 0;
    static int demonNum;
};


int Demon::demonNum = 1;

class Chihuahua : public Demon, public Dog{
private:
    string name;    
public:
    Chihuahua() : Dog(), Demon(), name("kutta") {cout << "A Chihuahua has been born" << endl;}
    Chihuahua(int a, int s, const string& n) : Dog(a, s), name(n) {cout << "A Chihuahua has been born" << endl;}
    void speak() const {cout << "wev wev" << endl;} // overriding
    void EatPoopRepeat() const {cout << "I ate, I pooped, now I rest" << endl;}
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
    Chihuahua kutta(3, 10, "maxie");
    kutta.EatPoopRepeat();
    noise(kutta);
    kutta.ageMe();
    return 0;
}