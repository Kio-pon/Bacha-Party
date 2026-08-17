// Design a program for Classroom with Students and Courses

// Each Student has a name and an age.
// A student can enroll in multiple Courses.

// But since the number of courses isn’t fixed at compile time, //we must use a dynamic array of pointers to courses.

// Students can:
        // Enroll in a course (addCourse)
        // List all their enrolled courses (listCourses)


#include <iostream>
using namespace std;

class Course {
private:
    string title;
    int credits;

public:
    // Constructor (Note that here we use pass by reference)
    Course(const string& t, int c) {
        title = t;
        credits = c;
    }

    void showInfo() {
        cout << title << " (" << credits << " credits)" << endl;
    }
};

class Student {

private:
    // 4 variables
    string name;
    int age;
    int course_count;
    Course** courses;   // dynamic array of pointers to Course

    // Course** → a list of address cards (each pointing to a course).
    // courses[0] = &math;
    // courses[1] = &physics;

public:
    // Constructor
    Student(const string& n, int a) {
        name = n;
        age = a;
        courses = nullptr;
        course_count = 0;
    }

    void addCourse(Course* c) {
        
        // Each time a new course is added, we allocate a new dynamic array of pointers (Course*).
        // Its size is one bigger than before (course_count + 1).
        // Then we copy all old pointers into this new array, and append the new one.
        // After copying over addresses, the old array of pointers is freed with delete[].

        // Remember this from double pointers
        Course** newArr = new Course*[course_count + 1];
        // Remember double pointer holds a list of address (each pointing to a different course).
        
        // Now let's copy the course addresses to new array
        for (int i = 0; i < course_count; i++) {
            newArr[i] = courses[i];
        }

        // add our new course address to the final location
        newArr[course_count] = c;

        // delete the previous address information
        delete[] courses;

        // update the courses to new array
        courses = newArr;

        // also increment counter
        course_count++;
    }

    void listCourses() {
        cout << name << " is enrolled in:" << endl;
        if (course_count == 0) {
            cout << " (no courses yet)" << endl;
            return;
        }
        for (int i = 0; i < course_count; i++) {
            cout << " - ";
            
            //  We will learn this in next class.
            // . (dot) → used when you have an object.
            // -> (arrow) → used when you have a pointer to an object.

            courses[i]->showInfo();
        }
    }

    // Destructor to clean up memory
    ~Student() {
        delete[] courses;
    }
};

int main() {
    // Step 1: Create some courses
    Course math("Mathematics", 3);
    Course physics("Physics", 4);
    Course cs("Computer Science", 5);

    // Step 2: Create students
    Student s1("Ali", 20);
    Student s2("Joe", 21);

    // Step 3: Enroll courses
    s1.addCourse(&math);
    s1.addCourse(&cs);
    s2.addCourse(&physics);

    // Step 4: List enrolled courses
    s1.listCourses();
    cout << endl;
    s2.listCourses();

    return 0;
}
