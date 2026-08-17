#include<iostream>
using namespace std;
//
class Item
{
    private:
        string item_code;

    protected:
        double actual_cost;
    
    public :
        string name ;
        int qty;
        double saleprice;
};
class Pen : public Item
{

        public: 
            void displayPen()
            { }
};

//Protected Inheritance 
//When deriving from a protected base class, public and protected members of the base class become 
//protected members of the derived class. 

class NoteBook : protected Item{
     public: 
            void displayNoteBook()
            {   
                    actual_cost = 22;
                 name = "notebook one";
                cout << name << endl;}
};
//Private Inheritance 
//When deriving from a private base class, public and protected members of the base class
// become private members of the derived class. 
class Pencil : private Item{

      public: 
            void displayPencil()
            {  // item_code = 22;
                actual_cost = 22;
                name = "Pencil one";
                cout << name << endl;}
};
//check access levels here
class ColorPencil : public Pencil
{
    public:
      void displayColorPencil()
            { 
                item_code = 22;
                actual_cost = 22;
                name = "Pencil one";
                cout << name << endl;
            }

};
int main()
{
    Pen p1;
    NoteBook n1;
    p1.name = "Aasdasd";
    // p1.item_code; //not accessible here
    // p1.actual_cost; //not accessible here

    //n1.name = "SAdbiasdi"; //not accessible here
    //n1.actual_cost;    // not accessible here
    Pencil pencil;
    //pencil.name = "ab";
    return 0;
}
