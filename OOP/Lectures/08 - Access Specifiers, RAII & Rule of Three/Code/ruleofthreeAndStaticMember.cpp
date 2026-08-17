#include<iostream>

using namespace std;

//static data member
class A
{   
    //keep it private so that objects can not change the value of Acount.
    // for class level access : make static getters and setters 
    static int Acount;
 
    public:
       
           int count = 0 ;
        int age;
        int CNIC;
        int *p;
       // void show();
       //Rule of 3:
       //==============
       //default dtor
       ~A()
       {
          delete[] p;

       }
        //defalut ctor
       A()
       {
            Acount++;
            age = 20;
            count++;
            CNIC = rand();
            p = new int[3]{21,35,42};
       }
       // defalut copy constrcutor 
       A(A& obj_A)
       {
            Acount++;
            age = obj_A.age;
            CNIC = rand();
            p = new int[3];
            //copy each element 
            for (int i = 0 ; i<3; i++)
               this->p[i] = obj_A.p[i];

       }
       // default copy assignment operator
       void operator= (A& obj_new)
       {
        age = obj_new.age;
        Acount++;
      
            //copy each element 
            for (int i = 0 ; i<3; i++)
               this->p[i] = obj_new.p[i];



       }
       //static getter function for static data member 
      static int  get_Acount()
       {
        return Acount;
       }
     
};
int A::Acount = 0;
int main()
{

    A obj , r; // default ctor
    r.age = 40;
    obj.age = 20;

    double num  = 3.4;
    double x = num;
    A p = obj; // defalut copy constrcutor // --> A p(obj); age =20 , CNIC = obj.cnic
    r = obj; // default copy asignment operator

    cout << "Total object of clas A: " << A::get_Acount();
     cout << "Total object of clas A: " << p.get_Acount();





    return 0;
}