#include <iostream>
#include <cstring>

class MyString {
    private:
        char* data;
    public:
        // Constructor
        MyString(const char* str = "") {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }

        // Destructor
        ~MyString() {
            delete[] data;
        }

        // Copy Constructor
        MyString(const MyString &other) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }

        // Copy Assignment Operator
        MyString& operator =(const MyString &other) {
            if (this == &other) {
                return *this; // handle self-assignment
            }
            delete[] data; // free existing resource

            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
            return *this;
        }

        void print() const {
            std::cout << data << std::endl;
        }
};

int main() {
    int *arr = new int[10]; // dynamically allocated array
    MyString str1("Hello, World!");
    MyString str2 = str1; // Calls copy constructor
    MyString str3;
    MyString *str4 = new MyString("Temporary");
    str3 = str1; // Calls copy assignment operator

    str1.print();
    str2.print();
    str3.print();
    // str4->print();
    std::cout << str4 << std::endl;
    str4->print();
    return 0;
}