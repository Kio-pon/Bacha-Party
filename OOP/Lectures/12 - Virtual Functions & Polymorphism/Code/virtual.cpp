 #include<iostream>
using namespace std;
 class Animal {
 public :
  virtual void sound () { cout << " Some sound " << endl ; }
 };

 class Dog : public Animal {
 public :
 //void sound ()  { cout << " Woof !" << endl ; }
 };
 

 class Cat : public Animal {
 public :
 void sound ()  { cout << " Meow !" << endl ; }
 };


int main () {
        Dog* d = new Dog();
        

        Animal * a1 = new Dog () ;
        Animal * a2 = new Cat () ;
        d-> sound();
        a1 -> sound () ; // Woof !
        a2 -> sound () ; // Meow !
 }