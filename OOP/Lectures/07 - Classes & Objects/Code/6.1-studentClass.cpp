#include <iostream>
using namespace std;
     
class Student
{  
   private :
         string ID;
         float grade = 90.0;
         string cnic="N/A";
         //setter function for grade
         void setGrade()
         {
               //read all gardes from graded elements(hw1, hw2 , cQ1, cQ2, mid , final)
               //sum of all grade

         }

   public:
         // //constructor
         Student()
         {
            cout << "New student added\n";
         } 
         Student(string c)
         {
            cnic = c;
            cout << "New student added with CNIC no : " << c <<"\n";
         } 
      //properties/attributes/data members
     
      string fname , lname , address;
      int age;

      //function members /actions/methods
      void viewGrade()
      {
         cout << "Your grade : " << grade << endl;
      }
      void editProfile()
      {
         cout << "Your fname : " << fname;
         cin >> fname;
           cout << "Your lname : " << lname;
         cin >> lname;
           cout << "Your address : " << address;
         cin >> address;

      }
       void viewProfile()
      {
         cout << "\nYour CNIC :" << cnic;
         cout << "\nYour fname : " << fname;
         cout << "\nYour lname : " << lname;
         cout << "\nYour address : " << address;
         cout << "\nYour garde : " << grade;
      }
};


void showAllStudents(Student* stds)
{
   for(int i =0;i<5;i++)
         stds[i].viewProfile();
}
 int main ()
 {
   //private member--> getters / setters 
   // garde -- > getter (public function) --> viewGrade()

   Student s1("1234") , s2("565") ,s3;
//    s1.grade =88;
//    s1.age = 20;
//    s1.fname = "Ahmed";
//    s1.lname = "Mujtaba";
//    s2.fname = "Azyan";
//    s2.lname = "Ahmed";
//    s1.viewGrade(); // getter function 80for grade prpoperty which was private

//   // s1.editProfile();
//    s1.viewProfile();
//    s2.viewProfile();
//    s1.viewGrade();
//    s1.viewProfile();


   //creating a list of students
   Student allStd[5];
   allStd[0] = s1;
   allStd[1] = s2;

   //view all students (but this is not a member function of Student class)
   //student objects will not perform this action.
   showAllStudents(allStd);

   
   
    return 0 ;
 }




