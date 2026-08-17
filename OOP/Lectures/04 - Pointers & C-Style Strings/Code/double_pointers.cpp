#include <iostream>
using namespace std;

struct Person{
    string name;
    int age;

    /*
        In the beginning, we might store just one friend:
            Person* bestie;

        But people can have multiple friends. One naive way:
            Person* friend1;
            Person* friend2;
            Person* friend3;  // ... ugly and inflexible

        A better way is to use an array of pointers:
            Person* friends[n];

        Problem: we usually don’t know 'n' at compile time.

        Solution: make 'friends' a pointer to dynamically allocated memory.
        If we want 'friends' to be an array of Person*, then its type is:
            Person** friends;

        Key idea:
        - Person*   → pointer to one Person
        - Person**  → pointer to (one or more) Person*

        In this case, 'friends' will point to a block of Person*,
        i.e. an array of pointers to Person objects.

        Important: Person** does NOT always mean pointer to "array of pointers".
        It only means "pointer to Person*". Whether that pointer is part
        of an array, or just a single pointer variable, depends on how we use it. 
        See example 1 in main for a case where you can see this.
    */
    int friend_count = 0;
    Person** friends;

    void construct(const string& name, const int age);
    void addFriend(Person* Friend);
    void listFriends();
};

// a soft introduction to constructors
void Person::construct(const string& name, int age){
    this->name = name;
    this->age = age;
    this->friends = nullptr;
}

void Person::addFriend(Person* newFriend) {
    // allocate new array with +1 size
    Person** newArr = new Person*[friend_count + 1];

    // copy existing friends
    for (int i = 0; i < friend_count; i++) {
        newArr[i] = friends[i];
    }

    // add the new one
    newArr[friend_count] = newFriend;

    // free old array
    delete[] friends;

    // update pointer + count
    friends = newArr;
    friend_count++;
}

void Person::listFriends(){
    for(int i = 0; i < this->friend_count; i++){
        cout << friends[i]->name << endl;
    }
}

int main(){
    int arr[][3] = {1,2,3};
    cout << sizeof(arr) << endl;
    // example 1
    int x = 10;
    int *p = &x;
    int **pp = &p;  // pp points to p

    // example 2
    Person Tauqeer; Tauqeer.construct("Tauqeer", 100);
    Person Tehreem; Tehreem.construct("Tehreem", 200);
    Person Tajdar; Tajdar.construct("Tajdar", 28);
    Person Tanzeel; Tanzeel.construct("Tanzeel", 2);

    Tauqeer.addFriend(&Tehreem);
    Tauqeer.addFriend(&Tajdar);
    Tauqeer.addFriend(&Tanzeel);

    Tauqeer.listFriends();

}