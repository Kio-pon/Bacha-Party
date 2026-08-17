// we have not studied linked list data structures yet, we are practising a Node class

#include <iostream>
using namespace std;


class Node{

public:
    int data; 
    Node* next;

    Node(){
        data =0;
        next=nullptr;
    }

    Node(int val){

        data = val;
        next = nullptr;
    }
};

int main(){
// Create nodes using parametrized constructors

// use a dynamic way of defining a node or use the new operator

//  x = new int a[10]

// initialized three nodes
Node* head  = new Node(10);

// int *p = &x
// Node* head = new Node(10);

Node* second  = new Node(20);
Node* third  = new Node(30); 


cout << head << endl;
cout << second << endl;
cout << third << endl;


// connecting these nodes
head-> next = second;
second-> next = third;



// head.next = second;

// new thing returns the address of the Node class with the initialized value 10 -> cout << head << 0x1000 

// head, second and third would have memory locations


// traverse these nodes

//This just copies the pointer (address). Both head and temp point to the same Node.
Node* temp = head;

cout << "value of temp " <<temp <<endl;
cout << "value of head " <<head <<endl;

// temp is storing the address of the Node class


// good example of a copy contructor
// we don't have to write a custom copy constructor

// Node head(10);       // create a Node object
// Node temp = head;    // ✅ calls the copy constructor

// traverse a linked list
while (temp != nullptr){
    // 1st iteration 10 -> 20 -> 30 -> NULL
    cout << temp->data << "->";
    // temp is going to have 0x746d40, 0x746f80
    temp = temp->next;
}

// while (head != nullptr){
//     // 1st iteration 10 -> 20 -> 30 -> NULL
//     cout << head->data << "->";
//     // temp is going to have 0x746d40, 0x746f80
//     head = head->next;
// }

// the print answer would be exactly similar
// why do we need a temp pointer
//


cout << "NULL" <<endl;

return 0;


}