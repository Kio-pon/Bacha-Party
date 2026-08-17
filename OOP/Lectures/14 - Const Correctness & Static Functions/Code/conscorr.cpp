// const_examples_class.cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name_;
    int age_;

public:
    Person(std::string name = "<no-name>", int age = 0)
    : name_(name), age_(age) {}

    // const-qualified accessor (callable on const objects/pointers/references)
    void print() const {
        std::cout << "Person{name=\"" << name_ << "\", age=" << age_ << "}\n";
    }

    // non-const modifier (not callable on const objects/pointers/references)
    void setAge(int a) {
        age_ = a;
    }

    // non-const modifier for name
    void setName(const std::string &n) {
        name_ = n;
    }

    // const-qualified getter
    int age() const { return age_; }
    const std::string &name() const { return name_; }
};

int main() {
    std::cout << "=== const / pointer / reference examples with class Person ===\n\n";
    
    // --- 1) const X* p  (aka X const * p) : pointer to const X ---
    {
        std::cout << "1) const Person* p  (pointer to const Person)\n";
        Person a{"Alice", 30};
        Person b{"Bob", 40};

        const Person* p = &a; // *p is const through this pointer
        p->print();

        //p->setAge(99); // ERROR if uncommented: cannot call non-const member through pointer-to-const

        // The pointer itself is not const: you can make it point elsewhere
        p = &b; // OK
        p->print();

        std::cout << "-> You cannot call non-const methods through 'const Person* p', but you may reassign p.\n\n";
    }
    /*
    // --- 2) Person* const p : const pointer to Person (pointer itself is const) ---
    {
        std::cout << "2) Person* const p  (const pointer to Person)\n";
        Person a{"Amy", 25};
        Person b{"Ben", 35};

        Person* const p = &a; // p is a const pointer: p cannot be changed to point elsewhere
        p->print();

        // But the pointed-to object is modifiable through p:
        p->setAge(26); // OK
        p->print();

        // p = &b; // ERROR if uncommented: p is const (cannot reassign the pointer itself)

        std::cout << "-> You can call non-const methods to modify the object, but you can't change p to point somewhere else.\n\n";
    }
    /*
    // --- 3) const Person* const p : const pointer to const Person ---
    {
        std::cout << "3) const Person* const p  (const pointer to const Person)\n";
        Person a{"Ann", 20};

        const Person* const p = &a; // neither p nor *p can be changed via this name
        p->print();

        // p = nullptr;   // ERROR if uncommented: pointer is const
        // p->setAge(21); // ERROR if uncommented: pointed-to is const (cannot call non-const members)

        std::cout << "-> Neither the pointer nor the pointee may be modified via 'const Person* const p'.\n\n";
    }

    // --- 4) const Person& r  (reference to const Person) ---
    {
        std::cout << "4) const Person& r  (reference to const Person)\n";
        Person a{"Arif", 50};

        const Person& r = a; // r is a read-only alias to a
        r.print();

        // r.setAge(51); // ERROR if uncommented: cannot call non-const member on reference-to-const

        // Reference-to-const can bind to temporaries (rvalues):
        const Person& rtemp = Person{"Temp", -1}; // binds to temporary
        rtemp.print();

        std::cout << "-> 'const Person&' is read-only and can bind to temporaries.\n\n";
    }

    // --- 5) Person const& r  and  Person const* p  (alternate placement of 'const') ---
    {
        std::cout << "5) Person const& r  and  Person const* p  (alternate placement of 'const')\n";
        Person a{"Zara", 28};
        Person b{"Yasir", 33};

        // identical to 'const Person&' and 'const Person*'
        Person const& ref = a;
        ref.print();
        // ref.setAge(29); // ERROR if uncommented

        Person const* pp = &b;
        pp->print();
        // pp->setAge(34); // ERROR if uncommented

        std::cout << "-> 'Person const&' and 'const Person&' are identical; same for pointer forms.\n\n";
    }

    // --- 6) Does 'Person& const r' make sense? ---
    {
        std::cout << "6) Does 'Person& const r' make sense?\n";
        std::cout << "-> No. A reference itself cannot be made const; references are aliases and must be initialized.\n";
        std::cout << "   'Person& const r = something;' is ill-formed and will not compile.\n\n";

        // Example (commented out - won't compile):
        // Person a{"No", 0};
        // Person& const bad = a; // ERROR: invalid declaration of reference 'bad' with const qualifier
    }
    */
    std::cout << "=== End of examples ===\n";
    return 0;
}
