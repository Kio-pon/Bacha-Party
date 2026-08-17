#include <iostream>
#include <cstring>
 
class MyString {
private:
    char* data;  
 
public:
    // Constructor
    MyString(const char* str = "") {
        data = new char[strlen(str)+1];  
        strcpy(data, str);                 
    }
    // Destructor
    ~MyString() {
        delete[] data;  
    }

    /* Now commenting the copy constructor and the copy assignment operator */

    /*
    // Copy Constructor
    MyString(const MyString& other) {
        data = new char[strlen(other.data)+1];  
        strcpy(data, other.data); 
    }

    // Copy Assignment Operator
    MyString& operator=(const MyString& other) {
        if (this == &other) 
            return *this;  
        delete[] data;
 
        data = new char[strlen(other.data)+1];
        strcpy(data, other.data);
        return *this;
    }
    */

    void prt() const {
        std::cout << data << std::endl;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2 = str1; //copy constructor
    MyString str3;
    str3 = str1;  //copy assignment operator
    str1.prt();  
    str1.~MyString();
    str2.prt(); str3.prt();  
    //Output: Hello 
    return 0;
}

