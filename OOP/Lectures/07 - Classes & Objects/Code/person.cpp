#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------
// Base Class: person (Abstract Class)
//------------------------------------------------------
class person {
protected:
    string name;
public:
    void getName() {
        cout << "Enter name: ";
        cin >> name;
    }

    void putName() const {
        cout << "Name is: " << name << endl;
    }

    // Pure virtual functions (no definition here)
    virtual void getData() = 0;
    virtual bool isOutstanding() const = 0;
};

//------------------------------------------------------
// Derived Class 1: student
//------------------------------------------------------
class student : public person {
private:
    float gpa;
public:
    void getData() override {
        getName();
        cout << "Enter student's GPA: ";
        cin >> gpa;
    }

    bool isOutstanding() const override {
        return (gpa > 3.5);
    }
};

//------------------------------------------------------
// Derived Class 2: professor
//------------------------------------------------------
class professor : public person {
private:
    int numPubs;
public:
    void getData() override {
        getName();
        cout << "Enter number of professor's publications: ";
        cin >> numPubs;
    }

    bool isOutstanding() const override {
        return (numPubs > 10);
    }
};

//------------------------------------------------------
// Main Program
//------------------------------------------------------
int main() {
    person* persPtr[100];  // array of base class pointers
    int n = 0;
    char choice;

    do {
        cout << "Enter student or professor (s/p): ";
        cin >> choice;

        if (choice == 's')
            persPtr[n] = new student;
        else
            persPtr[n] = new professor;

        persPtr[n++]->getData();

        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\n--- Results ---\n";
    for (int j = 0; j < n; j++) {
        persPtr[j]->putName();
        if (persPtr[j]->isOutstanding())
            cout << "This person is outstanding.\n";
        delete persPtr[j];
    }

    return 0;
}


