// Design a program for Classroom with Students and Courses

// Each Student has a name and an age.
// A student can enroll in multiple Courses.

// But since the number of courses isn’t fixed at compile time, we must use a dynamic array of pointers to courses.

// We will use double pointers, why?

// Each Course* holds the memory address of a list of courses // pointer to the address of each courses
// We need a double pointer to hold the starting address of the Course  // pointer to array of Course*

// Students can:
        // Enroll in a course (addCourse)
        // List all their enrolled courses (listCourses)


#include <iostream>
using namespace std;

// courses[Max_Courses][Max_Students]; // Fixed sized array

// Max_courses = 10, Max_Students = 100

// courses[i][j] represents the jth student enrolled in the ith course

// Can't modify the sizes if they are defined at compile time

//  Course ** holds a pointer to an array of rows 
//  Course * holds a pointer to each individual course i.e. &math, &physics

// Home excercise: Can you make a 2D block diagram of this problem just like slide 45 and 47 of the pointer slide-deck?


// 1. Let's define two classes one for Course and one for Student

// Define Course Class here

class Course {
private:
// store the title and credits

public:

string title;
int credits;
// Constructor that is used to initialize the values in the class
Course(const string & t, int c){
        title = t;
        credits = c;
}

void showInfo(){
        cout << title << "{" << credits << "credits" <<endl;
}

};

class Student {

private:
// 4 variables
string name;
int age;
int course_count;
Course ** courses; // dynamic array of pointers to a Course pointer array

//Course ** is a list of addresses (each pointing to a course)

//courses[0] -> &math 
// courses [1] -> &physics
// Course * course; // storing the address of a single course



public:
// Contructor

Student (const string &n, int a){
        name = n;
        age= a;
        courses = nullptr;
        course_count = 0;
}

// Add a course to our courses array

// Course* c = “a single pointer storing the address of one course” (e.g., Physics).

// Course** courses = “a double pointer pointing to the array of addresses”

// Student.courses (Course**) →  [ Course* , Course* , Course* ]
//                                  ↓         ↓         ↓
//                                 &Math     &Physics   &CS

void addCourse (Course *c){

        // Each time a course is address, we allocate a new dynamic array of pointers (Course *)
        // It's size is bigger than before (course_count +1)
        // Copy all the old pointers to this new array and then append the new course
        // After copy the address to this new memory location, we basically delete the old pointer locations

        Course ** newArr = new Course * [course_count+1];

        // Now let's copt the course addresses to this new array

        for(int i =0; i< course_count; i++){
                newArr[i] = courses[i];
        }



        // IMPORTANT! Here we are storing the address of the new course i.e. &Math, &Physics, &CS etc. 

        newArr[course_count] = c;

        if (course_count ==0) {

        cout << "Student name " << name << "Address 0 of new Arr " << newArr[0] <<endl;
        cout << "Student name " << name << "Incoming course address " << c <<endl;
        cout << "Student name" <<name << "title of the incoming course " << (*newArr[0]).title <<endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<endl;
        }

        else if (course_count ==1){
        
        cout << "Student name " << name << "Address 0 of new Arr " << newArr[0] <<endl;
        cout << "Student name " << name << "Incoming course address " << c <<endl;
        cout << "Student name" <<name << "title of the incoming course " << (*newArr[0]).title <<endl;
        cout << "================================================" <<endl;

        
        cout << "Student name " << name << "Address 1 of new Arr " << newArr[1] <<endl;
        cout << "Student name " << name << "Incoming course address " << c <<endl;
        cout << "Student name" <<name << "title of the incoming course " << (*newArr[1]).title <<endl;
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" <<endl;
        }



        delete [] courses;
        courses = newArr;

        // also increment counter

        course_count++;


}

void listCourses(){

        cout << name <<" is enrolled in: " << endl;

        if (course_count ==0){
                cout << "No courses yet" <<endl;
                return;
        }
        for (int i=0; i<course_count; i++){
                cout << " - ";
                courses[i] -> showInfo();

                // it's going to be equivalent to courses[i].showInfo()
        }
}

};

// Define Course Student Classs here


// Define Main Function here

int main(){
// Create some course

Course math ("Matematics", 3);
Course physics ("Physics", 4);
Course CS ("CS", 5);

// Create some students through our student class

Student s1("Ali", 20);
Student s2("Joe", 21);


// enroll course function or add courses to each student
s1.addCourse(&math);
s1.addCourse(&physics);
s1.addCourse(&CS);
s2.addCourse(&physics);


s1.listCourses();
cout << endl;
s2.listCourses();

return 0;
}