 #include<iostream>
using namespace std;
//Animal is an abstract class - it has atleast one pure virtual function
 class Animal {
 public :
        Animal() {cout << "Animal Created\n";}
      // virtual void sound () { cout << " Some sound " << endl ; }


      //pure virtual sound() method
      virtual void sound() = 0; // pure virtual
      virtual void eat()
      {
        cout << "Animal is eating\n";
      }

      virtual  ~Animal() { cout <<"Animal Destroyed\n";}

 };

 class Dog : public Animal {
 public :
 void sound ()  { cout << " Woof !" << endl ; }
 
 
   Dog() { cout << "Dog Created\n";}
   ~Dog() { cout << "Dog Destroyed\n";}
 };

 

 class Cat : public Animal {
 public :
  
   Cat() {cout << "Cat Created\n";}
   ~Cat() { cout << "Cat Destroyed\n";}
 void sound ()  { cout << " Meow !" << endl ; }
 };
 class Persian: public Cat
 {
  public :
   Persian() {cout << "Persian Created\n";}
   ~Persian() { cout << "Persian Destroyed\n";}
// void sound ()  { cout << "Persian Meow !" << endl ; }
 };

 


int main () {
//         // on main_stack
//         Dog d1 ;
//        // d1.sound();  // some sound
//         //heap
      //   Dog* d = new Dog(); 
      // d->sound(); // somesound
        
//         Cat* c = new Cat();
     //   c->sound();  // Meow !
//Dog d ;
       // Animal animal;
        // Animal * a1 = new Dog () ; // ctor
        // Animal * a2 = new Cat () ;
     
        // a1 -> sound () ; 
        // a2 -> sound () ; 
       
        //   delete a1 ; //dtor 
        //   delete a2;
        //runtime polymosrphism
        // runtime binding

    // creating Animal cart that has 5 animal references
          Animal** an = new Animal*[5];
          an[0] = new Cat();
          an[1] = new Dog();
          an[2] = new Dog();
          an[3] = new Persian();
          an[4] = new Dog();

          for (int i =0 ; i < 5 ; i++)
              an[i]->sound();

          for (int i =0 ; i < 5 ; i++)
          {
            delete an[i];
            an[i] = nullptr;}
          

          delete[] an;
          an = nullptr;

          Cat* p = new Persian();
          delete p;

        return 0;

 }